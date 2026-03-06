#ifndef VISITEURDESSINTCP_H
#define VISITEURDESSINTCP_H

#include "visitors/VisiteurForme.h"
#include "network/TcpClient.h"
#include "core/Color.h"

#include <vector>

/// Visiteur chargé d'envoyer les commandes de dessin au serveur Java via TCP
class VisiteurDessinTCP : public VisiteurForme
{
public:
    /// Constructeur : utilise un client TCP pour envoyer les commandes
    explicit VisiteurDessinTCP(TcpClient &c);

    /// Dessine un segment
    void visit(Segment &s) override;

    /// Dessine un cercle
    void visit(Cercle &c) override;

    /// Dessine un triangle
    void visit(Triangle &t) override;

    /// Dessine un polygone
    void visit(Polygone &p) override;

    /// Dessine un groupe de formes
    void visit(Groupe &g) override;

private:
    TcpClient &client; /// client TCP utilisé pour envoyer les commandes

    std::vector<Color> forcedColorStack; /// pile des couleurs forcées pour les groupes

    /// Détermine la couleur effective à utiliser
    Color effectiveColor(Color fallback) const;

    /// Envoie la commande de changement de couleur au serveur
    void sendColor(Color c);
};

#endif