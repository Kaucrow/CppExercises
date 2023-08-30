#pragma once

class Exception{
    public:
        Exception(const char* setErr) : error(setErr){}
        const char* what(){ return error; };
    private:
        const char* error;
};

class InvalidPlanet : public Exception{
    public:
        InvalidPlanet(const char* setErr) : Exception(setErr){}
};