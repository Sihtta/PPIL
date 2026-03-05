#include <iostream>
#include <memory>
#include <vector>
#include <cmath>

#include "core/Vecteur2D.h"
#include "core/Color.h"

#include "formes/Forme.h"
#include "formes/Segment.h"
#include "formes/Cercle.h"
#include "formes/Groupe.h"

#include "network/TcpClient.h"
#include "visitors/VisiteurDessinTCP.h"

// -------- TCP draw ----------
static bool dessinerTCP(Forme &f, int w = 1200, int h = 650)
{
    TcpClient client("127.0.0.1", 12345);
    if (!client.connectToServer())
    {
        std::cout << "[DESSIN] Connexion serveur dessin impossible\n";
        return false;
    }

    client.sendLine("OPEN " + std::to_string(w) + " " + std::to_string(h));
    VisiteurDessinTCP v(client);
    f.accept(v);
    client.sendLine("END");
    client.close();
    return true;
}

// -------- helpers ----------
static void addDot(Groupe &g, const Vecteur2D &p, double r)
{
    g.ajouter(std::make_shared<Cercle>(p, r, Color::Blue));
}

int main()
{
    std::cout << "PPIL - Serpent pointille (simple)\n";

    // Scène globale
    Groupe scene(Color::Black);

    // Axe noir
    scene.ajouter(std::make_shared<Segment>(Vecteur2D(-160, 0), Vecteur2D(260, 0), Color::Black));

    // Serpent (groupe bleu => couleur imposée au dessin si ton visitor est OK)
    auto snake = std::make_shared<Groupe>(Color::Blue);

    // Paramètres "style"
    const double step = 2.5;                               // distance entre points sur x
    const double dotR = 0.8;                               // rayon des points du corps
    const double amp = 45.0;                               // amplitude de l'onde (hauteur)
    const double len = 360.0;                              // longueur du serpent
    const double k = 2.0 * 3.14159265358979323846 / 140.0; // fréquence (période ~ 140)

    // Point de départ (queue) -> vers la droite (tête)
    const double x0 = -130.0;
    const double y0 = -10.0;

    // Corps : y = y0 + amp*sin(k*(x-x0)) * attenuation
    // attenuation donne une queue plus fine / moins ample
    for (double dx = 0.0; dx <= len; dx += step)
    {
        double x = x0 + dx;
        double att = 0.25 + 0.75 * (dx / len); // 0.25 -> 1.0
        double y = y0 + (amp * att) * std::sin(k * dx);
        addDot(*snake, Vecteur2D(x, y), dotR);
    }

    // Tête (au bout)
    const double headX = x0 + len;
    const double headY = y0 + (amp * 1.0) * std::sin(k * len);
    snake->ajouter(std::make_shared<Cercle>(Vecteur2D(headX, headY), 5.0, Color::Blue));

    // Œil (option, petit point)
    addDot(*snake, Vecteur2D(headX + 2.0, headY + 2.0), 0.8);

    // Langue (2 segments en "V")
    snake->ajouter(std::make_shared<Segment>(
        Vecteur2D(headX + 5.0, headY),
        Vecteur2D(headX + 11.0, headY + 3.0),
        Color::Blue));

    snake->ajouter(std::make_shared<Segment>(
        Vecteur2D(headX + 5.0, headY),
        Vecteur2D(headX + 11.0, headY - 3.0),
        Color::Blue));

    // Ajout à la scène + dessin
    scene.ajouter(snake);

    std::cout << "[DESSIN] Envoi au serveur Java...\n";
    dessinerTCP(scene, 1250, 650);

    std::cout << "Fin\n";
    return 0;
}