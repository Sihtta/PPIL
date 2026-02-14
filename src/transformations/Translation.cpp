#include "transformations/Translation.h"
#include "formes/Segment.h"
#include "formes/Cercle.h"
#include "formes/Triangle.h"
#include "formes/Polygone.h"
#include "formes/Groupe.h"

Translation::Translation(const Vecteur2D &v_) : v(v_) {}

void Translation::visit(Segment &s)
{
    s.setA(s.getA() + v);
    s.setB(s.getB() + v);
}

void Translation::visit(Cercle &c)
{
    c.setCentre(c.getCentre() + v);
}

void Translation::visit(Triangle &t)
{
    t.setA(t.getA() + v);
    t.setB(t.getB() + v);
    t.setC(t.getC() + v);
}

void Translation::visit(Polygone &p)
{
    std::vector<Vecteur2D> pts = p.getPoints();
    for (size_t i = 0; i < pts.size(); ++i)
        pts[i] = pts[i] + v;
    p.setPoints(pts);
}

void Translation::visit(Groupe &g)
{
    const auto &fs = g.getFormes();
    for (size_t i = 0; i < fs.size(); ++i)
        fs[i]->appliquer(*this);
}
