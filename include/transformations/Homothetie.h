#ifndef HOMOTHETIE_H
#define HOMOTHETIE_H

#include "transformations/Transformation.h"
#include "core/Vecteur2D.h"

class Homothetie : public Transformation
{
private:
    Vecteur2D centre;
    double k;

    Vecteur2D homoPoint(const Vecteur2D &p) const;

public:
    Homothetie(const Vecteur2D &centre_, double k_);

    void visit(Segment &s) override;
    void visit(Cercle &c) override;
    void visit(Triangle &t) override;
    void visit(Polygone &p) override;
    void visit(Groupe &g) override;
};

#endif
