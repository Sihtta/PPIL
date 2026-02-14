#ifndef VECTEUR2D_H
#define VECTEUR2D_H

#include <string>

class Vecteur2D
{
public:
    double x;
    double y;

    Vecteur2D(double x_ = 0.0, double y_ = 0.0);

    // opérations simples
    Vecteur2D operator+(const Vecteur2D &other) const;
    Vecteur2D operator-(const Vecteur2D &other) const;
    Vecteur2D operator*(double a) const;
    Vecteur2D operator-() const;

    // outils utiles
    double det(const Vecteur2D &other) const;
    std::string toString() const;
};

// scalaire * vecteur (côté scalaire)
Vecteur2D operator*(double a, const Vecteur2D &v);

#endif
