#ifndef FORME_H
#define FORME_H

#include "core/Color.h"
#include <string>

class Transformation;
class VisiteurForme;
class Groupe;

class Forme
{
protected:
    Color couleur;
    Groupe *parent = nullptr;

public:
    explicit Forme(Color c = Color::Black);
    virtual ~Forme() {}

    void setCouleur(Color c);
    Color getCouleur() const;

    Groupe *getParent() const;
    void setParent(Groupe *g);

    virtual double aire() const = 0;
    virtual void appliquer(Transformation &t) = 0;

    virtual void accept(VisiteurForme &v) = 0;

    virtual std::string toString() const = 0;
};

#endif
