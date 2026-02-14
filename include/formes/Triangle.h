#ifndef TRIANGLE_H
#define TRIANGLE_H

#include "formes/Forme.h"
#include "core/Vecteur2D.h"

class Triangle : public Forme
{
private:
    Vecteur2D a;
    Vecteur2D b;
    Vecteur2D c;

public:
    Triangle(const Vecteur2D &a_, const Vecteur2D &b_, const Vecteur2D &c_, Color col = Color::Black);

    const Vecteur2D &getA() const;
    const Vecteur2D &getB() const;
    const Vecteur2D &getC() const;

    void setA(const Vecteur2D &p);
    void setB(const Vecteur2D &p);
    void setC(const Vecteur2D &p);

    double aire() const override;
    void appliquer(Transformation &t) override;
    void accept(VisiteurForme &v) override;

    std::string toString() const override;
};

#endif
