#include "visitors/VisiteurSauvegarde.h"
#include "formes/Segment.h"
#include "formes/Cercle.h"
#include "formes/Triangle.h"
#include "formes/Polygone.h"
#include "formes/Groupe.h"
#include "core/Color.h"

VisiteurSauvegarde::VisiteurSauvegarde(std::ostream &os) : out(os) {}

void VisiteurSauvegarde::visit(Segment &s)
{
    out << "SEGMENT " << colorToString(s.getCouleur()) << " "
        << s.getA().x << " " << s.getA().y << " "
        << s.getB().x << " " << s.getB().y << "\n";
}

void VisiteurSauvegarde::visit(Cercle &c)
{
    out << "CERCLE " << colorToString(c.getCouleur()) << " "
        << c.getCentre().x << " " << c.getCentre().y << " "
        << c.getRayon() << "\n";
}

void VisiteurSauvegarde::visit(Triangle &t)
{
    out << "TRIANGLE " << colorToString(t.getCouleur()) << " "
        << t.getA().x << " " << t.getA().y << " "
        << t.getB().x << " " << t.getB().y << " "
        << t.getC().x << " " << t.getC().y << "\n";
}

void VisiteurSauvegarde::visit(Polygone &p)
{
    const auto &pts = p.getPoints();
    out << "POLYGONE " << colorToString(p.getCouleur()) << " " << pts.size();
    for (size_t i = 0; i < pts.size(); ++i)
        out << " " << pts[i].x << " " << pts[i].y;
    out << "\n";
}

void VisiteurSauvegarde::visit(Groupe &g)
{
    const auto &fs = g.getFormes();
    out << "GROUPE " << colorToString(g.getCouleur()) << " " << fs.size() << "\n";
    for (size_t i = 0; i < fs.size(); ++i)
        fs[i]->accept(*this);
    out << "ENDGROUPE\n";
}
