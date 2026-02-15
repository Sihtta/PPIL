#include "visitors/VisiteurDessinTCP.h"
#include "formes/Segment.h"
#include "formes/Cercle.h"
#include "formes/Triangle.h"
#include "formes/Polygone.h"
#include "formes/Groupe.h"
#include "core/Color.h"
#include <sstream>

VisiteurDessinTCP::VisiteurDessinTCP(TcpClient &c)
    : client(c) {}

void VisiteurDessinTCP::visit(Segment &s)
{
    std::ostringstream oss;
    oss << "COLOR " << colorToString(s.getCouleur());
    client.sendLine(oss.str());

    oss.str("");
    oss << "SEGMENT "
        << s.getA().x << " " << s.getA().y << " "
        << s.getB().x << " " << s.getB().y;
    client.sendLine(oss.str());
}

void VisiteurDessinTCP::visit(Cercle &c)
{
    std::ostringstream oss;
    oss << "COLOR " << colorToString(c.getCouleur());
    client.sendLine(oss.str());

    oss.str("");
    oss << "CERCLE "
        << c.getCentre().x << " "
        << c.getCentre().y << " "
        << c.getRayon();
    client.sendLine(oss.str());
}

void VisiteurDessinTCP::visit(Triangle &t)
{
    std::ostringstream oss;
    oss << "COLOR " << colorToString(t.getCouleur());
    client.sendLine(oss.str());

    oss.str("");
    oss << "POLYGON 3 "
        << t.getA().x << " " << t.getA().y << " "
        << t.getB().x << " " << t.getB().y << " "
        << t.getC().x << " " << t.getC().y;
    client.sendLine(oss.str());
}

void VisiteurDessinTCP::visit(Polygone &p)
{
    std::ostringstream oss;
    oss << "COLOR " << colorToString(p.getCouleur());
    client.sendLine(oss.str());

    const auto &pts = p.getPoints();

    oss.str("");
    oss << "POLYGON " << pts.size();
    for (auto &pt : pts)
        oss << " " << pt.x << " " << pt.y;

    client.sendLine(oss.str());
}

void VisiteurDessinTCP::visit(Groupe &g)
{
    for (auto &f : g.getFormes())
        f->accept(*this);
}
