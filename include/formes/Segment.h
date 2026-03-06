#ifndef SEGMENT_H
#define SEGMENT_H

#include "formes/Forme.h"
#include "core/Vecteur2D.h"

/// Représente un segment défini par deux points
class Segment : public Forme
{
private:
    Vecteur2D a; /// premier point du segment
    Vecteur2D b; /// second point du segment

public:
    /// Constructeur du segment
    Segment(const Vecteur2D &a_, const Vecteur2D &b_, Color c = Color::Black);

    /// Retourne le premier point
    const Vecteur2D &getA() const;

    /// Retourne le second point
    const Vecteur2D &getB() const;

    /// Modifie le premier point
    void setA(const Vecteur2D &p);

    /// Modifie le second point
    void setB(const Vecteur2D &p);

    /// Aire du segment (toujours 0)
    double aire() const override;

    /// Applique une transformation au segment
    void appliquer(Transformation &t) override;

    /// Méthode du pattern Visitor
    void accept(VisiteurForme &v) override;

    /// Convertit le segment en chaîne de caractères
    std::string toString() const override;
};

#endif