#include <iostream>
using std::cout, std::string;

template<typename SomeType> 
void Square(SomeType& toSquare);

int MultiplyPer2(int someInt);
float MultiplyPer2(float someFloat);

template<> 
void Square(string& someStr);

int main(){
    int myInt = 3;
    long myLong = 5.0l;
    float myFloat = 4.0f;
    string someStr = "Hello";

    Square(myInt);
    cout << myInt << '\n';
    
    Square(myLong);
    cout << myLong << '\n';

    Square(myFloat);
    cout << myFloat << '\n';

    Square(someStr);

    cout << MultiplyPer2(2) << '\n';
    cout << MultiplyPer2(2.2f) << '\n';
}

template<typename SomeType> 
void Square(SomeType& toSquare){
    toSquare = toSquare * toSquare;
}

template<> 
void Square(string& someStr){
    cout << someStr << someStr << '\n';
}

int MultiplyPer2(int someInt){
    return 2 * someInt;
}

float MultiplyPer2(float someFloat){
    return 2 * someFloat;
}