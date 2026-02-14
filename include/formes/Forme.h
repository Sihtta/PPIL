#ifndef FORME_H
#define FORME_H

#include "core/Color.h"
#include <string>

class Transformation;
class VisiteurForme;

class Forme
{
protected:
    Color couleur;

public:
    explicit Forme(Color c = Color::Black);
    virtual ~Forme() {}

    void setCouleur(Color c);
    Color getCouleur() const;

    virtual double aire() const = 0;
    virtual void appliquer(Transformation &t) = 0;

    virtual void accept(VisiteurForme &v) = 0;

    virtual std::string toString() const = 0;
};

#endif
