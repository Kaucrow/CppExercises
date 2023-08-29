#include <iostream>
#include "mixed_pair.h"
using std::cout;

template<typename T1, typename T2>
MixedPair<T1, T2>::MixedPair(T1 m, T2 n)
    : first(m), second(n){}

template<typename T1, typename T2>
T1 MixedPair<T1, T2>::First() const{
    return first;
}

template<typename T1, typename T2>
T2 MixedPair<T1, T2>::Second() const{
    return second;
}

template<typename T1, typename T2>
void MixedPair<T1, T2>::Print() const{
    cout << '(' << first << ", " << second << ")\n";    
}