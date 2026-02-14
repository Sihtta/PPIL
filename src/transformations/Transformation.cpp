#include "transformations/Transformation.h"
#include "formes/Forme.h"

void Transformation::appliquer(Forme &f)
{
    f.accept(*this);
}
