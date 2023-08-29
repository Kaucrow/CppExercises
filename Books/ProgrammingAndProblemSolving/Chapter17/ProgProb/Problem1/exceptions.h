#pragma once

class Exception{
    public:
        Exception(const char* setErr) : error(setErr){}
        const char* what(){ return error; };
    private:
        const char* error;
};

class NotFound : public Exception{
    public:
        NotFound(const char* setErr) : Exception(setErr){}
};