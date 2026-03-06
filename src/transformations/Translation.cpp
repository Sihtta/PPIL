#include "transformations/Translation.h"
#include "formes/Segment.h"
#include "formes/Cercle.h"
#include "formes/Triangle.h"
#include "formes/Polygone.h"
#include "formes/Groupe.h"

// Constructeur : initialise le vecteur de translation
Translation::Translation(const Vecteur2D &v_) : v(v_) {}

// Applique la translation aux deux points du segment
void Translation::visit(Segment &s)
{
    s.setA(s.getA() + v);
    s.setB(s.getB() + v);
}

// Applique la translation au centre du cercle
void Translation::visit(Cercle &c)
{
    c.setCentre(c.getCentre() + v);
}

// Applique la translation aux trois sommets du triangle
void Translation::visit(Triangle &t)
{
    t.setA(t.getA() + v);
    t.setB(t.getB() + v);
    t.setC(t.getC() + v);
}

// Applique la translation à tous les points du polygone
void Translation::visit(Polygone &p)
{
    std::vector<Vecteur2D> pts = p.getPoints();
    for (size_t i = 0; i < pts.size(); ++i)
        pts[i] = pts[i] + v;
    p.setPoints(pts);
}

// Applique la translation à toutes les formes du groupe
void Translation::visit(Groupe &g)
{
    const auto &fs = g.getFormes();
    for (size_t i = 0; i < fs.size(); ++i)
        fs[i]->appliquer(*this);
}