#include "core/Color.h"

// Convertit une valeur de l'énumération Color en chaîne de caractères
std::string colorToString(Color c)
{
    switch (c)
    {
    case Color::Black:
        return "black";
    case Color::Blue:
        return "blue";
    case Color::Red:
        return "red";
    case Color::Green:
        return "green";
    case Color::Yellow:
        return "yellow";
    case Color::Cyan:
        return "cyan";
    }
    return "black";
}

// Convertit une chaîne de caractères en valeur de l'énumération Color
Color stringToColor(const std::string &s)
{
    if (s == "black")
        return Color::Black;
    if (s == "blue")
        return Color::Blue;
    if (s == "red")
        return Color::Red;
    if (s == "green")
        return Color::Green;
    if (s == "yellow")
        return Color::Yellow;
    if (s == "cyan")
        return Color::Cyan;
    return Color::Black;
}