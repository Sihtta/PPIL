package ppil.server.cor;

import ppil.server.command.Command;
import ppil.server.context.DrawContext;

/**
 * Handler chargé de la commande OPEN.
 *
 * Cette commande demande l'ouverture de la fenêtre graphique
 * avec une largeur et une hauteur données.
 *
 * Exemple :
 * OPEN 800 600
 */
public class OpenHandler extends Handler {

    /**
     * Vérifie si la commande est OPEN.
     */
    @Override
    protected boolean canHandle(Command cmd) {
        return cmd.getName().equals("OPEN");
    }

    /**
     * Ouvre la fenêtre graphique via le DrawContext.
     */
    @Override
    protected void process(Command cmd, DrawContext ctx) {

        // Lecture de la largeur et de la hauteur
        int w = Integer.parseInt(cmd.getArgs().get(0));
        int h = Integer.parseInt(cmd.getArgs().get(1));

        // Création de la fenêtre Swing
        ctx.openWindow(w, h);

        // Message côté serveur
        System.out.println("OPEN window " + cmd.getArgs());
    }
}