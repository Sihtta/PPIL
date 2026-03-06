package ppil.server.cor;

import ppil.server.command.Command;
import ppil.server.context.DrawContext;

/**
 * Handler chargé de traiter la commande END.
 *
 * Cette commande indique généralement la fin de l'envoi
 * des primitives par le client.
 *
 * Ici le handler se contente de rafraîchir l'affichage.
 */
public class EndHandler extends Handler {

    /**
     * Vérifie si la commande est END.
     */
    @Override
    protected boolean canHandle(Command cmd) {
        return cmd.getName().equals("END");
    }

    /**
     * Traitement de la commande END.
     */
    @Override
    protected void process(Command cmd, DrawContext ctx) {

        // Simple message de debug côté serveur
        System.out.println("END");

        // Rafraîchissement du panneau si une fenêtre est ouverte
        if (ctx.getPanel() != null) ctx.getPanel().repaint();
    }
}