#ifndef VISITEURSAUVEGARDE_H
#define VISITEURSAUVEGARDE_H

#include "visitors/VisiteurForme.h"
#include <ostream>

class VisiteurSauvegarde : public VisiteurForme
{
private:
    std::ostream &out;

public:
    explicit VisiteurSauvegarde(std::ostream &os);

    void visit(Segment &s) override;
    void visit(Cercle &c) override;
    void visit(Triangle &t) override;
    void visit(Polygone &p) override;
    void visit(Groupe &g) override;
};

#endif
