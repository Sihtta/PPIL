#ifndef TRANSLATION_H
#define TRANSLATION_H

#include "transformations/Transformation.h"
#include "core/Vecteur2D.h"

/// Transformation géométrique de translation
class Translation : public Transformation
{
private:
    Vecteur2D v; /// vecteur de translation

public:
    /// Constructeur de la translation
    explicit Translation(const Vecteur2D &v_);

    /// Applique la translation à un segment
    void visit(Segment &s) override;

    /// Applique la translation à un cercle
    void visit(Cercle &c) override;

    /// Applique la translation à un triangle
    void visit(Triangle &t) override;

    /// Applique la translation à un polygone
    void visit(Polygone &p) override;

    /// Applique la translation à un groupe
    void visit(Groupe &g) override;
};

#endif