#ifndef CERCLE_H
#define CERCLE_H

#include "formes/Forme.h"
#include "core/Vecteur2D.h"

/// Représente un cercle défini par un centre et un rayon
class Cercle : public Forme
{
private:
    Vecteur2D centre; /// centre du cercle
    double rayon;     /// rayon du cercle

public:
    /// Constructeur du cercle
    Cercle(const Vecteur2D &c, double r, Color col = Color::Black);

    /// Retourne le centre du cercle
    const Vecteur2D &getCentre() const;

    /// Retourne le rayon du cercle
    double getRayon() const;

    /// Définit le centre du cercle
    void setCentre(const Vecteur2D &c);

    /// Définit le rayon du cercle
    void setRayon(double r);

    /// Calcule l'aire du cercle
    double aire() const override;

    /// Applique une transformation géométrique au cercle
    void appliquer(Transformation &t) override;

    /// Méthode du pattern Visitor
    void accept(VisiteurForme &v) override;

    /// Convertit le cercle en chaîne de caractères
    std::string toString() const override;
};

#endif