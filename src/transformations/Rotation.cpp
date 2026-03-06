#include "transformations/Rotation.h"
#include "formes/Segment.h"
#include "formes/Cercle.h"
#include "formes/Triangle.h"
#include "formes/Polygone.h"
#include "formes/Groupe.h"
#include <cmath>

// Constructeur : initialise le centre et l'angle de rotation (en radians)
Rotation::Rotation(const Vecteur2D &centre_, double angleRad)
    : centre(centre_), angle(angleRad) {}

// Applique la rotation à un point autour du centre
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

// Applique la rotation aux deux points du segment
void Rotation::visit(Segment &s)
{
    s.setA(rotPoint(s.getA()));
    s.setB(rotPoint(s.getB()));
}

// Applique la rotation au centre du cercle
void Rotation::visit(Cercle &c)
{
    c.setCentre(rotPoint(c.getCentre()));
}

// Applique la rotation aux trois sommets du triangle
void Rotation::visit(Triangle &t)
{
    t.setA(rotPoint(t.getA()));
    t.setB(rotPoint(t.getB()));
    t.setC(rotPoint(t.getC()));
}

// Applique la rotation à tous les points du polygone
void Rotation::visit(Polygone &p)
{
    std::vector<Vecteur2D> pts = p.getPoints();
    for (size_t i = 0; i < pts.size(); ++i)
        pts[i] = rotPoint(pts[i]);
    p.setPoints(pts);
}

// Applique la rotation à toutes les formes du groupe
void Rotation::visit(Groupe &g)
{
    const auto &fs = g.getFormes();
    for (size_t i = 0; i < fs.size(); ++i)
        fs[i]->appliquer(*this);
}