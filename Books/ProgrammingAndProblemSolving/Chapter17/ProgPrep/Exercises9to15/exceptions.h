#pragma once

class Exception{
    public:
        Exception(const char* setErr) : error(setErr){}
        const char* what(){ return error; };
    private:
        const char* error; 
};

class MathError : public Exception{
    public:
        MathError(const char* setErr) : Exception(setErr){}
};

class SumTooLarge : public Exception{
    public:
        SumTooLarge(const char* setErr) : Exception(setErr){}
};