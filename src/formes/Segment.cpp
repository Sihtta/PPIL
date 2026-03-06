#include "formes/Segment.h"
#include "transformations/Transformation.h"
#include "visitors/VisiteurForme.h"
#include "core/Color.h"
#include <sstream>

// Constructeur : initialise les deux points du segment et sa couleur
Segment::Segment(const Vecteur2D &a_, const Vecteur2D &b_, Color c)
    : Forme(c), a(a_), b(b_) {}

// Retourne le premier point du segment
const Vecteur2D &Segment::getA() const { return a; }

// Retourne le second point du segment
const Vecteur2D &Segment::getB() const { return b; }

// Modifie le premier point du segment
void Segment::setA(const Vecteur2D &p) { a = p; }

// Modifie le second point du segment
void Segment::setB(const Vecteur2D &p) { b = p; }

// L'aire d'un segment est nulle
double Segment::aire() const { return 0.0; }

// Applique une transformation géométrique au segment
void Segment::appliquer(Transformation &t)
{
    t.appliquer(*this);
}

// Méthode du pattern Visitor
void Segment::accept(VisiteurForme &v)
{
    v.visit(*this);
}

// Retourne une représentation textuelle du segment
std::string Segment::toString() const
{
    std::ostringstream oss;
    oss << "Segment(couleur=" << colorToString(couleur)
        << ", a=" << a.toString()
        << ", b=" << b.toString()
        << ")";
    return oss.str();
}