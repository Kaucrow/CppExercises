#pragma once

class Exception{
    public:
        Exception(const char* setErr) : error(setErr){}
        const char* what(){ return error; };
    private:
        const char* error;
};

class BadInput : public Exception{
    public:
        BadInput(const char* setErr) : Exception(setErr){}
};