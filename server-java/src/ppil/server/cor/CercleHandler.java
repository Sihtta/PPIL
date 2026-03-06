package ppil.server.cor;

import java.util.List;
import ppil.server.command.Command;
import ppil.server.context.DrawContext;
import ppil.server.model.CerclePrim;

/**
 * Handler responsable du traitement des commandes CERCLE.
 *
 * Fait partie de la chaîne de responsabilité (COR).
 * Si la commande reçue est "CERCLE", ce handler crée une
 * primitive CerclePrim et l'ajoute au contexte de dessin.
 *
 * Format attendu :
 * CERCLE cx cy r
 * où (cx,cy) est le centre et r le rayon.
 */
public class CercleHandler extends Handler {

    /**
     * Vérifie si ce handler peut traiter la commande.
     * Ici on regarde simplement le nom de la commande.
     */
    @Override
    protected boolean canHandle(Command cmd) {
        return cmd.getName().equals("CERCLE");
    }

    /**
     * Traitement de la commande CERCLE.
     * On récupère les arguments puis on crée la primitive graphique.
     */
    @Override
    protected void process(Command cmd, DrawContext ctx) {

        // Arguments de la commande
        List<String> a = cmd.getArgs();

        // Vérification minimale du nombre d'arguments
        if (a.size() < 3) return;

        // Conversion texte -> double
        double cx = Double.parseDouble(a.get(0));
        double cy = Double.parseDouble(a.get(1));
        double r  = Double.parseDouble(a.get(2));

        // Ajout du cercle dans la liste des primitives
        ctx.getPrimitives().add(new CerclePrim(ctx.getCurrentColor(), cx, cy, r));

        // Redessin du panneau Swing
        ctx.getPanel().repaint();
    }
}