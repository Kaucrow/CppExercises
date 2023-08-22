#include <string>
using std::string;

enum PhoneType {HOME, OFFICE, CELL, FAX, PAGE};

class Phone{
    public:
        Phone(int newAreaCode, int newNumber, PhoneType newType);
        virtual void Write() const;
    private:
        int areaCode;
        int number;
        PhoneType type;
        string TypeToStr(PhoneType toConvert) const;
};

class InternPhone : public Phone{
    public:
        InternPhone(int newCountryCode, int newAreaCode,
                    int newNumber, PhoneType newType);
        void Write() const;
    private:
        int countryCode;
};