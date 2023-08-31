#include <iostream>
#include <fstream>
#include <tuple>
#include "conversions.h"
using   std::cout, std::cerr, std::string, std::getline, 
        std::tuple, std::get, std::ifstream;

enum Field {NUMBER, ARTIST, TITLE, MEDIUM, HEIGHT, WIDTH, EXHIBIT, PRICE};

typedef tuple<int, string, string, Medium, float, float, Exhibit, float> Artwork;

string GetCurrData(ifstream& inFile, int spaces);

template<typename T>
void Equal(T search, Field dataField, Artwork artList[], int numPieces);

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

    string selectData;
    cout << "Select data field (Artist/Title/Medium/Height/Width/Exhibit/Price): ";
    std::cin >> selectData;
    for(auto& i : selectData) i = toupper(i);

    string search;
    std::cin.ignore(9999, '\n');
    cout << "Search: "; getline(std::cin, search);

    if(selectData == "ARTIST")
        Equal(search, ARTIST, artList, numPieces);
    else if(selectData == "TITLE")
        Equal(search, TITLE, artList, numPieces);
    else if(selectData == "MEDIUM"){
        Medium searchMed = StrToMedium(search);
        Equal(searchMed, MEDIUM, artList, numPieces); }
    else if(selectData == "HEIGHT"){
        float searchFlt = stof(search);
        Equal(searchFlt, HEIGHT, artList, numPieces); }
    else if(selectData == "WIDTH"){
        float searchFlt = stof(search);
        Equal(searchFlt, WIDTH, artList, numPieces); }
    else if(selectData == "EXHIBIT"){
        Exhibit searchExh = StrToExhibit(search);
        Equal(searchExh, EXHIBIT, artList, numPieces); }
    else if(selectData == "PRICE"){
        float searchFlt = stof(search);
        Equal(searchFlt, PRICE, artList, numPieces); }
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
void Equal(T search, Field dataField, Artwork artList[], int numPieces){
    for(int i = 0; i < numPieces; i++){
        if(search == get<dataField>(artList[i])) 
            cout << "Artwork " << get<NUMBER>(artList[i]) << '\n';
    }
}