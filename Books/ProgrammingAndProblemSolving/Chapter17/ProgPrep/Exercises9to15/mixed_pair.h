#pragma once

template<typename T1, typename T2>
class MixedPair{
    public:
        MixedPair(T1 m, T2 n);
        T1 First() const;
        T2 Second() const;
        void Print() const;
    private:
        T1 first;
        T2 second;
};

typedef MixedPair<int, float> MixedPairIF;
typedef MixedPair<float, int> MixedPairFI;

#include "mixed_pair.tpp"