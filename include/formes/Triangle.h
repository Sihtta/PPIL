#ifndef TRIANGLE_H
#define TRIANGLE_H

#include "formes/Forme.h"
#include "core/Vecteur2D.h"

/// Représente un triangle défini par trois points
class Triangle : public Forme
{
private:
    Vecteur2D a; /// premier sommet
    Vecteur2D b; /// deuxième sommet
    Vecteur2D c; /// troisième sommet

public:
    /// Constructeur du triangle
    Triangle(const Vecteur2D &a_, const Vecteur2D &b_, const Vecteur2D &c_, Color col = Color::Black);

    /// Retourne le premier sommet
    const Vecteur2D &getA() const;

    /// Retourne le deuxième sommet
    const Vecteur2D &getB() const;

    /// Retourne le troisième sommet
    const Vecteur2D &getC() const;

    /// Modifie le premier sommet
    void setA(const Vecteur2D &p);

    /// Modifie le deuxième sommet
    void setB(const Vecteur2D &p);

    /// Modifie le troisième sommet
    void setC(const Vecteur2D &p);

    /// Calcule l'aire du triangle
    double aire() const override;

    /// Applique une transformation au triangle
    void appliquer(Transformation &t) override;

    /// Méthode du pattern Visitor
    void accept(VisiteurForme &v) override;

    /// Convertit le triangle en chaîne de caractères
    std::string toString() const override;
};

#endif