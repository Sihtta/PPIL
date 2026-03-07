#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <vector>

struct SegmentData
{
    double x1;
    double y1;
    double x2;
    double y2;
};

int main()
{
    std::ifstream in("data/gecko/gecko6PattesJoliesEcaillesCreteTaches_aretesVoronoi.txt");
    std::ofstream out("data/gecko/gecko_voronoi_formes.txt");

    if (!in)
    {
        std::cerr << "Erreur : impossible d'ouvrir le fichier aretesVoronoi\n";
        return 1;
    }

    if (!out)
    {
        std::cerr << "Erreur : impossible de creer le fichier de sortie\n";
        return 1;
    }

    std::string line;
    std::vector<SegmentData> segments;

    // On ignore la première ligne (nombre d'arêtes)
    std::getline(in, line);

    while (std::getline(in, line))
    {
        int id;
        char p1, virgule1, p2, p3, virgule2, p4;
        double x1, y1, x2, y2;

        std::istringstream iss(line);

        if (iss >> id >> p1 >> x1 >> virgule1 >> y1 >> p2 >> p3 >> x2 >> virgule2 >> y2 >> p4)
        {
            segments.push_back({x1, y1, x2, y2});
        }
    }

    if (segments.empty())
    {
        std::cerr << "Erreur : aucun segment lu\n";
        return 1;
    }

    out << "GROUPE green " << segments.size() << "\n";

    for (size_t i = 0; i < segments.size(); ++i)
    {
        out << "SEGMENT green "
            << segments[i].x1 << " " << segments[i].y1 << " "
            << segments[i].x2 << " " << segments[i].y2 << "\n";
    }

    out << "ENDGROUPE\n";

    std::cout << "Conversion terminee : "
              << segments.size()
              << " segments convertis dans data/gecko/gecko_voronoi_formes.txt\n";

    return 0;
}