#include <string>
#include <vector>
#include <iostream>
using std::string;
using std::cin;
using std::cout;
using std::vector;
int main(){
    string s;
    getline(cin, s);
    vector<string> words;
    words.push_back(s);
    for(auto r:words){
        cout<<r<<" "<<"\n";
    }
    cout<<words.size();
    return 0;
}