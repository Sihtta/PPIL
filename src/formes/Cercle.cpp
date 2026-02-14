#include "formes/Cercle.h"
#include "transformations/Transformation.h"
#include "visitors/VisiteurForme.h"
#include "core/Color.h"
#include <sstream>

Cercle::Cercle(const Vecteur2D &c, double r, Color col)
    : Forme(col), centre(c), rayon(r > 0 ? r : 1.0) {}

const Vecteur2D &Cercle::getCentre() const { return centre; }
double Cercle::getRayon() const { return rayon; }

void Cercle::setCentre(const Vecteur2D &c) { centre = c; }

void Cercle::setRayon(double r)
{
    if (r > 0)
        rayon = r;
}

double Cercle::aire() const
{
    const double PI = 3.14159265358979323846;
    return PI * rayon * rayon;
}

void Cercle::appliquer(Transformation &t)
{
    t.appliquer(*this);
}

void Cercle::accept(VisiteurForme &v)
{
    v.visit(*this);
}

std::string Cercle::toString() const
{
    std::ostringstream oss;
    oss << "Cercle(couleur=" << colorToString(couleur)
        << ", centre=" << centre.toString()
        << ", rayon=" << rayon
        << ")";
    return oss.str();
}
