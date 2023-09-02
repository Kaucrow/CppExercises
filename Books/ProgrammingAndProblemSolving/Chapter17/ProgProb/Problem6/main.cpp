#include "date_class.h"
#include "exceptions.h"
using std::cerr;

int main(){
    Date date1, date2;

    try{ date1 = Date(28, 8, 1993); date1.PrintDate(); }
    catch(Exception excep){ cerr << excep.what(); return 1; }
    
    try{ date2 = Date(28, 8, 1993); date2.PrintDate(); }
    catch(Exception excep){ cerr << excep.what(); return 1; }

    if(date1.Equal(date2)) cout << "THE DATES ARE EQUAL!\n"; 
}

