#ifndef VECTEUR2D_H
#define VECTEUR2D_H

#include <string>

/**
 * @class Vecteur2D
 * @brief Représente un vecteur du plan (x,y).
 */
class Vecteur2D
{
public:
    double x; /// coordonnée x
    double y; /// coordonnée y

    /// Constructeur
    Vecteur2D(double x_ = 0.0, double y_ = 0.0);

    /// Addition de deux vecteurs
    Vecteur2D operator+(const Vecteur2D &other) const;

    /// Soustraction de deux vecteurs
    Vecteur2D operator-(const Vecteur2D &other) const;

    /// Multiplication par un scalaire
    Vecteur2D operator*(double a) const;

    /// Opposé du vecteur
    Vecteur2D operator-() const;

    /// Déterminant entre deux vecteurs
    double det(const Vecteur2D &other) const;

    /// Conversion en chaîne "(x,y)"
    std::string toString() const;
};

/// Scalaire * vecteur
Vecteur2D operator*(double a, const Vecteur2D &v);

#endif