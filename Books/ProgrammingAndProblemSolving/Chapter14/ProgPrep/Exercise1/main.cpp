#include <iostream>
#include "class_spec.h"
using std::cout;

int main(){
    IDScore johnny("Johnny", 100, 4320533);
    cout    << "Name: " << johnny.GetName() << '\n'
            << "ID: " << johnny.GetID() << '\n'
            <<"Score: " << johnny.GetScore() << '\n';
}