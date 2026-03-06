#include "chargement/ChargeurForme.h"

#include "formes/Forme.h"
#include "formes/Segment.h"
#include "formes/Cercle.h"
#include "formes/Triangle.h"
#include "formes/Polygone.h"
#include "formes/Groupe.h"

#include "core/Color.h"
#include "core/Vecteur2D.h"

#include <sstream>
#include <vector>

// Passe le traitement au handler suivant de la chaîne
bool ChargeurForme::Handler::pass(const std::string &line,
                                  std::istream &in,
                                  std::shared_ptr<Forme> &out,
                                  ChargeurForme &loader)
{
    if (!next)
        return false;
    return next->handle(line, in, out, loader);
}

// Extrait le premier mot de la ligne pour identifier le type de forme
static std::string firstToken(const std::string &line)
{
    std::istringstream iss(line);
    std::string tok;
    iss >> tok;
    return tok;
}

// Handler chargé de reconnaître et construire un segment
class SegmentHandler : public ChargeurForme::Handler
{
public:
    bool handle(const std::string &line,
                std::istream &in,
                std::shared_ptr<Forme> &out,
                ChargeurForme &loader) override
    {
        (void)in;
        (void)loader;
        if (firstToken(line) != "SEGMENT")
            return pass(line, in, out, loader);

        std::istringstream iss(line);
        std::string tag, col;
        double ax, ay, bx, by;
        iss >> tag >> col >> ax >> ay >> bx >> by;

        out = std::make_shared<Segment>(Vecteur2D(ax, ay), Vecteur2D(bx, by), stringToColor(col));
        return true;
    }
};

// Handler chargé de reconnaître et construire un cercle
class CercleHandler : public ChargeurForme::Handler
{
public:
    bool handle(const std::string &line,
                std::istream &in,
                std::shared_ptr<Forme> &out,
                ChargeurForme &loader) override
    {
        (void)in;
        (void)loader;
        if (firstToken(line) != "CERCLE")
            return pass(line, in, out, loader);

        std::istringstream iss(line);
        std::string tag, col;
        double cx, cy, r;
        iss >> tag >> col >> cx >> cy >> r;

        out = std::make_shared<Cercle>(Vecteur2D(cx, cy), r, stringToColor(col));
        return true;
    }
};

// Handler chargé de reconnaître et construire un triangle
class TriangleHandler : public ChargeurForme::Handler
{
public:
    bool handle(const std::string &line,
                std::istream &in,
                std::shared_ptr<Forme> &out,
                ChargeurForme &loader) override
    {
        (void)in;
        (void)loader;
        if (firstToken(line) != "TRIANGLE")
            return pass(line, in, out, loader);

        std::istringstream iss(line);
        std::string tag, col;
        double ax, ay, bx, by, cx, cy;
        iss >> tag >> col >> ax >> ay >> bx >> by >> cx >> cy;

        out = std::make_shared<Triangle>(
            Vecteur2D(ax, ay),
            Vecteur2D(bx, by),
            Vecteur2D(cx, cy),
            stringToColor(col));
        return true;
    }
};

// Handler chargé de reconnaître et construire un polygone
class PolygoneHandler : public ChargeurForme::Handler
{
public:
    bool handle(const std::string &line,
                std::istream &in,
                std::shared_ptr<Forme> &out,
                ChargeurForme &loader) override
    {
        (void)in;
        (void)loader;
        if (firstToken(line) != "POLYGONE")
            return pass(line, in, out, loader);

        std::istringstream iss(line);
        std::string tag, col;
        size_t n;
        iss >> tag >> col >> n;

        std::vector<Vecteur2D> pts;
        for (size_t i = 0; i < n; ++i)
        {
            double x, y;
            iss >> x >> y;
            pts.push_back(Vecteur2D(x, y));
        }

        out = std::make_shared<Polygone>(pts, stringToColor(col));
        return true;
    }
};

// Handler chargé de reconnaître et construire un groupe
class GroupeHandler : public ChargeurForme::Handler
{
public:
    bool handle(const std::string &line,
                std::istream &in,
                std::shared_ptr<Forme> &out,
                ChargeurForme &loader) override
    {
        if (firstToken(line) != "GROUPE")
            return pass(line, in, out, loader);

        std::istringstream iss(line);
        std::string tag, col;
        size_t nb;
        iss >> tag >> col >> nb;

        // Création du groupe puis chargement récursif de ses sous-formes
        std::shared_ptr<Groupe> g = std::make_shared<Groupe>(stringToColor(col));

        for (size_t i = 0; i < nb; ++i)
        {
            std::shared_ptr<Forme> child = loader.chargerUne(in);
            if (child)
                g->ajouter(child);
        }

        // Lecture éventuelle de la ligne de fin du groupe
        std::string endLine;
        if (!ChargeurForme::lireLigneUtile(in, endLine))
        {
            out = g;
            return true;
        }

        if (firstToken(endLine) != "ENDGROUPE")
        {
            out = g;
            return true;
        }

        out = g;
        return true;
    }
};

// Construit la chaîne de responsabilité des handlers de chargement
ChargeurForme::ChargeurForme()
{
    hSegment.reset(new SegmentHandler());
    hCercle.reset(new CercleHandler());
    hTriangle.reset(new TriangleHandler());
    hPolygone.reset(new PolygoneHandler());
    hGroupe.reset(new GroupeHandler());

    hSegment->setNext(hCercle.get());
    hCercle->setNext(hTriangle.get());
    hTriangle->setNext(hPolygone.get());
    hPolygone->setNext(hGroupe.get());

    head = hSegment.get();
}

// Lit la prochaine ligne non vide du flux
bool ChargeurForme::lireLigneUtile(std::istream &in, std::string &line)
{
    while (std::getline(in, line))
    {
        if (!line.empty())
            return true;
    }
    return false;
}

// Charge une forme en laissant la chaîne déterminer son type
std::shared_ptr<Forme> ChargeurForme::chargerUne(std::istream &in)
{
    std::string line;
    if (!lireLigneUtile(in, line))
        return nullptr;

    std::shared_ptr<Forme> f;
    if (!head->handle(line, in, f, *this))
        return nullptr;
    return f;
}