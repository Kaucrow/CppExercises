#include <iostream>
#include <fstream>
#include <tuple>
#include <functional>
#include <variant>
#include <map>
#include "conversions.h"
using   std::cout, std::cerr, std::string, std::getline, std::ifstream, 
        std::tuple, std::get, std::function, std::variant, std::map;

enum Field {NUMBER, ARTIST, TITLE, MEDIUM, HEIGHT, WIDTH, EXHIBIT, PRICE, ERROR};

map<string, Field> StrField {{"NUMBER", NUMBER}, {"ARTIST", ARTIST}, {"TITLE", TITLE},
                             {"MEDIUM", MEDIUM}, {"HEIGHT", HEIGHT}, {"WIDTH", WIDTH},
                             {"EXHIBIT", EXHIBIT}, {"PRICE", PRICE}};

typedef tuple<int, string, string, Medium, float, float, Exhibit, float> Artwork;
typedef variant<int, string, Medium, float, Exhibit> SearchVar;

string GetCurrData(ifstream& inFile, int spaces);
// SEARCH FUNCTION
void Search(SearchVar& search, Field dataField, Artwork artList[], int numPieces);

int main(){
    string inFileName = "artworks.dat";
    ifstream inFile;
    inFile.open(inFileName);

    int numPieces = stoi(GetCurrData(inFile, 3));
    Artwork artList[numPieces];

    // GET THE FILE'S ARTWORKS AND PUT THEIR DATA IN THE artList
    string currStr;
    for(int currArt = 0; currArt < numPieces; currArt++){
        // ignore the first two lines of the artwork data block
        getline(inFile, currStr); getline(inFile, currStr);

        get<NUMBER> (artList[currArt])    = currArt + 1;
        get<ARTIST> (artList[currArt])    = GetCurrData(inFile, 1);
        get<TITLE>  (artList[currArt])    = GetCurrData(inFile, 2);
        get<MEDIUM> (artList[currArt])    = StrToMedium(GetCurrData(inFile, 1));
        get<HEIGHT> (artList[currArt])    = stoi(GetCurrData(inFile, 1));
        get<WIDTH>  (artList[currArt])    = stoi(GetCurrData(inFile, 2));
        get<EXHIBIT>(artList[currArt])    = StrToExhibit(GetCurrData(inFile, 1));
        get<PRICE>  (artList[currArt])    = stoi(GetCurrData(inFile, 2));
        cout << get<ARTIST>(artList[currArt]) << '\n';
    }

    // THE USER INPUTS THE DATA FIELD TO SEARCH
    string dataFieldStr;
    cout << "Select data field (Artist/Title/Medium/Height/Width/Exhibit/Price): ";
    std::cin >> dataFieldStr;
    for(auto& i : dataFieldStr) i = toupper(i);

    // CONVERT THE STRING TO A "Field" ENUM TYPE VARIABLE 
    Field dataField = ERROR;
    for(auto& i : StrField) if(i.first == dataFieldStr) dataField = i.second;
    if(dataField == ERROR){ cerr << "ERR: DATA FIELD \"" << dataFieldStr << "\" IS NOT A VALID DATA FIELD\n"; return 1; }

    // THE USER INPUTS THE SEARCH
    string searchInput;
    std::cin.ignore(9999, '\n');
    cout << "Search: "; getline(std::cin, searchInput);
    SearchVar search = searchInput;

    // IF NEEDED, CONVERT THE SEARCH TO Float, Medium, OR Exhibit TYPE
    if(dataFieldStr == "HEIGHT" || dataFieldStr == "WIDTH" || dataFieldStr == "PRICE")
        search = stof(searchInput);
    else if(dataFieldStr == "MEDIUM")
        search = StrToMedium(searchInput);
    else if(dataFieldStr == "EXHIBIT")
        search = StrToExhibit(searchInput);

    // CALL THE SEARCH FUNCTION
    Search(search, dataField, artList, numPieces);
}

string GetCurrData(ifstream& inFile, int spaces){
    string tempStr;
    getline(inFile, tempStr);
    for(int i = 0; i < spaces; i++)
        tempStr = tempStr.substr(tempStr.find(' ') + 1);
    return tempStr;
}

void Search(SearchVar& search, Field dataField, Artwork artList[], int numPieces){
    using CompareFunc = function<bool(const Artwork&, const SearchVar&)>;
    
    CompareFunc compareFuncs[] = {
        [](const Artwork& art, const SearchVar& val){ return get<0>(art) == get<int>(val); },
        [](const Artwork& art, const SearchVar& val){ return get<1>(art) == get<string>(val); },
        [](const Artwork& art, const SearchVar& val){ return get<2>(art) == get<string>(val); },
        [](const Artwork& art, const SearchVar& val){ return get<3>(art) == get<Medium>(val); },
        [](const Artwork& art, const SearchVar& val){ return get<4>(art) == get<float>(val); },
        [](const Artwork& art, const SearchVar& val){ return get<5>(art) == get<float>(val); },
        [](const Artwork& art, const SearchVar& val){ return get<6>(art) == get<Exhibit>(val); },
        [](const Artwork& art, const SearchVar& val){ return get<7>(art) == get<float>(val); }
    };

    for (int i = 0; i < numPieces; i++){
        if (compareFuncs[dataField](artList[i], search)) {
            cout << "Artwork " << get<0>(artList[i]) << '\n';
        }
    }
}