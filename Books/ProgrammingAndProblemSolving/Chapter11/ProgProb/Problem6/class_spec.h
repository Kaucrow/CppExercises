using std::string;

enum Type {HOME, OFFICE, FAX, CELL, PAGER};

class Phone{
    private:
        Type type;
        string number;
        int countryCode, areaCode;
    public:
        Phone();
        Phone(string);
        Phone(Type, string, int, int);
        void SetType(Type);
        void SetNumber(string);
        void SetCountryCode(int);
        void SetAreaCode(int);
        string GetType() const;
        string GetNumber() const;
        int GetCountryCode() const;
        int GetAreaCode() const;
        bool IsEqual(Phone) const;
};