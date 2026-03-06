#ifndef FORME_H
#define FORME_H

#include "core/Color.h"
#include <string>

/**
 * @class Forme
 * @brief Classe abstraite représentant une forme géométrique.
 *
 * Cette classe sert de base pour toutes les formes de l'application
 * (segment, cercle, triangle, polygone, groupe).
 * Elle définit l'interface commune que toutes les formes doivent implémenter.
 */

class Transformation;
class VisiteurForme;
class Groupe;

class Forme
{
protected:
    /// Couleur de la forme
    Color couleur;

    /// Pointeur vers le groupe parent (nullptr si la forme n'appartient à aucun groupe)
    Groupe *parent = nullptr;

public:
    /**
     * @brief Constructeur de la forme
     * @param c couleur initiale de la forme
     */
    explicit Forme(Color c = Color::Black);

    /// Destructeur virtuel
    virtual ~Forme() {}

    /// Modifie la couleur de la forme
    void setCouleur(Color c);

    /// Retourne la couleur de la forme
    Color getCouleur() const;

    /// Retourne le groupe parent de la forme
    Groupe *getParent() const;

    /// Définit le groupe parent de la forme
    void setParent(Groupe *g);

    /**
     * @brief Calcule l'aire de la forme
     * @return aire de la forme
     */
    virtual double aire() const = 0;

    /**
     * @brief Applique une transformation géométrique à la forme
     * @param t transformation à appliquer
     */
    virtual void appliquer(Transformation &t) = 0;

    /**
     * @brief Méthode du pattern Visitor
     * Permet à un visiteur d'effectuer une opération sur la forme
     */
    virtual void accept(VisiteurForme &v) = 0;

    /**
     * @brief Convertit la forme en chaîne de caractères
     * @return représentation textuelle de la forme
     */
    virtual std::string toString() const = 0;
};

#endif