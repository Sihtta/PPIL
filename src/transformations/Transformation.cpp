#include "transformations/Transformation.h"
#include "formes/Forme.h"

// Applique la transformation à la forme via le pattern Visitor
void Transformation::appliquer(Forme &f)
{
    f.accept(*this);
}