#ifndef GROUPE_H
#define GROUPE_H

#include "formes/Forme.h"
#include <vector>
#include <memory>

/// Représente un groupe de formes géométriques
class Groupe : public Forme
{
private:
    std::vector<std::shared_ptr<Forme>> formes; /// formes contenues dans le groupe

public:
    /// Constructeur du groupe
    Groupe(Color col = Color::Black);

    /// Destructeur
    ~Groupe() override;

    /// Ajoute une forme au groupe
    bool ajouter(const std::shared_ptr<Forme> &f);

    /// Retire une forme du groupe
    bool retirer(const std::shared_ptr<Forme> &f);

    /// Retourne les formes du groupe
    const std::vector<std::shared_ptr<Forme>> &getFormes() const;

    /// Calcule l'aire totale du groupe
    double aire() const override;

    /// Applique une transformation à toutes les formes du groupe
    void appliquer(Transformation &t) override;

    /// Méthode du pattern Visitor
    void accept(VisiteurForme &v) override;

    /// Convertit le groupe en chaîne de caractères
    std::string toString() const override;
};

#endif