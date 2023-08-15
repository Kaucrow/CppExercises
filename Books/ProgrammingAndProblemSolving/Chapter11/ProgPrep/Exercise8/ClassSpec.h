#include <string>

enum Periods       {CUATERNARIO, TERCIARIO, CRETACEO,
                    JURASICO, TRIASICO, PERMICO,
                    CARBONIFERO, DEVONICO, SILURICO,
                    ORDOVICICO, CAMBRICO, PRECAMBRICO,
                    INVALIDO};
class Period{
    private:
        Periods currName;
    public:
        Period();
        Period(Periods newName);
        Periods Name();
        std::string PeriodString(Periods);
        int PeriodInt(Periods);
        std::string PeriodStart(Periods);
        void PeriodIncrease();
};