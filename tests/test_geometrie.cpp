#include <iostream>
#include <fstream>
#include <memory>

#include "formes/Groupe.h"
#include "formes/Segment.h"
#include "formes/Cercle.h"
#include "formes/Triangle.h"
#include "formes/Polygone.h"
#include "visitors/VisiteurSauvegarde.h"

int main()
{
    auto s = std::make_shared<Segment>(Vecteur2D(0, 0), Vecteur2D(2, 0), Color::Red);
    auto c = std::make_shared<Cercle>(Vecteur2D(1, 1), 2.0, Color::Blue);

    std::vector<Vecteur2D> pts = {Vecteur2D(0, 0), Vecteur2D(4, 0), Vecteur2D(4, 3), Vecteur2D(0, 3)};
    auto p = std::make_shared<Polygone>(pts, Color::Yellow);

    Groupe g(Color::Green);
    g.ajouter(s);
    g.ajouter(c);
    g.ajouter(p);

    std::ofstream f("save.txt");
    VisiteurSauvegarde vs(f);
    g.accept(vs);
    f.close();

    std::cout << "Sauvegarde dans save.txt\n";
    return 0;
}
