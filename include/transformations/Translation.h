#ifndef TRANSLATION_H
#define TRANSLATION_H

#include "transformations/Transformation.h"
#include "core/Vecteur2D.h"

class Translation : public Transformation
{
private:
    Vecteur2D v;

public:
    explicit Translation(const Vecteur2D &v_);

    void visit(Segment &s) override;
    void visit(Cercle &c) override;
    void visit(Triangle &t) override;
    void visit(Polygone &p) override;
    void visit(Groupe &g) override;
};

#endif
