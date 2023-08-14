#include <iostream>

using std::cout;

int main(){
    int myInt;
    myInt = 15;
    cout << "myInt: " << myInt << '\n';   
    myInt = 15u;                            // unsigned
    cout << "myInt: " << myInt << '\n';   
    myInt = 15ul;                           // unsigned long
    cout << "myInt: " << myInt << '\n';   
    myInt = 0x0f;                           // hexadecimal
    cout << "myInt: " << myInt << '\n';
    myInt = 017;                            // octal 
    cout << "myInt: " << myInt << '\n';
}