#include <iostream>
#include <fstream>
#include <variant>
#include <functional>
#include <map>
#include <cmath>        // for round()
using   std::cout, std::cerr, std::cin, std::getline, std::string,
        std::variant, std::get, std::function, std::ifstream;

enum IDType {NAMED, FLAMSTEED, COORDS};

std::map<char, string> ColorCharToStr = 
{{'W', "White"}, {'B', "Blue"}, {'Y', "Yellow"}, {'O', "Orange"}, {'R', "Red"}};

struct Flamsteed{
    int number;
    string constellation;
};

struct Coords{
    float rAsc, decl;
};

typedef variant<string, Flamsteed, Coords> Identifier;

struct Star{
    Identifier identifier;
    float brightness;
    char color;         // [B: Blue] [W: White] [Y: Yellow] [O: Orange] [R: Red]
};

void WriteStar(ifstream& inFile, Star starList[], int& listPos, int idType);
void SearchStar(Star starList[], string search, int typesLim[], int idType);
string GetCurrData(ifstream& inFile, int spaces);
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
            WriteStar(inFile, starList, listPos, i);
        }
        typesLim[i] = listPos;      // stores the ranges in which each star type is on inside the list
    }                               // (each element contains the amount of stars there are on the list
                                    //  up until the end of the range of the current type)

    // ASK THE USER FOR SEARCH INPUT AND CALL SearchStar() ACCORDING TO STAR ID TYPE
    string search;
    cout << "Input your search: "; getline(cin, search);

    if(search.find_first_of('(') != string::npos)
        SearchStar(starList, search, typesLim, COORDS);
    else if(search.find_first_of("0123456789") != string::npos)
        SearchStar(starList, search, typesLim, FLAMSTEED);
    else
        SearchStar(starList, search, typesLim, NAMED);
}

// WRITE STARS FROM THE INPUT FILES INTO THE starList ARRAY
void WriteStar(ifstream& inFile, Star starList[], int& listPos, int idType){
    using WriteID = function<void(ifstream& inFile, Star starList[], int& listPos)>;

    static WriteID writeID[] = {
        [](ifstream& inFile, Star starList[], int listPos){
            starList[listPos].identifier = GetCurrData(inFile, 1); },

        [](ifstream& inFile, Star starList[], int listPos){
            Flamsteed* tempFlam = new Flamsteed;
            string tempStr = GetCurrData(inFile, 1);
            tempFlam->constellation = get<string>(IDStrToData(tempStr, FLAMSTEED));
            tempFlam->number = get<float>(IDStrToData(tempStr, FLAMSTEED));
            starList[listPos].identifier = *tempFlam; delete tempFlam; },

        [](ifstream& inFile, Star starList[], int listPos){
            Coords* tempCoords = new Coords;
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

// SEARCH FOR A STAR ON THE starList, BASED ON ITS IDENTIFIER
#define SEARCH_PARAMS Star starList[], string search, int index 
void SearchStar(Star starList[], string search, int typesLim[], int idType){
    bool foundStar = 0;
    using SearchID = function<bool(SEARCH_PARAMS)>;

    static SearchID searchID[] = {
        [](SEARCH_PARAMS){ return (search == get<string>(starList[index].identifier)); },
        [](SEARCH_PARAMS){ return (search == IDDataToStr(starList, index, FLAMSTEED)); },
        [](SEARCH_PARAMS){ return (search == IDDataToStr(starList, index, COORDS)); }
    };

    int minLim, maxLim;
    if(idType == NAMED){ minLim = 0; maxLim = typesLim[NAMED]; }
    else if(idType == FLAMSTEED){ minLim = typesLim[NAMED]; maxLim = typesLim[FLAMSTEED]; }
    else{ minLim = typesLim[FLAMSTEED]; maxLim = typesLim[COORDS]; }

    // search only in the ranges in which the star type can be at (minLim - maxLim)
    for(int i = minLim; i < maxLim; i++){
        // do the search. If it returns true, the star was found, and print its data
        if(searchID[idType](starList, search, i)){
            cout    << "FOUND STAR:\n";
            cout    << "-------------------------------\n"
                    << "Identifier: ";

            if(idType == NAMED)             cout << get<string>(starList[i].identifier) << '\n';
            else if(idType == FLAMSTEED)    cout << IDDataToStr(starList, i, FLAMSTEED) << '\n';
            else                            cout << IDDataToStr(starList, i, COORDS) << '\n';

            cout << "Brightness: " << starList[i].brightness << '\n'; 
            cout << "Color: ";
            // convert the color char to an actual color string using the map
            for(auto& j : ColorCharToStr){ if(j.first == starList[i].color) cout << j.second << '\n'; }
            cout << "-------------------------------\n";
            foundStar = 1; break;
        }
    }
    if(!foundStar) cout << "STAR \"" << search << "\" WAS NOT FOUND! :(\n";
}

// GET LINE OF DATA FROM THE INFILES, IGNORING THE TEXT PRECEDING AN 'X' NUMBER OF SPACES
string GetCurrData(ifstream& inFile, int spaces){
    string returnStr;
    getline(inFile, returnStr);
    for(int i = 0; i < spaces; i++)
        returnStr = returnStr.substr(returnStr.find(' ') + 1);
    return returnStr;
}

// CONVERT A STR OF DATA SUCH AS "(12.43, 82.01)" OR "Lyncis 40" TO ITS DATA COMPONENTS 
// FOR FLAMSTEED OR COORD STAR TYPES. SHOULD BE CALLED TWICE IN A ROW FOR THE FULL CONVERSION
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

// GETS ID DATA FOR FLAMSTEED OR COORD STAR TYPES STORED IN THE starList, AND CONVERTS IT TO STRING
string IDDataToStr(Star starList[], int index, int idType){
    string returnStr;
    if(idType == FLAMSTEED){
        returnStr += get<Flamsteed>(starList[index].identifier).constellation; 
        returnStr.push_back(' ');
        returnStr += std::to_string(get<Flamsteed>(starList[index].identifier).number);
    }
    else{
        string tempStr;
        returnStr.push_back('('); 
        returnStr += std::to_string(round(get<Coords>(starList[index].identifier).rAsc * 100.0) / 100.0);
        returnStr = returnStr.substr(0, returnStr.find('.') + 3);
        returnStr += ", "; 
        tempStr = std::to_string(round(get<Coords>(starList[index].identifier).decl * 100.0) / 100.0); 
        returnStr += tempStr.substr(0, tempStr.find('.') + 3);
        returnStr.push_back(')');
    }
    return returnStr;
}