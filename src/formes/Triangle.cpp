#include "formes/Triangle.h"
#include "transformations/Transformation.h"
#include "visitors/VisiteurForme.h"
#include "core/Color.h"
#include <sstream>

// Constructeur : initialise les trois sommets du triangle et sa couleur
Triangle::Triangle(const Vecteur2D &a_, const Vecteur2D &b_, const Vecteur2D &c_, Color col)
    : Forme(col), a(a_), b(b_), c(c_) {}

// Retourne le premier sommet
const Vecteur2D &Triangle::getA() const { return a; }

// Retourne le deuxième sommet
const Vecteur2D &Triangle::getB() const { return b; }

// Retourne le troisième sommet
const Vecteur2D &Triangle::getC() const { return c; }

// Modifie le premier sommet
void Triangle::setA(const Vecteur2D &p) { a = p; }

// Modifie le deuxième sommet
void Triangle::setB(const Vecteur2D &p) { b = p; }

// Modifie le troisième sommet
void Triangle::setC(const Vecteur2D &p) { c = p; }

// Calcule l'aire du triangle à partir du déterminant des vecteurs AB et AC
double Triangle::aire() const
{
    Vecteur2D ab = b - a;
    Vecteur2D ac = c - a;
    double area2 = ab.det(ac);
    if (area2 < 0)
        area2 = -area2;
    return 0.5 * area2;
}

// Applique une transformation géométrique au triangle
void Triangle::appliquer(Transformation &t) { t.appliquer(*this); }

// Méthode du pattern Visitor
void Triangle::accept(VisiteurForme &v)
{
    v.visit(*this);
}

// Retourne une représentation textuelle du triangle
std::string Triangle::toString() const
{
    std::ostringstream oss;
    oss << "Triangle(couleur=" << colorToString(couleur)
        << ", a=" << a.toString()
        << ", b=" << b.toString()
        << ", c=" << c.toString()
        << ")";
    return oss.str();
}