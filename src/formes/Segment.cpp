#include "formes/Segment.h"
#include "transformations/Transformation.h"
#include "visitors/VisiteurForme.h"
#include "core/Color.h"
#include <sstream>

Segment::Segment(const Vecteur2D &a_, const Vecteur2D &b_, Color c)
    : Forme(c), a(a_), b(b_) {}

const Vecteur2D &Segment::getA() const { return a; }
const Vecteur2D &Segment::getB() const { return b; }

void Segment::setA(const Vecteur2D &p) { a = p; }
void Segment::setB(const Vecteur2D &p) { b = p; }

double Segment::aire() const { return 0.0; }

void Segment::appliquer(Transformation &t)
{
    t.appliquer(*this);
}

void Segment::accept(VisiteurForme &v)
{
    v.visit(*this);
}

std::string Segment::toString() const
{
    std::ostringstream oss;
    oss << "Segment(couleur=" << colorToString(couleur)
        << ", a=" << a.toString()
        << ", b=" << b.toString()
        << ")";
    return oss.str();
}
