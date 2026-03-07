#include "transformations/Homothetie.h"
#include "formes/Segment.h"
#include "formes/Cercle.h"
#include "formes/Triangle.h"
#include "formes/Polygone.h"
#include "formes/Groupe.h"
#include "core/Matrice22.h"
#include <vector>

// Constructeur : initialise le centre et le rapport d'homothétie
Homothetie::Homothetie(const Vecteur2D &centre_, double k_)
    : centre(centre_), k(k_) {}

// Applique l'homothétie à un point
Vecteur2D Homothetie::homoPoint(const Vecteur2D &p) const
{
    Matrice22 h = Matrice22::creeHomothetie(k);
    return centre + h * (p - centre);
}

// Applique l'homothétie aux deux points du segment
void Homothetie::visit(Segment &s)
{
    s.setA(homoPoint(s.getA()));
    s.setB(homoPoint(s.getB()));
}

// Applique l'homothétie au cercle
void Homothetie::visit(Cercle &c)
{
    c.setCentre(homoPoint(c.getCentre()));

    double kk = k;
    if (kk < 0)
        kk = -kk;
    if (kk > 0)
        c.setRayon(c.getRayon() * kk);
}

// Applique l'homothétie aux trois sommets du triangle
void Homothetie::visit(Triangle &t)
{
    t.setA(homoPoint(t.getA()));
    t.setB(homoPoint(t.getB()));
    t.setC(homoPoint(t.getC()));
}

// Applique l'homothétie à tous les points du polygone
void Homothetie::visit(Polygone &p)
{
    std::vector<Vecteur2D> pts = p.getPoints();
    for (size_t i = 0; i < pts.size(); ++i)
        pts[i] = homoPoint(pts[i]);
    p.setPoints(pts);
}

// Applique l'homothétie à toutes les formes du groupe
void Homothetie::visit(Groupe &g)
{
    const auto &fs = g.getFormes();
    for (size_t i = 0; i < fs.size(); ++i)
        fs[i]->appliquer(*this);
}