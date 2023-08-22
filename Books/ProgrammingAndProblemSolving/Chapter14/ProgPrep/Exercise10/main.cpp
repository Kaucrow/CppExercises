#include <iostream>
#include "class_spec.h"
using std::cout;

void PrintComputerData(Computer& someComputer);

int main(){
    Computer testComputer   ("testPC", "testBrand", "testModel", 10,
                             "QWERTY", 30);
    InstallRecord myRecord  ("PC1", "Lenovo", "Thinkpad T420", 340, 
                             "GFDSF", 63542, "Storage", 22, 8, 2023);
    PrintComputerData(testComputer);
    PrintComputerData(myRecord);
}

void PrintComputerData(Computer& someComputer){
    someComputer.Write(); cout << '\n';
}