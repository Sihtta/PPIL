#ifndef POLYGONE_H
#define POLYGONE_H

#include "formes/Forme.h"
#include "core/Vecteur2D.h"
#include <vector>

/// Représente un polygone défini par une liste de points
class Polygone : public Forme
{
private:
    std::vector<Vecteur2D> points; /// sommets du polygone

public:
    /// Constructeur du polygone
    Polygone(const std::vector<Vecteur2D> &pts, Color col = Color::Black);

    /// Retourne les points du polygone
    const std::vector<Vecteur2D> &getPoints() const;

    /// Modifie les points du polygone
    void setPoints(const std::vector<Vecteur2D> &pts);

    /// Calcule l'aire du polygone
    double aire() const override;

    /// Applique une transformation au polygone
    void appliquer(Transformation &t) override;

    /// Méthode du pattern Visitor
    void accept(VisiteurForme &v) override;

    /// Convertit le polygone en chaîne de caractères
    std::string toString() const override;
};

#endif