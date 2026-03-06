#include "formes/Groupe.h"
#include "transformations/Transformation.h"
#include "visitors/VisiteurForme.h"
#include "core/Color.h"
#include <sstream>

// Vérifie récursivement si un groupe contient un autre groupe
// Permet d'éviter de créer des cycles dans la hiérarchie des groupes
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

// Constructeur du groupe
Groupe::Groupe(Color col) : Forme(col) {}

// Destructeur : détache les formes du groupe
Groupe::~Groupe()
{
    for (size_t i = 0; i < formes.size(); ++i)
        formes[i]->setParent(nullptr);
}

// Ajoute une forme au groupe en vérifiant plusieurs contraintes
bool Groupe::ajouter(const std::shared_ptr<Forme> &f)
{
    if (!f)
        return false;

    // Empêche l'ajout de doublons
    for (const auto &x : formes)
    {
        if (x == f)
            return false;
    }

    // Une forme ne peut appartenir qu'à un seul groupe
    if (f->getParent() != nullptr && f->getParent() != this)
        return false;

    // Empêche qu'un groupe se contienne lui-même
    if (f.get() == this)
        return false;

    // Vérifie qu'il n'y aura pas de cycle de groupes
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

// Retire une forme du groupe
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

// Retourne la liste des formes du groupe
const std::vector<std::shared_ptr<Forme>> &Groupe::getFormes() const
{
    return formes;
}

// Calcule l'aire totale du groupe (somme des aires des formes)
double Groupe::aire() const
{
    double total = 0.0;
    for (const auto &f : formes)
        total += f->aire();
    return total;
}

// Applique une transformation au groupe
void Groupe::appliquer(Transformation &t) { t.appliquer(*this); }

// Méthode du pattern Visitor
void Groupe::accept(VisiteurForme &v)
{
    v.visit(*this);
}

// Retourne une représentation textuelle du groupe et de ses formes
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