//write code to change value of a pointer. write code to change the value to which the pointer points
#include <iostream>
using std::cout;
int main(){
int a=4;
int *b=&a;
cout<<b<<" "<<a<<"\n";
b=0;
    cout<<b<<" "<<a<<"\n";
return 0;
}
