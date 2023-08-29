#include <iostream>
using std::cout, std::cin;

enum AutoType {SEDAN, COUPE, OTHER};

template<typename SomeType>
SomeType SumOfElements(const SomeType arr[], int arrLength);

template<typename SomeType>
void GetData(const char* someStr, SomeType& input);
template<>
void GetData(const char* someStr, AutoType& input);

int main(){
    // EXERCISE 5
    int arrI[] = {1, 2, 3, 4, 5};
    float arrF[] = {1.1f, 2.2f, 3.3f, 4.4f, 5.5f};
    cout << SumOfElements(arrI, sizeof(arrI)/sizeof(int)) << '\n';
    cout << SumOfElements(arrF, sizeof(arrF)/sizeof(float)) << '\n';

    // EXERCISE 6
    std::string input;
    GetData("Input value: ", input);
    cout << input << '\n';
    
    // EXERCISE 7
    AutoType someAuto;
    GetData("Input car: ", someAuto);
}

template<typename SomeType>
SomeType SumOfElements(const SomeType arr[], int arrLength){
    SomeType sum = 0;
    for(int i = 0; i < arrLength; i++){
        sum += arr[i];
    }
    return sum;
}

template<typename SomeType>
void GetData(const char* someStr, SomeType& input){
    cout << someStr; cin >> input;
}

template<>
void GetData(const char* someStr, AutoType& input){
    char selection;

    do{
        cin.ignore(999, '\n');
        cout << someStr;
        cin.get(selection);
    }while(selection != 's' && selection != 'c' && selection != 'o');
    cin.ignore(999, '\n');

    switch(selection){
        case 's': input = SEDAN; break;
        case 'c': input = COUPE; break;
        case 'o': input = OTHER; break;
        default: cout << "ERR: GetData ERROR\n"; break;
    }
}