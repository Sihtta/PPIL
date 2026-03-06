#ifndef CHARGEURFORME_H
#define CHARGEURFORME_H

#include <istream>
#include <memory>
#include <string>

class Forme;

/**
 * @class ChargeurForme
 * @brief Charge une forme depuis un flux texte.
 *
 * Le chargement repose sur le pattern Chain of Responsibility :
 * chaque handler tente de reconnaître une forme selon son type
 * (segment, cercle, triangle, polygone ou groupe).
 */
class ChargeurForme
{
public:
    /// Construit la chaîne des handlers de chargement
    ChargeurForme();

    /// Charge une forme à partir d'un flux
    std::shared_ptr<Forme> chargerUne(std::istream &in);

    /**
     * @class Handler
     * @brief Élément de la chaîne de responsabilité.
     *
     * Chaque handler tente de traiter une ligne du fichier.
     * Si le type ne correspond pas, il passe la main au suivant.
     */
    class Handler
    {
    public:
        virtual ~Handler() {}
        void setNext(Handler *n) { next = n; }

        /// Tente de construire une forme à partir de la ligne lue
        virtual bool handle(const std::string &line,
                            std::istream &in,
                            std::shared_ptr<Forme> &out,
                            ChargeurForme &loader) = 0;

    protected:
        Handler *next = nullptr; /// handler suivant dans la chaîne

        /// Passe le traitement au handler suivant
        bool pass(const std::string &line,
                  std::istream &in,
                  std::shared_ptr<Forme> &out,
                  ChargeurForme &loader);
    };

    /// Lit la prochaine ligne non vide du flux
    static bool lireLigneUtile(std::istream &in, std::string &line);

private:
    std::unique_ptr<Handler> hSegment;
    std::unique_ptr<Handler> hCercle;
    std::unique_ptr<Handler> hTriangle;
    std::unique_ptr<Handler> hPolygone;
    std::unique_ptr<Handler> hGroupe;

    Handler *head = nullptr; /// tête de la chaîne
};

#endif