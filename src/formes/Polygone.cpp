#include "formes/Polygone.h"
#include "transformations/Transformation.h"
#include "visitors/VisiteurForme.h"
#include "core/Color.h"
#include <sstream>

Polygone::Polygone(const std::vector<Vecteur2D> &pts, Color col)
    : Forme(col), points(pts) {}

const std::vector<Vecteur2D> &Polygone::getPoints() const
{
    return points;
}

void Polygone::setPoints(const std::vector<Vecteur2D> &pts)
{
    points = pts;
}

double Polygone::aire() const
{
    if (points.size() < 3)
        return 0.0;

    double aireTotale = 0.0;
    Vecteur2D origine = points[0];

    for (size_t i = 1; i + 1 < points.size(); ++i)
    {
        Vecteur2D ab = points[i] - origine;
        Vecteur2D ac = points[i + 1] - origine;
        double det = ab.det(ac);
        if (det < 0)
            det = -det;
        aireTotale += 0.5 * det;
    }

    return aireTotale;
}

void Polygone::appliquer(Transformation &t) { t.appliquer(*this); }

void Polygone::accept(VisiteurForme &v)
{
    v.visit(*this);
}

std::string Polygone::toString() const
{
    std::ostringstream oss;
    oss << "Polygone(couleur=" << colorToString(couleur) << ", points=[";
    for (size_t i = 0; i < points.size(); ++i)
    {
        oss << points[i].toString();
        if (i + 1 < points.size())
            oss << ", ";
    }
    oss << "])";
    return oss.str();
}
