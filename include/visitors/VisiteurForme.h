#ifndef VISITEURFORME_H
#define VISITEURFORME_H

class Segment;
class Cercle;
class Triangle;
class Polygone;
class Groupe;

/**
 * @class VisiteurForme
 * @brief Interface du pattern Visitor pour les formes géométriques.
 *
 * Cette interface permet de définir des opérations externes
 * aux classes de formes, comme le dessin ou la sauvegarde,
 * sans modifier les classes concrètes.
 */
class VisiteurForme
{
public:
    /// Destructeur virtuel
    virtual ~VisiteurForme() {}

    /// Visite un segment
    virtual void visit(Segment &s) = 0;

    /// Visite un cercle
    virtual void visit(Cercle &c) = 0;

    /// Visite un triangle
    virtual void visit(Triangle &t) = 0;

    /// Visite un polygone
    virtual void visit(Polygone &p) = 0;

    /// Visite un groupe de formes
    virtual void visit(Groupe &g) = 0;
};

#endif