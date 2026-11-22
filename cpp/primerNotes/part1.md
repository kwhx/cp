// chapter 2-8

## dt

- cpp provides builtin/primitive types (primitive types = arithmetic types + void)
- arithmetic types includes int, bool, char, float etc
- void is special and can only be used in certain circumstances, most commonly as return type when a func doesnt return a value 
- except for bool and extended character types, teh integer types can be either signed or unsigned
- signed = -ve and +ve both
- unsigned = >=0

| prefix                         |          type                  | representation | min size (in bits) | min size (in bytes) | range                           |
|------------- | -----------------------------------|--------------------------------|--------------------|---------------------|---------------------------------| 
|                                                | boolean                        | bool | n/a                | -                   | true/false                      |
| u8 (when and for string literals only)         | character                      | char | 8                  | 1                   | -                               |
| L                                              | wide char                      | wchar_t | 16                 | 2 | -                               |
| u                                              | unicode 16 char                | char16_t | 16                 | 2 | 0 to 65,535                     |
| U                                              | unicode 32 char                | char32_t | 32                 | 4 | 0 to 4,294,967,295              |
|                                                | short int                      | short | 16                 | 2 | −32,768 to 32,767               |
|                                                | integer                        | int | 16                 | 2 | −32,768 to 32,767               |
|                                                | long int                       | long | 32                 | 4 | −2,147,483,648 to 2,147,483,647 |
|                                                | long int                       | long long | 64                 | 8 | −9.22 × 10^18 to 9.22 × 10^18   |
|                                                | single precision floating pt   | float | 32                 | 4 | Approximately ±3.4 × 10^38 |
|                                                | double precision floating pt   | double | 64                 | 8 | Approximately ±1.7 × 10^308 |
|                                                | extended precision floating pt | long double | 64                 | 8 | - |

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

| `alignas` | `alignof` | `asm` | `auto` |
|---|---|---|---|
| `bool` | `break` | `case` | `catch` |
| `char` | `char16_t` | `char32_t` | `class` |
| `const` | `constexpr` | `const_cast` | `continue` |
| `decltype` | `default` | `delete` | `do` |
| `double` | `dynamic_cast` | `else` | `enum` |
| `explicit` | `export` | `extern` | `false` |
| `float` | `for` | `friend` | `goto` |
| `if` | `inline` | `int` | `long` |
| `mutable` | `namespace` | `new` | `noexcept` |
| `nullptr` | `operator` | `private` | `protected` |
| `public` | `register` | `reinterpret_cast` | `return` |
| `short` | `signed` | `sizeof` | `static` |
| `static_assert` | `static_cast` | `struct` | `switch` |
| `template` | `this` | `thread_local` | `throw` |
| `true` | `try` | `typedef` | `typeid` |
| `typename` | `union` | `unsigned` | `using` |
| `virtual` | `void` | `volatile` | `wchar_t` |
| `while` | — | — | — |

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
Each star defines its own pointer level, as in:

```cpp
int x=1024;     // integer
int *a=&x;      // pointer to integer
int **b=&a;     // pointer to a pointer to an integer
int ***c=&b;    // pointer to a pointer to a pointer to an integer
```

- A reference isnt an object, hence we cant have a pointer to a reference. But since a pointer is an object we can have a reference to a pointer.

#### const

- a variable can be made unchangeable by  using const type (in case of values that needs to remain a constant and shallnt change). E.G:
```cpp
const int bufferSize=1024;
```

- const vars are local to files, in case we divide our program into multiple files we'll have to initialise the same const var in each file if there was any in the original single codefile. To avoid this we use 'extern' keyword. As in:
```cpp
//file_1.cpp:
extern const int buffersize=1024;

//file_1.h:
extern const int buffersize; //same buffersize as defined in file_1.cpp
```

- Top level const = int *const p
- Low level const = const int *p

#### constexpr

- a constant expression is an expression whose value cant change. It's evaluated at compile time, not at runtime.
- every const literal is a const expression if its value is initialised with definition. E.G:
```cpp
const int max=10; //max is a constant expression
int size=20; //not a constant expression since int is plain and not a const
const int sz = get(size); //sz isnt const expression since it has no initialised value at compile time
```

- If we want to use a var as a constant expression that cant be initialised at compile time, we'd need to be explicit by using the 'constexpr' term. As in:
```cpp
constexpr int sz=get(size);
```

#### Type aliases

- a type alias is simply a synonym for a type or var
```cpp
typedef double wages;
using si=sales_item;

wages monthly, weekly;
```

- it can become complex to determine the type of something or what type to choose for something, in certain programs. To resolve that we use the 'auto' keyword which lets the compiler decide the type by the kind of values being worked on. E.G:
```cpp
auto item=item1+item2;
```
### Strings

- a string is  a variable length sequence of characters
- string type is defined in cpp's 'std' namespace
- to use it we must include the string header

| Ways to initialise a string       |
|-----------------------------------|
| string s //default initialisation |
| string s2(s1) //s2 is copy of s1  |
| string s2 = s1 |
| string s("value") //same meaning as below |
| string s = "value" |
| string s(n, 'c') //initialise s with n copies of char c |

#### String operations

| ??              | what dat mean                                                                                                                                                |
|-----------------|--------------------------------------------------------------------------------------------------------------------------------------------------------------|
| getline(cin, s) | cin>>s would only read the first word of input string by user, doesnt accept space. Hence getline is used cuz it allows space and read till enter is pressed |
| s.empty()       | checks if string is empty, returns boolean                                                                                                                   |
| s.size()        | returns size of string                                                                                                                                       | 
| s[n]            | returns value at certain index; n=index num                                                                                                                  |

#### Operations on characters of a string

- if we wanna do smth to each character of a string, best approach is to use the 'range for' statement, syntax:
```cpp
for (declaration : expression)
    statement
```
E.G:
```cpp
string s="hello"
for (char c : s)
    cout<<c;
```
Detailed e.g:
```cpp
// finding all punctuation marks in a string
#include <string>
#include <iostream>
using std::string;
using std::cout;
int main(){
    int punc_cnt=0;
    string s="hello, kst!!";
            for (char c:s)
                if(ispunct(c)){
                    ++punc_cnt;
                }
    cout<<punc_cnt;
    return 0;        
}
```

- cctype is a header that includes names from c language

#### cctype string functions

| function | what its for                                                                |
| --- |-----------------------------------------------------------------------------|
| `isalnum(c)` | true if `c` is an alphanumeric character (letter or digit).                 |
| `isalpha(c)` | true if `c` is an alphabetic character (A–Z or a–z).                 |
| `iscntrl(c)` | true if `c` is a control character (e.g., newline, tab).             |
| `isdigit(c)` | true if `c` is a decimal digit (0–9).                                |
| `isgraph(c)` | true if `c` is a printable character other than a space.             |
| `islower(c)` | true if `c` is a lowercase letter (a–z).                             |
| `isupper(c)` | true if `c` is an uppercase letter (A–Z).                            |
| `ispunct(c)` | true if `c` is a punctuation character (e.g., !, ?, .).              |
| `isspace(c)` | true if `c` is a whitespace character (e.g., space, tab, newline).   |
| `isprint(c)` | true if `c` is a printable character (including space).              |
| `isxdigit(c)` | true if `c` is a hexadecimal digit (0–9, A–F, a–f).                  |
| `tolower(c)` | Converts an uppercase letter to lowercase; otherwise, returns it unchanged. |
| `toupper(c)` | Converts a lowercase letter to uppercase; otherwise, returns it unchanged.  |

- if we wanna change characters of a string, we shall use references to  do so, e.g:
```cpp
string s="hello kst";
for (&c:s)
    c = toupper(r); //c is a reference to each original character so here we're assigning capital values to each and thus changing the whole string
cout<<s;
```

- a range for statement works we'll when we need to work with all characters of a string but if we wanna work on only certain characters rather all, we use the subscript operator and provide the index
- E.g;
```cpp
string s="hello kst;
if(!s.empty()){
    s[0]=toupper(s[0]);
}
cout<<s;
```

### Vectors

- a vector is basically just a collection of objects of same dt
- std::vector+include vector header file, to use
- a vector is a template, not a type, so the type  needs to be declared with teh declaration as well, as in:
```cpp
vector<int> nums;
vector<Sales_items> salesitemclassvector;
vector<vector<string>> file;
vector<string> articles = {"a", "an", "the"};
```

- We can specify the limit/range of items to be stored in the vector with the following syntax;
```cpp
vector<type> vec(n, value); //here n is the range, a vector of range 10 can have 10 elements
vector<int> randoms(10, 6); //this vector will have 10 nums, all 6s
```

#### Ways to initialise a vector

| method | what it does |
| --- | --- |
| `vector<T> v1`                | Creates an empty vector of type `T`.                                                        |
| `vector<T> v2(v1)`            | Creates `v2` as a copy of `v1` (copy initialization using parentheses).                     |
| `vector<T> v2 = v1`           | Creates `v2` as a copy of `v1` (copy initialization using `=`).                             |
| `vector<T> v3(n, val)`        | Creates a vector containing `n` elements, each initialized to `val`.                        |
| `vector<T> v4(n)`             | Creates a vector containing `n` elements, each value-initialized (e.g., `0` for `int`).     |
| `vector<T> v5{a, b, c, d}`    | Creates a vector containing the elements `a`, `b`, `c`, and `d` (list initialization).      |
| `vector<T> v6 = {a, b, c, d}` | Creates a vector containing the elements `a`, `b`, `c`, and `d` (copy-list initialization). |

Make sure of braces in these fuckers:
```cpp
vector<int> v1(10) //10 elements with value 0
vector<int> v1(10, 1) //10 elements each with value 1
vector<int> v2{10} //1 element with value 10
vector<int> v2{10, 1} //2 element with values 10 & 1
```
To add elements in a vector we use the '.push_back()' function, e.g:
```cpp
vector<int> v;
for(int i=0; i<=100; i++)
    v.push_back(i);
```

#### Vector Operations

| Operation          | What it does                                                                                           |
| ------------------ | ------------------------------------------------------------------------------------------------------ |
| `v.empty()`        | Returns `true` if the vector is empty; otherwise returns `false`.                                      |
| `v.size()`         | Returns the number of elements in the vector (`size_type`).                                            |
| `v.push_back(t)`   | Adds element `t` to the end of the vector.                                                             |
| `v[n]`             | Accesses the element at index `n` (zero-based indexing). Does not perform bounds checking.             |
| `v.at(n)`          | Accesses the element at index `n`. Performs bounds checking and throws `std::out_of_range` if invalid. |
| `v.pop_back()`     | Removes the last element of the vector.                                                                |
| `v.front()`        | Returns a reference to the first element.                                                              |
| `v.back()`         | Returns a reference to the last element.                                                               |
| `v.clear()`        | Removes all elements from the vector.                                                                  |
| `v.begin()`        | Returns an iterator pointing to the first element.                                                     |
| `v.end()`          | Returns an iterator pointing just past the last element.                                               |
| `v.insert(pos, t)` | Inserts element `t` before the position specified by `pos`.                                            |
| `v.erase(pos)`     | Removes the element at the position specified by `pos`.                                                |
| `v.resize(n)`      | Changes the vector's size to `n`.                                                                      |
| `v.reserve(n)`     | Allocates capacity for at least `n` elements without changing its size.                                |
| `v.capacity()`     | Returns the number of elements the vector can hold without reallocating memory.                        |

### Iterators

- We indeed can use the subscript operator to access elements of a vector or chars of a string but a better approach is iterators since not all container types support the subscript operator but they all support iterators
- Each type that supports iterators provides members to use the iterator: 'begin' and 'end' are 2 such members which returns an iterator that denotes the first and last elements of the container. E.G:
```cpp
auto b=v.begin();
auto e=v.end();
```
- tbh, end doesnt return the last element, instead it returns an off the end value, i.e. value after the last element which marks the end.
- 2 iterators are equal if they denote the same element or are both off-the-end iterators.
- As with pointers we can dereference an iterator, e.g:
```cpp
string s("kst");
if(s.begin()!=s.end()){
    auto it=s.begin();
    *it=toupper(*it);
}
cout<<s; //shall return Kst
```

| Iterator Operation | Description                       |
| ------------------ | --------------------------------- |
| `*it`              | Accesses the element              |
| `it->mem`          | Accesses a member of the element  |
| `++it`             | Moves to the next element         |
| `--it`             | Moves to the previous element     |
| `it1 == it2`       | Checks if iterators are equal     |
| `it1 != it2`       | Checks if iterators are not equal |

Moving iterator from one element to another:
```cpp
for(auto it=s.begin(); it!=s.end() && !isspace(*it); ++it){
    *it=toupper(*it);
}
```

- Iterator itself is a type. Regarding thsi context theres two types defined in stl: iterator & const_iterator.
```cpp
vector<int> :: iterator it; //'it' can r&w vector<int> elements
string::iterator it2; //'it2' can r&w chars in a string
vector<int> :: const_iterator it3; //'it3' can read but not write elements
string::const_iterator it4; //'it4' can read but not write chars
```

- If the object is const, begin and end will return a 'const_iterator' type. If it isnt then theyll return an 'iterator' type.
- The new standard provides two new function for the same, 'cbegin' & 'cend', which regardless of the type of object will have const_iterator type
```cpp
auto it=v.cbegin();
```

- To combine dereferencing and member access we do the following:
```cpp
(*it).empty() 
```
here, were trying to check if the object our iterator points to is empty or not but notice how *it is in parentheses.

- To simplify such operations the new standard provides the arrow operator for member access. '(*it).mem' = 'it->mem'
```cpp
for(auto it=text.cbegin(); it!=text.cend() && !it->empty(); ++it){
    cout<<*it;
}
```

| Operations supported by vector and string iterators   | Description                                |
| ----------- | ------------------------------------------ |
| `it + n`    | Moves iterator forward by `n` positions    |
| `it - n`    | Moves iterator backward by `n` positions   |
| `it += n`   | Advances iterator by `n` positions         |
| `it -= n`   | Moves iterator backward by `n` positions   |
| `it1 - it2` | Returns the distance between two iterators |

```cpp
//computing an iterator to the element closest to the mid of vector vi
auto mid=vi.begin()+(vi.size()/2);
```

### Arrays

An array is a data structure that is similar to a vector, difference being that an array has fixed size unlike a vector. We cant add more elements than the size of the array.
- Arrays provides better runtime performance than vectors

Initialisation: 
```cpp
int arr[3]={0,1,2};
```
- Character arrays are special, they can be initialised using a string literal (string literals ends with a null character hence character arrays has a null char as last element)
```cpp
char a1[]={'c', '+', '+'}; //no null
char a2[]={'c','+','+', '\0'}; //explicit null
char a3[]={"c++"}; // null will be added automatically
const char a4[3]={"c++"}; //will error since no space is left for null
```

**We cannot assign an array to another array, copy and assignment is banned between arrays**

| Declaration                         | Meaning                                                       |
| ----------------------------------- | ------------------------------------------------------------- |
| `int (*ptr)[5];`                    | Declares a pointer to an array of 5 integers.                 |
| `int arr[5]; int (*ptr)[5] = &arr;` | Initialises the pointer with the address of the entire array. |
| `(*ptr)[i]`                         | Accesses the element at index `i`.                            |
| `ptr + 1`                           | Advances by the size of an entire array (5 integers).         |
| `int (&ref)[5] = arr;` | Declares a reference to an array of 5 integers. |
| `ref[i]`               | Accesses the element at index `i`.              |

| Pointer to Array                                         | Reference to Array                                  |
| -------------------------------------------------------- | --------------------------------------------------- |
| `int (*ptr)[5]`                                          | `int (&ref)[5]`                                     |
| Can be uninitialised when declared locally.              | Must be initialised at declaration.                 |
| Can be reassigned to point to another compatible array.  | Cannot be reseated to refer to another array.       |
| Requires dereferencing to access the array: `(*ptr)[i]`. | Accesses elements directly: `ref[i]`.               |
| Can be null.                                             | Cannot be a null reference in valid ordinary usage. |

```cpp
int ia[]={0,1,2,3,4};
int *beg=begin(ia);
int *last=end(ia);
```

#### Multidimensional arrays

- cpp doesnt have multidimensional arrays, whats mentioned as multidi arrays are usually: 'Multidimensional array = array of array'
```cpp
int arr[2][4]={1,2,3,4,5,6,7,8};  //array of 2 ints where each of these 2 elements is an array of 4 ints. In this case the first array has {1,2,3,4} and second has {5,6,7,8}
int arr[10][20][30]={0};        // array of 10 ints where each of these 10 is an array of 20 ints where each of these 20 is an array of 30 integers; all initialised to 0
```

