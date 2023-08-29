#include <iostream>
#include "mixed_pair.h"
#include "exceptions.h"
using std::cout, std::cerr, std::cin;

int Sum(int int1, int int2);

int main(){
    // EXERCISE 9
    MixedPair<float, int> mixedPair(3.1f, 2);
    cout << mixedPair.First() << '\n';
    cout << mixedPair.Second() << '\n';
    mixedPair.Print();
    
    // EXERCISE 10
    MixedPair<int, float> mixedPair2(5, 29.48);
    MixedPair<const char*, int> mixedPair3("Book", 36);
    mixedPair3.Print();

    // EXERCISE 11 : done on mixed_pair.tpp

    // EXERCISE 12 :
    try{
        int a = -1;
        if(a < 0) 
            throw MathError("A MATH ERROR HAS OCCURRED\n");
        cout << "This will never get printed\n";
    }
    catch(MathError err){ cerr << err.what(); }
    
    // EXERCISE 14 & 15:
    try{ cout << Sum(2, INT_MAX); }
    catch(SumTooLarge err){ cerr << err.what(); }
}

int Sum(int int1, int int2){
    try{
        long long checkContainer = static_cast<long long>(int1) + int2;
        if(checkContainer > INT_MAX) 
            throw SumTooLarge("THE SUM OF int1 & int2 IS LARGER THAN INT_MAX\n");
    }
    catch(SumTooLarge err){
        cerr << "FIRST CATCH\n";
        throw;
    } 
    return int1 + int2;
}