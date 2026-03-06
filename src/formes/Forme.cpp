#include "formes/Forme.h"

// Constructeur : initialise la forme avec une couleur donnée
Forme::Forme(Color c) : couleur(c) {}

// Définit la couleur de la forme
void Forme::setCouleur(Color c)
{
    couleur = c;
}

// Retourne la couleur actuelle de la forme
Color Forme::getCouleur() const
{
    return couleur;
}

// Retourne le groupe parent de la forme
// nullptr si la forme n'appartient à aucun groupe
Groupe *Forme::getParent() const
{
    return parent;
}

// Définit le groupe parent de la forme
void Forme::setParent(Groupe *g)
{
    parent = g;
}