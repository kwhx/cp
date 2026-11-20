#include <array>
#include <cstddef>
#include <cstdint>
#include <cstdio>
#include <new>
#include <type_traits>
#include <utility>
typedef std::uint8_t  __u8;
typedef std::uint32_t __u32;
typedef std::uint64_t __u64;

#define __force_inline inline __attribute__((always_inline))
#define __noinline     __attribute__((noinline))
#define unlikely(__x)  __builtin_expect(!!(__x), 0)
#define container_of(__p, __T, __m) \
	((__T *)((char *)(__p) - __builtin_offsetof(__T, __m)))
#define list_for_each(__pos, __h) \
	for ((__pos) = (__h)->next; (__pos) != (__h); (__pos) = (__pos)->next)

struct list_head { list_head *next, *prev; };

static __force_inline void INIT_LIST_HEAD(list_head *__h) { __h->next = __h->prev = __h; }
static __force_inline void __list_add(list_head *__n, list_head *__p, list_head *__x)
{ __x->prev = __n; __n->next = __x; __n->prev = __p; __p->next = __n; }
static __force_inline void list_add_tail(list_head *__n, list_head *__h)
{ __list_add(__n, __h->prev, __h); }

template <__u64 __N> struct ct_fib
        : std::integral_constant<__u64, ct_fib<__N - 1>::value + ct_fib<__N - 2>::value> {};
template <> struct ct_fib<0> : std::integral_constant<__u64, 0> {};
template <> struct ct_fib<1> : std::integral_constant<__u64, 1> {};

template <std::size_t __N> constexpr auto __ct_sieve()
{
    std::array<bool, __N + 1> __s{};
    for (std::size_t __i = 2; __i <= __N; ++__i) __s[__i] = true;
    for (std::size_t __i = 2; __i * __i <= __N; ++__i)
        if (__s[__i])
            for (std::size_t __j = __i * __i; __j <= __N; __j += __i) __s[__j] = false;
    return __s;
}
template <std::size_t __N> constexpr std::size_t __ct_pi()
{
    constexpr auto __s = __ct_sieve<__N>();
    std::size_t __c = 0;
    for (bool __b : __s) __c += __b;
    return __c;
}
template <class... __T> constexpr __u64 __fnv(__T... __v)
{
__u64 __h = 1469598103934665603ULL;
((__h = (__h ^ (__u64)__v) * 1099511628211ULL), ...);
return __h;
}
static_assert(ct_fib<20>::value == 6765, "fib");
static_assert(__ct_pi<1000>() == 168, "pi(1000)");

template <class __T, std::size_t __N> struct kmem_cache {
    alignas(__T) unsigned char __slab[__N][sizeof(__T)];
    std::size_t __nr_free = 0;
    __T *alloc() { return unlikely(__nr_free == __N) ? nullptr : ::new (&__slab[__nr_free++]) __T(); }
};

enum { OP_MOVI, OP_ADD, OP_XCHG, OP_DEC, OP_JNZ, OP_HLT, OP_MAX };

struct vm_insn {
    __u8 op, a, b;
    union { __u32 imm; list_head *tgt; };
    list_head node;
};

template <class __D> struct __tracer {
    __force_inline void __t(const char *__s) const { static_cast<const __D *>(this)->__emit(__s); }
};

struct vcpu : __tracer<vcpu> {
    __u64 __regs[4];
    list_head *__pc;
    bool __halt;
    mutable __u64 __cyc;

    void __emit(const char *) const { ++__cyc; }
    void __op_movi(const vm_insn *);
    void __op_add (const vm_insn *);
    void __op_xchg(const vm_insn *);
    void __op_dec (const vm_insn *);
    void __op_jnz (const vm_insn *);
    void __op_hlt (const vm_insn *);
};

/* pointer to an array data member of vcpu*/
constexpr __u64 (vcpu::*const __rp)[4] = &vcpu::__regs;
#define R(__i) ((this->*__rp)[(__i)])
void vcpu::__op_movi(const vm_insn *__i) { __t("movi"); R(__i->a) = __i->imm; }
void vcpu::__op_add (const vm_insn *__i) { __t("add");  R(__i->a) += R(__i->b); }
void vcpu::__op_xchg(const vm_insn *__i) { __t("xchg"); std::swap(R(__i->a), R(__i->b)); }
void vcpu::__op_dec (const vm_insn *__i) { __t("dec");  --R(__i->a); }
void vcpu::__op_jnz (const vm_insn *__i) { __t("jnz");  if (R(__i->a)) __pc = __i->tgt; }
void vcpu::__op_hlt (const vm_insn *)    { __t("hlt");  __halt = true; }

typedef void (vcpu::*__op_fn)(const vm_insn *);

/* reference-to-array-of-pointer-to-member-function, returned from a function */
static const __op_fn (&__vcpu_ops(void))[OP_MAX]
{
    static const __op_fn __t[OP_MAX] = {
            &vcpu::__op_movi, &vcpu::__op_add, &vcpu::__op_xchg,
            &vcpu::__op_dec,  &vcpu::__op_jnz, &vcpu::__op_hlt,
    };
    return __t;
}

static __noinline void __vcpu_run(vcpu *__c)
{
    while (!__c->__halt) {
        vm_insn *__i = container_of(__c->__pc, vm_insn, node);
        __c->__pc = __c->__pc->next;
        (__c->*__vcpu_ops()[__i->op])(__i);
    }
}
int main(void)
{
    static kmem_cache<vm_insn, 16> __cache;
    list_head __prog, *__pos;
    INIT_LIST_HEAD(&__prog);
    auto __e = [&](__u8 __op, __u8 __a, __u8 __b, __u32 __imm) -> vm_insn * {
        vm_insn *__i = __cache.alloc();
        __i->op = __op; __i->a = __a; __i->b = __b; __i->imm = __imm;
        list_add_tail(&__i->node, &__prog);
        return __i;
    };
    __e(OP_MOVI, 0, 0, 0);
    __e(OP_MOVI, 1, 0, 1);
    __e(OP_MOVI, 2, 0, 20);
    vm_insn *__loop = __e(OP_ADD, 0, 1, 0);
    __e(OP_XCHG, 0, 1, 0);
    __e(OP_DEC,  2, 0, 0);
    __e(OP_JNZ,  2, 0, 0)->tgt = &__loop->node;
    __e(OP_HLT,  0, 0, 0);
    std::size_t __n = 0;
    list_for_each(__pos, &__prog) { (void)container_of(__pos, vm_insn, node); ++__n; }
    vcpu __c{};
    __c.__pc = __prog.next;
    __vcpu_run(&__c);

    std::printf("insns assembled : %zu\n", __n);
    std::printf("vm  fib(20)     : %llu\n", (unsigned long long)(__c.*__rp)[0]);
    std::printf("ct  fib(20)     : %llu\n", (unsigned long long)ct_fib<20>::value);
    std::printf("ct  pi(1000)    : %zu\n", __ct_pi<1000>());
    std::printf("cycles          : %llu\n", (unsigned long long)__c.__cyc);
    std::printf("fnv(1,2,3,4)    : %016llx\n", (unsigned long long)__fnv(1, 2, 3, 4));
    return 0;
}