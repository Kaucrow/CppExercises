#include <iostream>

using std::cout, std::cin;

float GetWoodPrice(char woodType, int pieceNum, int width, int height, int length);
int main(){
    // Wood price by board foot (square foot by height inch)
    // Pine         0.89$
    // Fir          1.09$
    // Cedar        2.26$
    // Maple        2.50$
    // Oak          3.10$
    auto checkWoods = [](char woodType, char availWoods[]) -> bool{
        for(int i = 0; i < 6; i++){
            if(woodType == availWoods[i]) return true;
        }
        return false;
    };
    char availWoods[6] = {'P','F','C','M','O','T'};
    float totalPrice = 0, woodPrice;
    char woodType;
    int width, height, length, pieceNum;
    while(true){
        do{
            cout << "\nWood type P,F,C,M,O (or enter \'T\'\nto get total price): "; cin >> woodType;
        }while(!checkWoods(woodType, availWoods));
        if(woodType == 'T') break;
        cout << "Board width in inches: ";  cin >> width;
        cout << "Board height in inches: "; cin >> height;
        cout << "Board length in feet: ";   cin >> length;
        cout << "Number of boards: ";       cin >> pieceNum;
        woodPrice = GetWoodPrice(woodType, pieceNum, width, height, length);
        cout << "The price is: " << woodPrice << "$.\n";
        totalPrice += woodPrice;
    }
    cout << "The total price is: " << totalPrice << "$.\n";
}

float GetWoodPrice(char woodType, int pieceNum, int width, int height, int length){
    float boardFeet;
    boardFeet = (pieceNum * ((width * height * (length * 12)) / 144.0));
    switch(woodType){
        case 'P': return (boardFeet * 0.89);
        case 'F': return (boardFeet * 1.09);
        case 'C': return (boardFeet * 2.26);
        case 'M': return (boardFeet * 2.50);
        case 'O': return (boardFeet * 3.10);
    }
}