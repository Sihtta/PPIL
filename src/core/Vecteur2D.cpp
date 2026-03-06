#include "core/Vecteur2D.h"
#include <sstream>

// Constructeur : initialise les coordonnées du vecteur
Vecteur2D::Vecteur2D(double x_, double y_) : x(x_), y(y_) {}

// Addition de deux vecteurs
Vecteur2D Vecteur2D::operator+(const Vecteur2D &other) const
{
    return Vecteur2D(x + other.x, y + other.y);
}

// Soustraction de deux vecteurs
Vecteur2D Vecteur2D::operator-(const Vecteur2D &other) const
{
    return Vecteur2D(x - other.x, y - other.y);
}

// Multiplication du vecteur par un scalaire
Vecteur2D Vecteur2D::operator*(double a) const
{
    return Vecteur2D(x * a, y * a);
}

// Opposé du vecteur
Vecteur2D Vecteur2D::operator-() const
{
    return Vecteur2D(-x, -y);
}

// Calcul du déterminant entre deux vecteurs
// utile pour les calculs géométriques (ex : aire d'un triangle)
double Vecteur2D::det(const Vecteur2D &other) const
{
    return x * other.y - y * other.x;
}

// Conversion du vecteur en chaîne de caractères "(x, y)"
std::string Vecteur2D::toString() const
{
    std::ostringstream oss;
    oss << "( " << x << ", " << y << " )";
    return oss.str();
}

// Permet d'écrire : scalaire * vecteur
Vecteur2D operator*(double a, const Vecteur2D &v)
{
    return v * a;
}