#ifndef TRANSFORMATION_H
#define TRANSFORMATION_H

#include "visitors/VisiteurForme.h"

class Forme;

/**
 * @class Transformation
 * @brief Classe de base des transformations géométriques.
 *
 * Cette classe hérite de VisiteurForme afin d'appliquer
 * le pattern Visitor aux différentes formes géométriques.
 * Les classes concrètes comme Translation, Rotation et
 * Homothetie redéfinissent les méthodes visit.
 */
class Transformation : public VisiteurForme
{
public:
    /// Destructeur virtuel
    virtual ~Transformation() {}

    /// Applique la transformation à une forme
    void appliquer(Forme &f);
};

#endif