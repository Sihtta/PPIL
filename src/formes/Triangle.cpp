#include "formes/Triangle.h"
#include "transformations/Transformation.h"
#include "visitors/VisiteurForme.h"
#include "core/Color.h"
#include <sstream>

Triangle::Triangle(const Vecteur2D &a_, const Vecteur2D &b_, const Vecteur2D &c_, Color col)
    : Forme(col), a(a_), b(b_), c(c_) {}

const Vecteur2D &Triangle::getA() const { return a; }
const Vecteur2D &Triangle::getB() const { return b; }
const Vecteur2D &Triangle::getC() const { return c; }

void Triangle::setA(const Vecteur2D &p) { a = p; }
void Triangle::setB(const Vecteur2D &p) { b = p; }
void Triangle::setC(const Vecteur2D &p) { c = p; }

double Triangle::aire() const
{
    Vecteur2D ab = b - a;
    Vecteur2D ac = c - a;
    double area2 = ab.det(ac);
    if (area2 < 0)
        area2 = -area2;
    return 0.5 * area2;
}

void Triangle::appliquer(Transformation &t) { t.appliquer(*this); }

void Triangle::accept(VisiteurForme &v)
{
    v.visit(*this);
}

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
