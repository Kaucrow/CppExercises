#include <iostream>

using std::cout, std::cin;

int Power(int base, int exp);

int main(){
    int base, exp;
    cout << "Base value: ";     cin >> base;
    cout << "Exponent value: "; cin >> exp;
    cout << "The result is: " << Power(base, exp) << '\n'; 
}

int Power(int base, int exp){
    int result = 1;
    while(exp > 0){
        result *= base;
        exp--;
    }
    return result;
}