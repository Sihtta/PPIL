#ifndef GROUPE_H
#define GROUPE_H

#include "formes/Forme.h"
#include <vector>
#include <memory>

class Groupe : public Forme
{
private:
    std::vector<std::shared_ptr<Forme>> formes;

public:
    Groupe(Color col = Color::Black);
    ~Groupe() override;

    bool ajouter(const std::shared_ptr<Forme> &f);
    bool retirer(const std::shared_ptr<Forme> &f);

    const std::vector<std::shared_ptr<Forme>> &getFormes() const;

    double aire() const override;
    void appliquer(Transformation &t) override;
    void accept(VisiteurForme &v) override;

    std::string toString() const override;
};

#endif
