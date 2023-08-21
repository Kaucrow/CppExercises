#include <iostream>
using std::cout, std::string;

enum Medium    {OIL, WATERCOLOR, PASTEL, ACRILIC,
                PRINT, COLORPHOTO, BWPHOTO};

enum Exhibit   {MAINROOM, GREEN, BLUE, NORTH, SOUTH,
                ENTRANCE, BALCONY};

string MediumToStr(Medium toConvert);
string ExhibitToStr(Exhibit toConvert);

int main(){
    const int STARTING_PIECES = 120;
    struct Artwork{
        string artist, title;
        Medium medium;
        struct{
            float height, width;
        }Size;
        Exhibit exhibit;
        float price;
    };
    Artwork currentList[STARTING_PIECES];
    int numPieces = STARTING_PIECES;

    cout << "ARTWORK #37:\n"
            << "Artist:  "  << currentList[36].artist << '\n'
            << "Title:   "  << currentList[36].title << '\n'
            << "Medium:  "  << MediumToStr(currentList[36].medium) << '\n'
            << "Size:    "  << currentList[36].Size.height << 'x' << currentList[36].Size.width << '\n'
            << "Exhibit: "  << ExhibitToStr(currentList[36].exhibit) << '\n'
            << "Price:   "  << currentList[36].price << "$\n\n";

    currentList[77].artist = "John Doe"; 
    cout << "ARTWORK #78:\n"
            << "First letter of the artist's name: " << currentList[77].artist[0] << "\n\n";

    cout << "*** AVAILABLE ARTWORKS ***\n\n";
    for(int i = 0; i < STARTING_PIECES; i++){
        cout << "ARTWORK #" << i + 1 << ":\n"
            << "Artist:  "  << currentList[i].artist << '\n'
            << "Title:   "  << currentList[i].title << '\n'
            << "Medium:  "  << MediumToStr(currentList[i].medium) << '\n'
            << "Size:    "  << currentList[i].Size.height << 'x' << currentList[i].Size.width << '\n'
            << "Exhibit: "  << ExhibitToStr(currentList[i].exhibit) << '\n'
            << "Price:   "  << currentList[i].price << "$\n\n";
    }
}

string MediumToStr(Medium toConvert){
    switch(toConvert){
        case OIL:           return "Oil";
        case WATERCOLOR:    return "Watercolor";
        case PASTEL:        return "Pastel";
        case ACRILIC:       return "Acrilic";
        case PRINT:         return "Print";
        case COLORPHOTO:    return "Color Photo";
        case BWPHOTO:       return "B/W Photo";
        default:            return "ERROR";
    }
}

string ExhibitToStr(Exhibit toConvert){
    switch(toConvert){
        case MAINROOM:  return "Main Room";
        case GREEN:     return "Green Room";
        case BLUE:      return "Blue Room";
        case NORTH:     return "North Room";
        case SOUTH:     return "South Room";
        case ENTRANCE:  return "Entrance";
        case BALCONY:   return "Balcony";
        default:        return "ERROR";
    }
}