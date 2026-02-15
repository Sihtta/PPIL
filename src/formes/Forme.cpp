#include "formes/Forme.h"

Forme::Forme(Color c) : couleur(c) {}

void Forme::setCouleur(Color c)
{
    couleur = c;
}

Color Forme::getCouleur() const
{
    return couleur;
}

Groupe *Forme::getParent() const
{
    return parent;
}

void Forme::setParent(Groupe *g)
{
    parent = g;
}