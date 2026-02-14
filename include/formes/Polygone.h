#ifndef POLYGONE_H
#define POLYGONE_H

#include "formes/Forme.h"
#include "core/Vecteur2D.h"
#include <vector>

class Polygone : public Forme
{
private:
    std::vector<Vecteur2D> points;

public:
    Polygone(const std::vector<Vecteur2D> &pts, Color col = Color::Black);

    const std::vector<Vecteur2D> &getPoints() const;
    void setPoints(const std::vector<Vecteur2D> &pts);

    double aire() const override;
    void appliquer(Transformation &t) override;
    void accept(VisiteurForme &v) override;

    std::string toString() const override;
};

#endif
