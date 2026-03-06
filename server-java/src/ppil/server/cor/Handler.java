package ppil.server.cor;

import ppil.server.command.Command;
import ppil.server.context.DrawContext;

/**
 * Classe abstraite représentant un maillon de la
 * chaîne de responsabilité (Chain Of Responsibility).
 *
 * Chaque handler est responsable d'un type de commande.
 * Si la commande ne correspond pas, elle est transmise
 * au handler suivant dans la chaîne.
 */
public abstract class Handler {

    /** Handler suivant dans la chaîne */
    protected Handler next;

    /**
     * Définit le handler suivant.
     * Permet de construire la chaîne dynamiquement.
     */
    public Handler setNext(Handler next) {
        this.next = next;
        return next;
    }

    /**
     * Méthode principale de traitement des commandes.
     *
     * Le handler teste d'abord s'il peut traiter la commande.
     * Sinon, la commande est transmise au handler suivant.
     */
    public void handle(Command cmd, DrawContext ctx) {

        if (canHandle(cmd)) {

            // Si ce handler sait traiter la commande
            process(cmd, ctx);

        } else if (next != null) {

            // Sinon on transmet au suivant
            next.handle(cmd, ctx);

        } else {

            // Aucun handler ne sait traiter la commande
            System.out.println("Commande inconnue: " + cmd.getName());
        }
    }

    /**
     * Test si ce handler peut traiter la commande.
     */
    protected abstract boolean canHandle(Command cmd);

    /**
     * Traitement concret de la commande.
     */
    protected abstract void process(Command cmd, DrawContext ctx);
}