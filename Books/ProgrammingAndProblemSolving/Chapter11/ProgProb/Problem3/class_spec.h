using std::string;
// Mercury  0.4155
// Venus    0.8975
// Earth    1.0
// Moon     0.166
// Mars     0.3507
// Jupiter  2.5374
// Saturn   1.0677
// Uranus   0.8947
// Neptune  1.1794
// Pluto    0.0899
enum Planets   {MERCURY, VENUS, EARTH, MOON, MARS, JUPITER, 
                SATURN, URANUS, NEPTUNE, PLUTO, ERROR};

Planets StrToPlanets(string planetName);

class Weight
{
private:
    Planets planet;
    double weight;
public:
    Weight();
    Weight(Planets);
    void Set(double setWeight);
    double Get();
};