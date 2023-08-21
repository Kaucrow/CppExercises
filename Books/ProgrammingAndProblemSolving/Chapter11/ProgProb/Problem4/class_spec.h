class Time{
    private:
        int minutes, seconds;
    public:
        Time();
        Time(int, int);
        void Add(int, int);
        void Subtract(int, int);
        int GetMinutes();
        int GetSeconds();
        int GetTotalSeconds();
};