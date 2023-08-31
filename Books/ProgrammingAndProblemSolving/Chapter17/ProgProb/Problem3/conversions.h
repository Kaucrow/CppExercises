#pragma once
#include <string>
using std::string;

enum Medium    {OIL, WATERCOLOR, PASTEL, ACRILIC,
                PRINT, COLORPHOTO, BWPHOTO, MED_ERR};

enum Exhibit   {MAINROOM, GREEN, BLUE, NORTH, SOUTH,
                ENTRANCE, BALCONY, EXH_ERR};

string MediumToStr(Medium toConvert);
string ExhibitToStr(Exhibit toConvert);
Medium StrToMedium(string toConvert);
Exhibit StrToExhibit(string toConvert);