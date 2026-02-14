#include "transformations/Homothetie.h"
#include "formes/Segment.h"
#include "formes/Cercle.h"
#include "formes/Triangle.h"
#include "formes/Polygone.h"
#include "formes/Groupe.h"

Homothetie::Homothetie(const Vecteur2D &centre_, double k_)
    : centre(centre_), k(k_) {}

Vecteur2D Homothetie::homoPoint(const Vecteur2D &p) const
{
    Vecteur2D d = p - centre;
    return centre + d * k;
}

void Homothetie::visit(Segment &s)
{
    s.setA(homoPoint(s.getA()));
    s.setB(homoPoint(s.getB()));
}

void Homothetie::visit(Cercle &c)
{
    c.setCentre(homoPoint(c.getCentre()));

    double kk = k;
    if (kk < 0)
        kk = -kk;
    if (kk > 0)
        c.setRayon(c.getRayon() * kk);
}

void Homothetie::visit(Triangle &t)
{
    t.setA(homoPoint(t.getA()));
    t.setB(homoPoint(t.getB()));
    t.setC(homoPoint(t.getC()));
}

void Homothetie::visit(Polygone &p)
{
    std::vector<Vecteur2D> pts = p.getPoints();
    for (size_t i = 0; i < pts.size(); ++i)
        pts[i] = homoPoint(pts[i]);
    p.setPoints(pts);
}

void Homothetie::visit(Groupe &g)
{
    const auto &fs = g.getFormes();
    for (size_t i = 0; i < fs.size(); ++i)
        fs[i]->appliquer(*this);
}
