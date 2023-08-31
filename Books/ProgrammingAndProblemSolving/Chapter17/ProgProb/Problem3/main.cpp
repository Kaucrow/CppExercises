#include <iostream>
#include <fstream>
#include "conversions.h"
using std::cout, std::cerr, std::string, std::getline, std::ifstream;

struct Artwork{
    int number;
    string artist, title;
    Medium medium;
    struct{
        float height, width;
    }Size;
    Exhibit exhibit;
    float price;
};

string GetCurrData(ifstream& inFile, int spaces);

template<typename T>
void Equal (T search, T comparison, Artwork& i);

int main(){
    string inFileName = "artworks.dat";
    ifstream inFile;
    inFile.open(inFileName);

    int numPieces = stoi(GetCurrData(inFile, 3));
    Artwork artList[numPieces];

    string currStr;
    for(int currArt = 0; currArt < numPieces; currArt++){
        // ignore the first two lines of the artwork data block
        getline(inFile, currStr); getline(inFile, currStr);

        artList[currArt].number      = currArt + 1;
        artList[currArt].artist      = GetCurrData(inFile, 1);
        artList[currArt].title       = GetCurrData(inFile, 2);
        artList[currArt].medium      = StrToMedium(GetCurrData(inFile, 1));
        artList[currArt].Size.height = stoi(GetCurrData(inFile, 1));
        artList[currArt].Size.width  = stoi(GetCurrData(inFile, 2));
        artList[currArt].exhibit     = StrToExhibit(GetCurrData(inFile, 1));
        artList[currArt].price       = stoi(GetCurrData(inFile, 2));
        cout << artList[currArt].title << '\n';
    }

    string selectData;
    cout << "Select data field (Artist/Title/Medium/Height/Width/Exhibit/Price): ";
    std::cin >> selectData;
    for(auto& i : selectData) i = toupper(i);

    string search;
    std::cin.ignore(9999, '\n');
    cout << "Search: "; getline(std::cin, search);

    if(selectData == "ARTIST")
        for(auto& i: artList){ (Equal(search, i.artist, i)); }
    else if(selectData == "TITLE")
        for(auto& i : artList){ (Equal(search, i.title, i)); }
    else if(selectData == "MEDIUM"){
        Medium searchMed = StrToMedium(search);
        for(auto& i : artList){ (Equal(searchMed, i.medium, i)); }}
    else if(selectData == "HEIGHT"){
        float searchFlt = stof(search);
        for(auto& i : artList){ (Equal(searchFlt, i.Size.height, i)); }}
    else if(selectData == "WIDTH"){
        float searchFlt = stof(search);
        for(auto& i : artList){ (Equal(searchFlt, i.Size.width, i)); }}
    else if(selectData == "EXHIBIT"){
        Exhibit searchExh = StrToExhibit(search);
        for(auto& i : artList){ (Equal(searchExh, i.exhibit, i)); }}
    else if(selectData == "PRICE"){
        float searchFlt = stof(search);
        for(auto& i : artList){ (Equal(searchFlt, i.price, i)); }}
    else cerr << "ERR: DATA FIELD \"" << selectData << "\" IS NOT A VALID DATA FIELD\n";
}

string GetCurrData(ifstream& inFile, int spaces){
    string tempStr;
    getline(inFile, tempStr);
    for(int i = 0; i < spaces; i++)
        tempStr = tempStr.substr(tempStr.find(' ') + 1);
    return tempStr;
}

template<typename T>
void Equal (T search, T comparison, Artwork& i){
    if(search == comparison) cout << "Artwork " << i.number << '\n';
}