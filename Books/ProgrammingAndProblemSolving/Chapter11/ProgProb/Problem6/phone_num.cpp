#include <iostream>
#include "class_spec.h"
using std::cout;

int main(){
    Phone myPhone("+52 (432) 992-4354");
    cout << myPhone.GetCountryCode() << '\n';
    cout << myPhone.GetAreaCode() << '\n';
    cout << myPhone.GetType() << '\n';
    myPhone.SetType(PAGER);
    cout << myPhone.GetType() << '\n';
    Phone friendPhone(FAX, "+1 (24) 142-4325", 1, 24);
    cout << myPhone.IsEqual(friendPhone) << '\n';
    Phone equalPhone(PAGER, "+52 (432) 992-4354", 52, 432);
    cout << myPhone.IsEqual(equalPhone) << '\n';
}