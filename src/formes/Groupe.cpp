#include "formes/Groupe.h"
#include "transformations/Transformation.h"
#include "visitors/VisiteurForme.h"
#include "core/Color.h"
#include <sstream>

Groupe::Groupe(Color col) : Forme(col) {}

void Groupe::ajouter(const std::shared_ptr<Forme> &f)
{
    formes.push_back(f);
}

const std::vector<std::shared_ptr<Forme>> &Groupe::getFormes() const
{
    return formes;
}

double Groupe::aire() const
{
    double total = 0.0;
    for (const auto &f : formes)
    {
        total += f->aire();
    }
    return total;
}

void Groupe::appliquer(Transformation &t) { t.appliquer(*this); }

void Groupe::accept(VisiteurForme &v)
{
    v.visit(*this);
}

std::string Groupe::toString() const
{
    std::ostringstream oss;
    oss << "Groupe(couleur=" << colorToString(couleur) << ", formes=[";
    for (size_t i = 0; i < formes.size(); ++i)
    {
        oss << formes[i]->toString();
        if (i + 1 < formes.size())
            oss << ", ";
    }
    oss << "])";
    return oss.str();
}
