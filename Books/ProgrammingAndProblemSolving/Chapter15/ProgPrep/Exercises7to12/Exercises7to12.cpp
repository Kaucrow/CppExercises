#include <iostream>
using std::cout;

// EXERCISE 10
class Circuit{
    public:
        Circuit(){}
        ~Circuit(){ delete[] source; delete[] sink; }
    private:
        int* source = new int[100];
        int* sink = new int[100];
};
 
int Greatest(int data[], int size);
int GetGreatestInput(int size);

int main(){
    // EXERCISE 7
    int* data = new int[100];
    int max = data[0];
    for(int i = 0; i < 100; i++){
        if(max < data[i]) max = data[i];
    }
    delete[] data; data = nullptr;

    // EXERCISE 8
    data = new int[100];
    cout << "Max: " << Greatest(data, 100) << '\n'; data = nullptr;

    // EXERCISE 9
    cout << "Max2: " << GetGreatestInput(100) << '\n';
    
    // EXERCISE 11
    int* oldValue = nullptr;
    int* newValue = nullptr;
    if(oldValue != nullptr){
        newValue = oldValue;
        int someInt = *newValue;
    }

    // EXERCISE 12
    if(oldValue != newValue){ delete oldValue; }
}

int Greatest(int data[], int size){    // can also use "int* data" as pointer param
    int max = data[0];
    for(int i = 0; i < size; i++){
        if(max < data[i]) max = data[i];
    }
    return max; 
    delete[] data;
}

int GetGreatestInput(int size){
    int* anotherData = new int[size];
    return Greatest(anotherData, size);
}