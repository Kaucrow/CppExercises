#include <iostream>
using std::cout, std::string, std::swap;

void Reverse(string& str);

int main(){
    string str = "Hello World";
    cout << "Original string: " << str << '\n';
    Reverse(str);
    cout << "Reversed string: " << str << '\n';
}

void Reverse(string& str){
    for(int i = 0; i < (str.length() / 2); i++){
        swap(str[i], str[str.length() - 1 - i]);
    }
}