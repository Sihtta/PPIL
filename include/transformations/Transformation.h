#ifndef TRANSFORMATION_H
#define TRANSFORMATION_H

#include "visitors/VisiteurForme.h"

class Forme;

class Transformation : public VisiteurForme
{
public:
    virtual ~Transformation() {}
    void appliquer(Forme &f);
};

#endif
