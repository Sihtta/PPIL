#ifndef VISITEURSAUVEGARDE_H
#define VISITEURSAUVEGARDE_H

#include "visitors/VisiteurForme.h"
#include <ostream>

/// Visiteur chargé de sauvegarder les formes dans un flux texte
class VisiteurSauvegarde : public VisiteurForme
{
private:
    std::ostream &out; /// flux de sortie utilisé pour la sauvegarde

public:
    /// Constructeur : initialise le flux de sortie
    explicit VisiteurSauvegarde(std::ostream &os);

    /// Sauvegarde un segment
    void visit(Segment &s) override;

    /// Sauvegarde un cercle
    void visit(Cercle &c) override;

    /// Sauvegarde un triangle
    void visit(Triangle &t) override;

    /// Sauvegarde un polygone
    void visit(Polygone &p) override;

    /// Sauvegarde un groupe de formes
    void visit(Groupe &g) override;
};

#endif