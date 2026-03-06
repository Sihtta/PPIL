#ifndef COLOR_H
#define COLOR_H

#include <string>

/// Couleurs disponibles pour les formes
enum class Color
{
    Black,
    Blue,
    Red,
    Green,
    Yellow,
    Cyan
};

/// Convertit une couleur en chaîne de caractères
std::string colorToString(Color c);

/// Convertit une chaîne de caractères en couleur
Color stringToColor(const std::string &s);

#endif