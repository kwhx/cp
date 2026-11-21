#include <string>
#include <iostream>

using std::string;
using std::cout;

int main(){
    string s="hello kst";
    if(!s.empty()){
        s[2]=toupper(s[2]);
    }
    cout<<s;
}