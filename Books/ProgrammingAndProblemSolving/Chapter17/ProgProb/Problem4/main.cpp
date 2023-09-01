#include <iostream>
#include <fstream>
#include <variant>
#include <functional>
using   std::cout, std::cerr, std::cin, std::getline, std::string,
        std::variant, std::get, std::function, std::ifstream;

struct Flamsteed{
    int number;
    string constellation;
};

struct EqCoords{
    float rAsc, decl;
};

typedef variant<string, Flamsteed, EqCoords> Identifier;

struct Star{
    Identifier identifier;
    float brightness;
    char color;         // [B: Blue] [W: White] [Y: Yellow] [O: Orange] [R: Red]
};

string GetCurrData(ifstream& inFile, int spaces);
void WriteStar(ifstream& inFile, Star starList[], int idType);

int main(){
    auto OpenFile = [](ifstream& inFile, string fileName){
        inFile.close(); inFile.open(fileName);
        if(!inFile){ cerr << "ERR: COULD NOT OPEN FILE \"" << fileName << "\"\n"; return 1; } return 0;
    };
    int starNum = 0;
    string fileNames[3] = {"named.dat", "numbered.dat", "coord.dat"};
    ifstream inFile;

    // OPEN THE FILES AND ADD THE NUMBERS OF STARS TO starNum
    for(int i = 0; i < 3; i++){
        if(OpenFile(inFile, fileNames[i])){ return 1; };
        starNum += stoi(GetCurrData(inFile, 5));
        cout << starNum << '\n';
    }

    // WRITE THE STARS IN THE FILES INTO AN ARRAY OF TYPE Star
    Star starList[starNum];
    int currStars, listPos = 0;
    string tempStr;
    for(int i = 0; i < 3; i++){
        OpenFile(inFile, fileNames[i]);
        currStars = stoi(GetCurrData(inFile, 5)); getline(inFile, tempStr);
        for(int j = 0; j < currStars; j++){
            getline(inFile, tempStr);
            WriteStar(inFile, starList, i);
        }
    }
    cout << starList[1].color << '\n';
}

string GetCurrData(ifstream& inFile, int spaces){
    string tempStr;
    getline(inFile, tempStr);
    for(int i = 0; i < spaces; i++)
        tempStr = tempStr.substr(tempStr.find(' ') + 1);
    return tempStr;
}

void WriteStar(ifstream& inFile, Star starList[], int idType){
    static int listPos = 0;
    using WriteID = function<void (ifstream& inFile, Star starList[], int listPos)>;

    static WriteID writeID[] = {
        [](ifstream& inFile, Star starList[], int listPos){ starList[listPos].identifier = GetCurrData(inFile, 1); },

        [](ifstream& inFile, Star starList[], int listPos){
            Flamsteed* tempFlam = new Flamsteed;
            string tempStr = GetCurrData(inFile, 1);
            tempFlam->constellation = tempStr.substr(0, tempStr.find(' '));
            tempFlam->number = stoi(tempStr.substr(tempStr.find(' ') + 1));
            starList[listPos].identifier = *tempFlam; delete tempFlam; },

        [](ifstream& inFile, Star starList[], int listPos){
            EqCoords* tempCoords = new EqCoords;
            string tempStr = GetCurrData(inFile, 1); tempStr = tempStr.substr(1);
            tempCoords->rAsc = stof(tempStr);
            tempCoords->decl = stof(tempStr.substr(tempStr.find(' ') + 1, tempStr.find(')')));
            starList[listPos].identifier = *tempCoords; delete tempCoords; }
    };

    writeID[idType](inFile, starList, listPos);
    starList[listPos].brightness = stof(GetCurrData(inFile, 1));
    starList[listPos].color = (GetCurrData(inFile, 1))[0];
    listPos++;
}