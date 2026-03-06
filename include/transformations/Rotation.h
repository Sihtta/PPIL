#ifndef ROTATION_H
#define ROTATION_H

#include "transformations/Transformation.h"
#include "core/Vecteur2D.h"

/// Transformation géométrique de rotation autour d'un point
class Rotation : public Transformation
{
private:
    Vecteur2D centre; /// centre de la rotation
    double angle;     /// angle de rotation en radians

    /// Applique la rotation à un point
    Vecteur2D rotPoint(const Vecteur2D &p) const;

public:
    /// Constructeur de la rotation
    Rotation(const Vecteur2D &centre_, double angleRad);

    /// Applique la rotation à un segment
    void visit(Segment &s) override;

    /// Applique la rotation à un cercle
    void visit(Cercle &c) override;

    /// Applique la rotation à un triangle
    void visit(Triangle &t) override;

    /// Applique la rotation à un polygone
    void visit(Polygone &p) override;

    /// Applique la rotation à un groupe
    void visit(Groupe &g) override;
};

#endif