class Money{
private:
    int dollars, cents;
public:
    Money();
    Money(int, int);
    void Add(int, int);
    void Subtract(int, int);
    void PrintDollars();
    void PrintCents();
    float Total();
};