#include <iostream>
using std::cout;

struct Phone{
    int country, area, number;
};

bool ShallowCompare(Phone* ptrToComp1, Phone* ptrToComp2);
bool DeepCompare(Phone* ptrToComp1, Phone* ptrToComp2);

int main(){
    // EXERCISE 1
    int someInt;
    int* intPtr = &someInt;
    someInt = 451;
    *intPtr = 451;

    // EXERCISE 2
    char initials[4];
    char* initialsPtr;
    initialsPtr[0] = 'A'; 
    initialsPtr[1] = 'E'; 
    initialsPtr[2] = 'W';

    // EXERCISE 3
    Phone newPhone1;
    Phone* phonePtr = &newPhone1;
    phonePtr->country = 1;
    phonePtr->area = 888;
    phonePtr->number = 5551212;

    // EXERCISE 4
    Phone newPhone2;
    Phone& phoneRef = newPhone2;
    phoneRef.country = 1;
    phoneRef.area = 888;
    phoneRef.number = 5551212;
    cout    << phoneRef.country << '\n'
            << phoneRef.area << '\n'
            << phoneRef.number << '\n';

    //EXERCISE 5
    Phone somePhone;
    Phone* phonePtrA = &somePhone;
    Phone* phonePtrB = &somePhone;
    cout << ShallowCompare(phonePtrA, phonePtrB) << '\n';

    //EXERCISE 6
    cout << DeepCompare(phonePtrA, phonePtrB) << '\n';
}

bool ShallowCompare(Phone* ptrToComp1, Phone* ptrToComp2){
    if(ptrToComp1 == ptrToComp2) return true;
    else return false;
}

bool DeepCompare(Phone* ptrToComp1, Phone* ptrToComp2){
    return
        (ptrToComp1->country != ptrToComp2->country)    ? 0 :
        (ptrToComp1->number != ptrToComp2->number)      ? 0 :
        (ptrToComp1->area != ptrToComp2->area)          ? 0 : 1;
}