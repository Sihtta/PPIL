#ifndef MATRICE22_H
#define MATRICE22_H

#include "core/Vecteur2D.h"
#include <cmath>
#include <sstream>
#include <string>

class Matrice22
{
public:
    Vecteur2D ligneHaut;
    Vecteur2D ligneBas;

    Matrice22(const Vecteur2D &lh, const Vecteur2D &lb)
        : ligneHaut(lh), ligneBas(lb) {}

    explicit Matrice22(const double &a11 = 1.0,
                       const double &a12 = 0.0,
                       const double &a21 = 0.0,
                       const double &a22 = 1.0)
        : ligneHaut(a11, a12), ligneBas(a21, a22) {}

    static Matrice22 creeRotation(const double &angle)
    {
        const double c = std::cos(angle);
        const double s = std::sin(angle);
        return Matrice22(c, -s, s, c);
    }

    static Matrice22 creeHomothetie(const double &k)
    {
        return Matrice22(k, 0.0, 0.0, k);
    }

    Vecteur2D operator*(const Vecteur2D &v) const
    {
        return Vecteur2D(
            ligneHaut.x * v.x + ligneHaut.y * v.y,
            ligneBas.x * v.x + ligneBas.y * v.y);
    }

    operator std::string() const
    {
        std::ostringstream os;

        os << "(" << ligneHaut.x << ", " << ligneHaut.y << ")\n";
        os << "(" << ligneBas.x << ", " << ligneBas.y << ")";

        return os.str();
    }
};

#endif