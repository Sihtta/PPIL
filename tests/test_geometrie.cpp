#include <iostream>
#include <memory>

#include "formes/Groupe.h"
#include "formes/Segment.h"

int main()
{
    auto s = std::make_shared<Segment>(
        Vecteur2D(0, 0),
        Vecteur2D(2, 0),
        Color::Red);

    Groupe g1(Color::Green);
    Groupe g2(Color::Blue);

    std::cout << "Ajout dans g1\n";
    g1.ajouter(s);
    std::cout << "Parent de s: " << (s->getParent() == &g1 ? "g1" : "null") << "\n";

    std::cout << "Tentative ajout dans g2 (doit etre ignore)\n";
    g2.ajouter(s);

    std::cout << "g1 contient " << g1.getFormes().size() << " forme(s)\n";
    std::cout << "g2 contient " << g2.getFormes().size() << " forme(s)\n";

    std::cout << "Retrait de g1\n";
    g1.retirer(s);

    std::cout << "Ajout dans g2 (doit fonctionner)\n";
    g2.ajouter(s);

    std::cout << "g1 contient " << g1.getFormes().size() << " forme(s)\n";
    std::cout << "g2 contient " << g2.getFormes().size() << " forme(s)\n";

    return 0;
}