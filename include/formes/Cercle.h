#ifndef CERCLE_H
#define CERCLE_H

#include "formes/Forme.h"
#include "core/Vecteur2D.h"

class Cercle : public Forme
{
private:
    Vecteur2D centre;
    double rayon;

public:
    Cercle(const Vecteur2D &c, double r, Color col = Color::Black);

    const Vecteur2D &getCentre() const;
    double getRayon() const;

    void setCentre(const Vecteur2D &c);
    void setRayon(double r);

    double aire() const override;
    void appliquer(Transformation &t) override;
    void accept(VisiteurForme &v) override;

    std::string toString() const override;
};

#endif
