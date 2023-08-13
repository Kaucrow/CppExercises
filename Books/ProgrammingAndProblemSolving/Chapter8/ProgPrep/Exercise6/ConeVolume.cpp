#include <iostream>
#include <cmath>

using std::cout, std::cin, std::pow;

float ConeVolume(float radius, float height);

int main(){
    float radius, height;
    cout << "Cone radius: "; cin >> radius;
    cout << "Cone height: "; cin >> height;
    cout << "The cone's volume is: " << ConeVolume(radius, height) << '\n';
}

float ConeVolume(float radius, float height){
    return ((M_PI/3)*(pow(radius,2))*height);
}