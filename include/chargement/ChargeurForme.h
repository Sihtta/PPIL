#ifndef CHARGEURFORME_H
#define CHARGEURFORME_H

#include <istream>
#include <memory>
#include <string>

class Forme;

class ChargeurForme
{
public:
    ChargeurForme();
    std::shared_ptr<Forme> chargerUne(std::istream &in);

    class Handler
    {
    public:
        virtual ~Handler() {}
        void setNext(Handler *n) { next = n; }

        virtual bool handle(const std::string &line,
                            std::istream &in,
                            std::shared_ptr<Forme> &out,
                            ChargeurForme &loader) = 0;

    protected:
        Handler *next = nullptr;

        bool pass(const std::string &line,
                  std::istream &in,
                  std::shared_ptr<Forme> &out,
                  ChargeurForme &loader);
    };

    static bool lireLigneUtile(std::istream &in, std::string &line);

private:
    std::unique_ptr<Handler> hSegment;
    std::unique_ptr<Handler> hCercle;
    std::unique_ptr<Handler> hTriangle;
    std::unique_ptr<Handler> hPolygone;
    std::unique_ptr<Handler> hGroupe;

    Handler *head = nullptr;
};

#endif
