#include <iostream>
#include <fstream>
#include <variant>
#include <functional>
#define STR_TO_ID_PARAMS string search, string& searchName, int& searchNumber, float& searchRAsc, float& searchDecl
using   std::cout, std::cerr, std::cin, std::getline, std::string,
        std::variant, std::get, std::function, std::ifstream;

enum IDType {NAMED, FLAMSTEED, COORDS};

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
void WriteStar(ifstream& inFile, Star starList[], int idType, int& listPos);
void SearchStar(Star starList[], int minLim, int maxLim, string search, int idType);
variant<float, string> IDStrToData(string toConvert, int idType);
string IDDataToStr(Star starList[], int index, int idType);

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
    int typesLim[3];
    string tempStr;
    for(int i = 0; i < 3; i++){
        OpenFile(inFile, fileNames[i]);
        currStars = stoi(GetCurrData(inFile, 5)); getline(inFile, tempStr);
        for(int j = 0; j < currStars; j++){
            getline(inFile, tempStr);
            WriteStar(inFile, starList, i, listPos);
        }
        typesLim[i] = listPos - 1;
    }
    cout << starList[1].color << '\n';

    string search;
    int searchStarType;
    cout << "Input your search: "; getline(cin, search);
    if(search.find_first_of('(') != string::npos){ cout << "FOUND (! " << '\n'; searchStarType = 2; }
    else if(search.find_first_of("0123456789") != string::npos){ cout << "FOUND NUM! " << '\n'; searchStarType = 1; }
    else{ cout << "FOUND NONE! " << '\n'; searchStarType = 0; }
}

string GetCurrData(ifstream& inFile, int spaces){
    string tempStr;
    getline(inFile, tempStr);
    for(int i = 0; i < spaces; i++)
        tempStr = tempStr.substr(tempStr.find(' ') + 1);
    return tempStr;
}

void WriteStar(ifstream& inFile, Star starList[], int idType, int& listPos){
    using WriteID = function<void(ifstream& inFile, Star starList[], int listPos)>;

    static WriteID writeID[] = {
        [](ifstream& inFile, Star starList[], int listPos){ starList[listPos].identifier = GetCurrData(inFile, 1); },

        [](ifstream& inFile, Star starList[], int listPos){
            Flamsteed* tempFlam = new Flamsteed;
            string tempStr = GetCurrData(inFile, 1);
            tempFlam->constellation = get<string>(IDStrToData(tempStr, FLAMSTEED));
            tempFlam->number = get<float>(IDStrToData(tempStr, FLAMSTEED));
            starList[listPos].identifier = *tempFlam; delete tempFlam; },

        [](ifstream& inFile, Star starList[], int listPos){
            EqCoords* tempCoords = new EqCoords;
            string tempStr = GetCurrData(inFile, 1);
            tempCoords->rAsc = get<float>(IDStrToData(tempStr, COORDS));
            tempCoords->decl = get<float>(IDStrToData(tempStr, COORDS));
            starList[listPos].identifier = *tempCoords; delete tempCoords; }
    };

    writeID[idType](inFile, starList, listPos);
    starList[listPos].brightness = stof(GetCurrData(inFile, 1));
    starList[listPos].color = (GetCurrData(inFile, 1))[0];
    listPos++;
}

#define SEARCH_PARAMS Star starList[], string search, int index 
void SearchStar(Star starList[], int minLim, int maxLim, string search, int idType){
    using SearchID = function<bool(SEARCH_PARAMS)>;

    static SearchID searchID[] = {
        [](SEARCH_PARAMS){ return (search == get<string>(starList[index].identifier)); },
        [](SEARCH_PARAMS){ return (search == IDDataToStr(starList, index, FLAMSTEED)); },
        [](SEARCH_PARAMS){ return (search == IDDataToStr(starList, index, COORDS)); }
    };
}

variant<float, string> IDStrToData(string toConvert, int idType){
    static bool status = 0;
    if(status == 0){
        status = 1;
        if(idType == FLAMSTEED) return toConvert.substr(0, toConvert.find(' '));
        else return stof(toConvert.substr(1));
    }
    else
        { status = 0; return stof(toConvert.substr(toConvert.find(' ') + 1)); }
}

string IDDataToStr(Star starList[], int index, int idType){
    string returnStr;
    if(idType == FLAMSTEED){
        returnStr += get<Flamsteed>(starList[index].identifier).constellation; 
        returnStr.push_back(' ');
        returnStr += get<Flamsteed>(starList[index].identifier).number;
    }
    else{
        returnStr.push_back('('); returnStr += get<EqCoords>(starList[index].identifier).rAsc;
        returnStr.push_back(','); returnStr.push_back(' ');
        returnStr += get<EqCoords>(starList[index].identifier).decl; returnStr.push_back(')');
    }
    return returnStr;
}