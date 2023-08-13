#include <iostream>

using std::cout, std::cin;

bool Equal(float numX, float numY);

int main(){
    float numX, numY;
    cout << "X number: "; cin >> numX;
    cout << "Y number: "; cin >> numY;
    if(Equal(numX, numY)) cout << "The numbers are equal.\n";
    else cout << "The numbers are not equal.\n";
}

bool Equal(float numX, float numY){
    if((abs(numX - numY) < 0.00000001)) return true;
    else return false;
}