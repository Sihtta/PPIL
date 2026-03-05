#ifndef VISITEURDESSINTCP_H
#define VISITEURDESSINTCP_H

#include "visitors/VisiteurForme.h"
#include "network/TcpClient.h"
#include "core/Color.h"

#include <vector>

class VisiteurDessinTCP : public VisiteurForme
{
public:
    explicit VisiteurDessinTCP(TcpClient &c);

    void visit(Segment &s) override;
    void visit(Cercle &c) override;
    void visit(Triangle &t) override;
    void visit(Polygone &p) override;
    void visit(Groupe &g) override;

private:
    TcpClient &client;

    std::vector<Color> forcedColorStack;

    Color effectiveColor(Color fallback) const;
    void sendColor(Color c);
};

#endif