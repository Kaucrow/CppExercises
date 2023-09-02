#pragma once

class Exception{
    public:
        Exception(const char* setErr) : error(setErr){}
        const char* what(){ return error; };
    private:
        const char* error;
};

class InvalidDay : public Exception{
    public:
        InvalidDay(const char* setErr) : Exception(setErr){}
};

class InvalidMonth : public Exception{
    public:
        InvalidMonth(const char* setErr) : Exception(setErr){}
};

class InvalidYear : public Exception{
    public:
        InvalidYear(const char* setErr) : Exception(setErr){}
};