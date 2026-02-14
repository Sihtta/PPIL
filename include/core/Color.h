#ifndef COLOR_H
#define COLOR_H

#include <string>

enum class Color
{
    Black,
    Blue,
    Red,
    Green,
    Yellow,
    Cyan
};

std::string colorToString(Color c);

Color stringToColor(const std::string &s);

#endif
