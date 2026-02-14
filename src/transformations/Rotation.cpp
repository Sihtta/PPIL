#include "transformations/Rotation.h"
#include "formes/Segment.h"
#include "formes/Cercle.h"
#include "formes/Triangle.h"
#include "formes/Polygone.h"
#include "formes/Groupe.h"
#include <cmath>

Rotation::Rotation(const Vecteur2D &centre_, double angleRad)
    : centre(centre_), angle(angleRad) {}

Vecteur2D Rotation::rotPoint(const Vecteur2D &p) const
{
    double x = p.x - centre.x;
    double y = p.y - centre.y;

    double ca = std::cos(angle);
    double sa = std::sin(angle);

    double xr = x * ca - y * sa;
    double yr = x * sa + y * ca;

    return Vecteur2D(xr + centre.x, yr + centre.y);
}

void Rotation::visit(Segment &s)
{
    s.setA(rotPoint(s.getA()));
    s.setB(rotPoint(s.getB()));
}

void Rotation::visit(Cercle &c)
{
    c.setCentre(rotPoint(c.getCentre()));
}

void Rotation::visit(Triangle &t)
{
    t.setA(rotPoint(t.getA()));
    t.setB(rotPoint(t.getB()));
    t.setC(rotPoint(t.getC()));
}

void Rotation::visit(Polygone &p)
{
    std::vector<Vecteur2D> pts = p.getPoints();
    for (size_t i = 0; i < pts.size(); ++i)
        pts[i] = rotPoint(pts[i]);
    p.setPoints(pts);
}

void Rotation::visit(Groupe &g)
{
    const auto &fs = g.getFormes();
    for (size_t i = 0; i < fs.size(); ++i)
        fs[i]->appliquer(*this);
}
