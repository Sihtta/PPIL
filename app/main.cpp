#include <iostream>
#include <fstream>
#include <memory>
#include <vector>

#include "core/Vecteur2D.h"
#include "core/Color.h"

#include "chargement/ChargeurForme.h"

#include "formes/Segment.h"
#include "formes/Cercle.h"
#include "formes/Triangle.h"
#include "formes/Polygone.h"
#include "formes/Groupe.h"

#include "transformations/Translation.h"
#include "transformations/Rotation.h"
#include "transformations/Homothetie.h"

#include "visitors/VisiteurSauvegarde.h"

int main()
{
    std::cout << "Projet synthese : tests metier (en C++14)\n\n";

    std::shared_ptr<Forme> seg = std::make_shared<Segment>(
        Vecteur2D(0, 0), Vecteur2D(2, 0), Color::Red);

    std::shared_ptr<Forme> cer = std::make_shared<Cercle>(
        Vecteur2D(1, 1), 2.0, Color::Blue);

    std::shared_ptr<Forme> tri = std::make_shared<Triangle>(
        Vecteur2D(0, 0), Vecteur2D(4, 0), Vecteur2D(0, 3), Color::Green);

    std::vector<Vecteur2D> pts;
    pts.push_back(Vecteur2D(0, 0));
    pts.push_back(Vecteur2D(4, 0));
    pts.push_back(Vecteur2D(4, 3));
    pts.push_back(Vecteur2D(0, 3));
    std::shared_ptr<Forme> pol = std::make_shared<Polygone>(pts, Color::Yellow);

    Groupe g(Color::Cyan);
    g.ajouter(seg);
    g.ajouter(cer);
    g.ajouter(tri);
    g.ajouter(pol);

    std::cout << "Etat initial:\n";
    std::cout << g.toString() << "\n";
    std::cout << "Aire groupe = " << g.aire() << "\n\n";

    Translation t(Vecteur2D(10, 0));
    g.appliquer(t);

    std::cout << "Apres translation (10,0):\n";
    std::cout << g.toString() << "\n";
    std::cout << "Aire groupe = " << g.aire() << "\n\n";

    const double PI = 3.14159265358979323846;
    Rotation r(Vecteur2D(0, 0), PI / 2.0);
    g.appliquer(r);

    std::cout << "Apres rotation 90 deg autour (0,0):\n";
    std::cout << g.toString() << "\n";
    std::cout << "Aire groupe = " << g.aire() << "\n\n";

    Homothetie h(Vecteur2D(0, 0), 2.0);
    g.appliquer(h);

    std::cout << "Apres homothetie k=2 autour (0,0):\n";
    std::cout << g.toString() << "\n";
    std::cout << "Aire groupe = " << g.aire() << "\n\n";

    std::ofstream f("save.txt");
    if (!f)
    {
        std::cout << "Erreur: impossible d'ouvrir save.txt en ecriture\n";
        return 1;
    }

    VisiteurSauvegarde vs(f);
    g.accept(vs);
    f.close();

    std::cout << "Sauvegarde ok -> save.txt\n";

    std::ifstream fin("save.txt");
    if (!fin)
    {
        std::cout << "Erreur: impossible d'ouvrir save.txt en lecture\n";
        return 1;
    }

    ChargeurForme loader;
    std::shared_ptr<Forme> loaded = loader.chargerUne(fin);
    fin.close();

    if (!loaded)
    {
        std::cout << "Erreur: chargement impossible\n";
        return 1;
    }

    std::cout << "\n--- Forme chargee depuis save.txt ---\n";
    std::cout << loaded->toString() << "\n";
    std::cout << "Aire chargee = " << loaded->aire() << "\n";

    std::cout << "\nFin\n";
    return 0;
}
