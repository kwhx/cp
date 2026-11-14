## goated legacy notes
- prepared these back in 2025, then halted. Gold standard initial notes for competitive programming

# the global 5% dream

cpp is used in:
- os
- game engines
- robotics
- malware engineering
- competitive programming

```cpp
#include <iostream>  //header file containing declarations for std::cin, std::cout, std::endl, std::cerr, std::clog, and more
// here iostream is being included by  the #include preprocessor directive, it pastes a;ll contents of iostream.h into current file 
int main(){  //entrypoint of the program, os will call main() when execution starts, main() returns an output, return 0 indicates success (we explicitly ask the programs to return an exit status of 0 & this is the reason why return 0 cant be used in helper fx cuz they return a value, cpp allows omitting return 0)
std::cout<<"hello khx"<<std::endl; //std is a namespace, namespaces are containers for names, suppose a program depends on 2 libs a & b and both of them defines the name 'log', this will result in a name collision, this is the reason namespaces are important; cout, vector, string, etc. all lives in std.
// :: is the scope resolution operator, it is used to access a name in a namespace, here we are accessing cout in std namespace, here it basically says 'go into std and fetch the cout term for me so that i can use it.
// cout i sthe character output, a global object of type std::ostream, ostream is a class that represents an output stream, cout is an instance of ostream, it is used to output data to the standard output device (usually the terminal), std::endl is a manipulator that inserts a newline character into the output stream and flushes the stream, flushing means that it forces the output buffer to be written to the output device, this is important because cout is buffered, meaning that it stores data in a buffer before writing it to the output device, this can improve performance but can also cause issues if the program crashes before the buffer is flushed, so we use std::endl to ensure that the buffer is flushed and all output is written to the screen.
// think of cout as a pipe connected to terminal's output buffer, streams=pipelines, a stream is a pipeline that carries data byte by byte
<< is the stream insertion operator, so cout << "hi" = insert string hi in cout stream; cin>>age = insert whatever data comes from keyboard to cin stream and assign to age var; '<'s small mouth is in and large mouth is out (>> is the stream extraction operator, it reads formatted output and skips whiespaces by default)
return 0;
}
```

# datatypes
| type | size in mem (in bytes) | range/precision |
| --- | --- | --- |
| int | 4 | -2billion to 2 billion |
| unsigned int | 4 |  0 to 4 billion |
| long long | 8 | -9 quintillion to 9 quintillion |
| float | 4 | 7 digit precision |
| double | 8 | 15 digit precision |
| bool | 1 | 0/1 |
| char | 1 | -128 to 127 |
| short | 2 | -32,768 to 32,767 |

* 