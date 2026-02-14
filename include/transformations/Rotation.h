#ifndef ROTATION_H
#define ROTATION_H

#include "transformations/Transformation.h"
#include "core/Vecteur2D.h"

class Rotation : public Transformation
{
private:
    Vecteur2D centre;
    double angle;

    Vecteur2D rotPoint(const Vecteur2D &p) const;

public:
    Rotation(const Vecteur2D &centre_, double angleRad);

    void visit(Segment &s) override;
    void visit(Cercle &c) override;
    void visit(Triangle &t) override;
    void visit(Polygone &p) override;
    void visit(Groupe &g) override;
};

#endif
