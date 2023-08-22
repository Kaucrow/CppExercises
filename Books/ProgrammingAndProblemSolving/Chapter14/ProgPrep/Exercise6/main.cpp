#include <iostream>
#include "class_spec.h"
using std::cout;

void Print(Phone& somePhone);

int main(){
    InternPhone friendPhone(43, 82, 4324235, HOME);
    Print(friendPhone);
}

void Print(Phone& somePhone){
    somePhone.Write();
}