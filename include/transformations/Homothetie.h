#ifndef HOMOTHETIE_H
#define HOMOTHETIE_H

#include "transformations/Transformation.h"
#include "core/Vecteur2D.h"

/// Transformation géométrique d'homothétie (agrandissement ou réduction)
class Homothetie : public Transformation
{
private:
    Vecteur2D centre; /// centre de l'homothétie
    double k;         /// rapport d'homothétie

    /// Applique l'homothétie à un point
    Vecteur2D homoPoint(const Vecteur2D &p) const;

public:
    /// Constructeur de l'homothétie
    Homothetie(const Vecteur2D &centre_, double k_);

    /// Applique l'homothétie à un segment
    void visit(Segment &s) override;

    /// Applique l'homothétie à un cercle
    void visit(Cercle &c) override;

    /// Applique l'homothétie à un triangle
    void visit(Triangle &t) override;

    /// Applique l'homothétie à un polygone
    void visit(Polygone &p) override;

    /// Applique l'homothétie à un groupe
    void visit(Groupe &g) override;
};

#endif