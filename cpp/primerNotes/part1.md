// chapter 2-8

## dt

- cpp provides builtin/primitive types (primitive types = arithmetic types + void)
- arithmetic types includes int, bool, char, float etc
- void is special and can only be used in certain circumstances, most commonly as return type when a func doesnt return a value 
- except for bool and extended character types, teh integer types can be either signed or unsigned
- signed = -ve and +ve both
- unsigned = >=0

| prefix                         |          type                  | representation | min size (in bits) | min size (in bytes) | range |
|------------- | -----------------------------------|--------------------------------| --- | --- | --- | 
|                                                | boolean                        | bool | n/a |
| u8 (when and for string literals only)         | character                      | char | 8 |
| L                                              | wide char                      | wchar_t | 16 |
| u                                              | unicode 16 char                | char16_t | 16 |
| U                                              | unicode 32 char                | char32_t | 32 |
|                                                | short int                      | short | 16 |
|                                                | integer                        | int | 16 |
|                                                | long int                       | long | 32 |
|                                                | long int                       | long long | 64 | 
|                                                | single precision floating pt   | float | | 
|                                                | double precision floating pt   | double | | 
|                                                | extended precision floating pt | long double | |

- prefixes and suffixes are used to override the default types 

| suffix | meaning |
| --- | --- |
| U | unsigned |
| L | long / long double |
| LL | long long |
| f | float |

### type conversion

- values behaves drunk when youre trying to mate unsigned with a signed or vice versa, it wraps around, need to be careful bout this and understand each scenario about this, imp for cp
- DONT MIX SIGNED AND UNSIGNED VALUES

### escape sequences

| es | ?? |
| --- | --- |
| \n | newline |
| \t | tab |
| \a | alert (bell) |
| \v | vertical tab |
| \b | backspace |
| \" | dbqt |
| \' | sgqt| 
| \\ | backslash |
| \? | quesmark |
| \r | carriage return |
| \f |formfeed |

### todo: extern keyword (context: declaration vs definition)

### cpp reserved keywords

- alignas
- alignof
- asm
- auto
- bool
- break
- case
- catch
- char
- char16_t
- char32_t
- class
- const
- constexpr
- const_cast
- continue
- decltype
- default
- delete
- do
- double
- dynamic_cast
- else
- enum
- explicit
- export
- extern
- false
- float
- for
- friend
- goto
- if
- inline
- int
- long
- mutable
- namespace
- new
- noexcept
- nullptr
- operator
- private
- protected
- public
- register
- reinterpret_cast
- return
- short
- signed
- sizeof
- static
- static_assert
- static_cast
- struct
- switch
- template
- this
- thread_local
- throw
- true
- try
- typedef
- typeid
- typename
- union
- unsigned
- using
- virtual
- void
- volatile
- wchar_t
- while

### alternative operator names

- add
- and_eq
- bitand
- bitor
- compl
- not
- not_eq
- or
- or_eq
- xor
- xor_eq

### compound types

##### references

- a reference is basically just an alias to a variable/object and nothing else
- a reference can only be bind to an object/variable and not to a literal value
- declared using ampersand

Syntax:
```cpp
int i=2;
int &r=i; //here r is a reference type, r references to i
```

##### pointers

- a pointer holds the memory address of another object or variable
- ampersand is the 'address of' operator and is used to access memaddr of a variable or object

Syntax:
```cpp
int i;
int *p=&i; //p is a pointer to store address of i
```

- a null pointer doesnt point to an object, syntax:
```cpp
int *ab= nullptr; 
```

- a void pointer can store address of an object of any type, syntax:
```cpp
double obj=3.17;
void *p=&obj; 
```