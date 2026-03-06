#include "formes/Cercle.h"
#include "transformations/Transformation.h"
#include "visitors/VisiteurForme.h"
#include "core/Color.h"
#include <sstream>

// Constructeur : initialise le cercle avec son centre, son rayon et sa couleur
// Si le rayon est invalide (<= 0), on force une valeur minimale de 1.0
Cercle::Cercle(const Vecteur2D &c, double r, Color col)
    : Forme(col), centre(c), rayon(r > 0 ? r : 1.0) {}

// Retourne le centre du cercle
const Vecteur2D &Cercle::getCentre() const { return centre; }

// Retourne le rayon du cercle
double Cercle::getRayon() const { return rayon; }

// Modifie le centre du cercle
void Cercle::setCentre(const Vecteur2D &c) { centre = c; }

// Modifie le rayon du cercle (doit rester strictement positif)
void Cercle::setRayon(double r)
{
    if (r > 0)
        rayon = r;
}

// Calcule l'aire du cercle
double Cercle::aire() const
{
    const double PI = 3.14159265358979323846;
    return PI * rayon * rayon;
}

// Applique une transformation géométrique au cercle
void Cercle::appliquer(Transformation &t)
{
    t.appliquer(*this);
}

// Méthode du pattern Visitor
void Cercle::accept(VisiteurForme &v)
{
    v.visit(*this);
}

// Retourne une représentation textuelle du cercle
std::string Cercle::toString() const
{
    std::ostringstream oss;
    oss << "Cercle(couleur=" << colorToString(couleur)
        << ", centre=" << centre.toString()
        << ", rayon=" << rayon
        << ")";
    return oss.str();
}