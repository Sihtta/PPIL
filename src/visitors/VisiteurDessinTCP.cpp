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

Color VisiteurDessinTCP::effectiveColor(Color fallback) const
{
    if (!forcedColorStack.empty())
        return forcedColorStack.back();
    return fallback;
}

void VisiteurDessinTCP::sendColor(Color c)
{
    std::ostringstream oss;
    oss << "COLOR " << colorToString(c);
    client.sendLine(oss.str());
}

void VisiteurDessinTCP::visit(Segment &s)
{
    sendColor(effectiveColor(s.getCouleur()));

    std::ostringstream oss;
    oss << "SEGMENT "
        << s.getA().x << " " << s.getA().y << " "
        << s.getB().x << " " << s.getB().y;
    client.sendLine(oss.str());
}

void VisiteurDessinTCP::visit(Cercle &c)
{
    sendColor(effectiveColor(c.getCouleur()));

    std::ostringstream oss;
    oss << "CERCLE "
        << c.getCentre().x << " "
        << c.getCentre().y << " "
        << c.getRayon();
    client.sendLine(oss.str());
}

void VisiteurDessinTCP::visit(Triangle &t)
{
    sendColor(effectiveColor(t.getCouleur()));

    std::ostringstream oss;
    oss << "POLYGON 3 "
        << t.getA().x << " " << t.getA().y << " "
        << t.getB().x << " " << t.getB().y << " "
        << t.getC().x << " " << t.getC().y;
    client.sendLine(oss.str());
}

void VisiteurDessinTCP::visit(Polygone &p)
{
    sendColor(effectiveColor(p.getCouleur()));

    const auto &pts = p.getPoints();

    std::ostringstream oss;
    oss << "POLYGON " << pts.size();
    for (const auto &pt : pts)
        oss << " " << pt.x << " " << pt.y;

    client.sendLine(oss.str());
}

void VisiteurDessinTCP::visit(Groupe &g)
{
    forcedColorStack.push_back(g.getCouleur());

    for (auto &f : g.getFormes())
        f->accept(*this);

    forcedColorStack.pop_back();
}