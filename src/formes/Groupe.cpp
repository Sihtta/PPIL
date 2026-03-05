#include "formes/Groupe.h"
#include "transformations/Transformation.h"
#include "visitors/VisiteurForme.h"
#include "core/Color.h"
#include <sstream>

static bool contientGroupe(const Groupe *racine, const Groupe *cible)
{
    if (!racine || !cible)
        return false;

    if (racine == cible)
        return true;

    const auto &enfants = racine->getFormes();
    for (const auto &f : enfants)
    {
        const Groupe *g = dynamic_cast<const Groupe *>(f.get());
        if (g)
        {
            if (contientGroupe(g, cible))
                return true;
        }
    }
    return false;
}

Groupe::Groupe(Color col) : Forme(col) {}

Groupe::~Groupe()
{
    for (size_t i = 0; i < formes.size(); ++i)
        formes[i]->setParent(nullptr);
}

bool Groupe::ajouter(const std::shared_ptr<Forme> &f)
{
    if (!f)
        return false;

    for (const auto &x : formes)
    {
        if (x == f)
            return false;
    }

    if (f->getParent() != nullptr && f->getParent() != this)
        return false;

    if (f.get() == this)
        return false;

    const Groupe *fg = dynamic_cast<const Groupe *>(f.get());
    if (fg)
    {
        if (contientGroupe(fg, this))
            return false;
    }

    f->setParent(this);
    formes.push_back(f);

    return true;
}

bool Groupe::retirer(const std::shared_ptr<Forme> &f)
{
    if (!f)
        return false;

    for (auto it = formes.begin(); it != formes.end(); ++it)
    {
        if (*it == f)
        {
            (*it)->setParent(nullptr);
            formes.erase(it);
            return true;
        }
    }
    return false;
}

const std::vector<std::shared_ptr<Forme>> &Groupe::getFormes() const
{
    return formes;
}

double Groupe::aire() const
{
    double total = 0.0;
    for (const auto &f : formes)
        total += f->aire();
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