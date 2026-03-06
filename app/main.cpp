#include <iostream>
#include <fstream>
#include <memory>

#include "chargement/ChargeurForme.h"
#include "formes/Forme.h"

#include "network/TcpClient.h"
#include "visitors/VisiteurDessinTCP.h"

int main()
{
    std::cout << "=== Test chargement fichier ===\n";

    std::ifstream in("save_roundtrip.txt");

    if (!in)
    {
        std::cerr << "Erreur ouverture fichier save_roundtrip.txt\n";
        return 1;
    }

    ChargeurForme loader;

    std::shared_ptr<Forme> forme = loader.chargerUne(in);

    if (!forme)
    {
        std::cerr << "Echec chargement forme\n";
        return 1;
    }

    std::cout << "[FORME CHARGEE]\n";
    std::cout << forme->toString() << "\n";

    std::cout << "\n[DESSIN]\n";

    TcpClient client("127.0.0.1", 12345);
    if (!client.connectToServer())
    {
        std::cerr << "Impossible de se connecter au serveur Java\n";
        return 1;
    }

    client.sendLine("OPEN 1250 650");

    VisiteurDessinTCP dessin(client);

    forme->accept(dessin);

    client.close();

    std::cout << "Dessin envoye au serveur.\n";

    return 0;
}