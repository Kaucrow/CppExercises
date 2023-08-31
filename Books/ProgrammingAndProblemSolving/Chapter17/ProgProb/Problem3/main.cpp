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
bool Equal (T search, T comparison);

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
        for(auto& i : artList){ if(Equal(search, i.artist))                 cout << "Artwork " << i.number << '\n'; }
    else if(selectData == "TITLE")
        for(auto& i : artList){ if(Equal(search, i.title))                  cout << "Artwork " << i.number << '\n'; }
    else if(selectData == "MEDIUM")
        for(auto& i : artList){ if(Equal(StrToMedium(search), i.medium))    cout << "Artwork " << i.number << '\n'; }
    else if(selectData == "HEIGHT")
        for(auto& i : artList){ if(Equal(stof(search), i.Size.height))      cout << "Artwork " << i.number << '\n'; }
    else if(selectData == "WIDTH")
        for(auto& i : artList){ if(Equal(stof(search), i.Size.width))       cout << "Artwork " << i.number << '\n'; }
    else if(selectData == "EXHIBIT")
        for(auto& i : artList){ if(Equal(StrToExhibit(search), i.exhibit))  cout << "Artwork " << i.number << '\n'; }
    else if(selectData == "PRICE")
        for(auto& i : artList){ if(Equal(stof(search), i.price))            cout << "Artwork " << i.number << '\n'; }
    else cerr << "ERR: DATA FIELD \"" << selectData << "\" IS NOT A VALID DATA FIELD\n";
}

string GetCurrData(ifstream& inFile, int spaces){
    string tempStr;
    getline(inFile, tempStr);
    //cout << tempStr << '\n';
    for(int i = 0; i < spaces; i++)
        tempStr = tempStr.substr(tempStr.find(' ') + 1);
    return tempStr;
}

template<typename T>
bool Equal (T search, T comparison){
    return (search == comparison);
}