#ifndef SEGMENT_H
#define SEGMENT_H

#include "formes/Forme.h"
#include "core/Vecteur2D.h"

class Segment : public Forme
{
private:
    Vecteur2D a;
    Vecteur2D b;

public:
    Segment(const Vecteur2D &a_, const Vecteur2D &b_, Color c = Color::Black);

    const Vecteur2D &getA() const;
    const Vecteur2D &getB() const;

    void setA(const Vecteur2D &p);
    void setB(const Vecteur2D &p);

    double aire() const override;
    void appliquer(Transformation &t) override;
    void accept(VisiteurForme &v) override;

    std::string toString() const override;
};

#endif
