#include "conversions.h"

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

Medium StrToMedium(string toConvert){
    char tempChar = toupper(toConvert[0]);
    switch(tempChar){
        case 'O':   return OIL;
        case 'W':   return WATERCOLOR;
        case 'A':   return ACRILIC;
        case 'C':   return COLORPHOTO;
        case 'B':   return BWPHOTO;
        case 'P':   return (tolower(toConvert[1]) == 'a') ? PASTEL : PRINT;
        default:    return MED_ERR;
    }
}

Exhibit StrToExhibit(string toConvert){
    char tempChar = toupper(toConvert[0]);
    switch(tempChar){
        case 'M':   return MAINROOM;
        case 'G':   return GREEN;
        case 'N':   return NORTH;
        case 'S':   return SOUTH;
        case 'E':   return ENTRANCE;
        case 'B':   return (tolower(toConvert[1]) == 'l') ? BLUE : BALCONY;
        default:    return EXH_ERR;
    }
}