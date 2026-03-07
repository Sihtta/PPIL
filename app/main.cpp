#include <iostream>
#include <fstream>
#include <memory>
#include <vector>
#include <cmath>

#include "core/Vecteur2D.h"
#include "core/Color.h"

#include "formes/Forme.h"
#include "formes/Segment.h"
#include "formes/Cercle.h"
#include "formes/Triangle.h"
#include "formes/Polygone.h"
#include "formes/Groupe.h"

#include "transformations/Translation.h"
#include "transformations/Rotation.h"
#include "transformations/Homothetie.h"

#include "visitors/VisiteurSauvegarde.h"
#include "visitors/VisiteurDessinTCP.h"

#include "chargement/ChargeurForme.h"
#include "network/TcpClient.h"
#include <cmath>

using namespace std;
const double PI = 3.14159265358979323846;
// Dessin d'une forme via le serveur Java
static void dessiner(Forme &f, const std::string &host = "127.0.0.1", int port = 12345)
{
    TcpClient client(host, port);

    if (!client.connectToServer())
    {
        cerr << "Erreur : impossible de se connecter au serveur Java de dessin." << endl;
        return;
    }

    // Adapter ces commandes si votre protocole exact diffère
    client.sendLine("OPEN 900 700");

    VisiteurDessinTCP visiteur(client);
    f.accept(visiteur);

    client.sendLine("END");
    client.close();
}

// Sauvegarde d'une forme dans un flux texte
static void sauvegarder(Forme &f, std::ostream &os)
{
    VisiteurSauvegarde visiteur(os);
    f.accept(visiteur);
    os << '\n';
}

// Chargement de toutes les formes d'un fichier
static vector<shared_ptr<Forme>> chargerToutes(const std::string &nomFichier)
{
    vector<shared_ptr<Forme>> formes;
    ifstream ifs(nomFichier);

    if (!ifs)
    {
        cerr << "Erreur : impossible d'ouvrir le fichier " << nomFichier << endl;
        return formes;
    }

    ChargeurForme chargeur;
    while (true)
    {
        shared_ptr<Forme> f = chargeur.chargerUne(ifs);
        if (!f)
            break;
        formes.push_back(f);
    }

    return formes;
}

int main()
{
    cout << "===== TEST DU PROJET DE SYNTHESE =====" << endl;

    // ------------------------------------------------------------
    // 1) Creation des formes simples (paragraphe 2)
    // ------------------------------------------------------------
    auto segment = make_shared<Segment>(
        Vecteur2D(20, 20),
        Vecteur2D(180, 20),
        Color::Red);

    auto cercle = make_shared<Cercle>(
        Vecteur2D(250, 120),
        50,
        Color::Blue);

    auto triangle = make_shared<Triangle>(
        Vecteur2D(80, 220),
        Vecteur2D(140, 320),
        Vecteur2D(20, 320),
        Color::Green);

    vector<Vecteur2D> pts = {
        Vecteur2D(300, 250),
        Vecteur2D(380, 250),
        Vecteur2D(420, 320),
        Vecteur2D(340, 380),
        Vecteur2D(280, 320)};
    auto polygone = make_shared<Polygone>(pts, Color::Yellow);

    cout << "\n--- Formes simples creees ---" << endl;
    cout << segment->toString() << endl;
    cout << cercle->toString() << endl;
    cout << triangle->toString() << endl;
    cout << polygone->toString() << endl;

    // ------------------------------------------------------------
    // 2) Creation d'un groupe (paragraphe 2)
    // Le groupe est une forme composee contenant plusieurs formes.
    // ------------------------------------------------------------
    auto groupe = make_shared<Groupe>(Color::Cyan);
    groupe->ajouter(segment);
    groupe->ajouter(cercle);
    groupe->ajouter(triangle);
    groupe->ajouter(polygone);

    cout << "\n--- Groupe cree ---" << endl;
    cout << groupe->toString() << endl;

    // ------------------------------------------------------------
    // 3) Calcul des aires (paragraphe 6)
    // ------------------------------------------------------------
    cout << "\n--- Aires avant transformations ---" << endl;
    cout << "Aire cercle   : " << cercle->aire() << endl;
    cout << "Aire triangle : " << triangle->aire() << endl;
    cout << "Aire polygone : " << polygone->aire() << endl;
    cout << "Aire groupe   : " << groupe->aire() << endl;

    // ------------------------------------------------------------
    // 4) Transformations geometriques (paragraphe 3)
    // On les applique au groupe pour montrer qu'elles se propagent
    // a toutes les formes qu'il contient.
    // ------------------------------------------------------------
    Translation translation(Vecteur2D(50, 30));
    Rotation rotation(Vecteur2D(250, 200), PI / 6.0);
    Homothetie homothetie(Vecteur2D(250, 200), 1.2); // agrandissement

    cout << "\n--- Application d'une translation au groupe ---" << endl;
    groupe->appliquer(translation);
    cout << groupe->toString() << endl;

    cout << "\n--- Application d'une rotation au groupe ---" << endl;
    groupe->appliquer(rotation);
    cout << groupe->toString() << endl;

    cout << "\n--- Application d'une homothetie au groupe ---" << endl;
    groupe->appliquer(homothetie);
    cout << groupe->toString() << endl;

    cout << "\n--- Aires apres transformations ---" << endl;
    cout << "Aire groupe : " << groupe->aire() << endl;

    // ------------------------------------------------------------
    // 5) Sauvegarde dans un fichier texte (paragraphe 5)
    // ------------------------------------------------------------
    const string fichier = "formes.txt";
    {
        ofstream ofs(fichier);
        if (!ofs)
        {
            cerr << "Erreur : impossible de creer le fichier " << fichier << endl;
            return 1;
        }

        // On sauvegarde ici le groupe complet
        sauvegarder(*groupe, ofs);
    }

    cout << "\n--- Sauvegarde effectuee dans " << fichier << " ---" << endl;

    // ------------------------------------------------------------
    // 6) Chargement depuis le fichier texte (paragraphe 5)
    // ------------------------------------------------------------
    vector<shared_ptr<Forme>> formesChargees = chargerToutes(fichier);

    cout << "\n--- Formes chargees depuis le fichier ---" << endl;
    for (size_t i = 0; i < formesChargees.size(); ++i)
    {
        cout << "[" << i << "] " << formesChargees[i]->toString() << endl;
        cout << "    Aire : " << formesChargees[i]->aire() << endl;
    }

    // ------------------------------------------------------------
    // 7) Dessin via le serveur Java (paragraphe 4)
    // ------------------------------------------------------------
    cout << "\n--- Dessin du groupe courant ---" << endl;
    dessiner(*groupe);

    if (!formesChargees.empty())
    {
        cout << "\n--- Dessin d'une forme simple avant groupement ---" << endl;
        dessiner(*cercle);
    }

    cout << "\n===== FIN DES TESTS =====" << endl;
    return 0;
}