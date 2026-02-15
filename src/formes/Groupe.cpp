#include "formes/Groupe.h"
#include "transformations/Transformation.h"
#include "visitors/VisiteurForme.h"
#include "core/Color.h"
#include <sstream>

Groupe::Groupe(Color col) : Forme(col) {}

Groupe::~Groupe()
{
    for (size_t i = 0; i < formes.size(); ++i)
        formes[i]->setParent(nullptr);
}

void Groupe::ajouter(const std::shared_ptr<Forme> &f)
{
    if (!f)
        return;

    if (f->getParent() != nullptr && f->getParent() != this)
        return;

    f->setParent(this);
    formes.push_back(f);
}

void Groupe::retirer(const std::shared_ptr<Forme> &f)
{
    if (!f)
        return;

    for (auto it = formes.begin(); it != formes.end(); ++it)
    {
        if (*it == f)
        {
            (*it)->setParent(nullptr);
            formes.erase(it);
            return;
        }
    }
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
