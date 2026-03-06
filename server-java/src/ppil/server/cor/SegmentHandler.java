package ppil.server.cor;

import java.util.List;
import ppil.server.command.Command;
import ppil.server.context.DrawContext;
import ppil.server.model.SegmentPrim;

/**
 * Handler responsable du traitement des commandes SEGMENT.
 *
 * Cette commande permet de dessiner un segment entre deux points.
 *
 * Format :
 * SEGMENT x1 y1 x2 y2
 */
public class SegmentHandler extends Handler {

    /**
     * Vérifie si la commande est SEGMENT.
     */
    @Override
    protected boolean canHandle(Command cmd) {
        return cmd.getName().equals("SEGMENT");
    }

    /**
     * Création de la primitive SegmentPrim.
     */
    @Override
    protected void process(Command cmd, DrawContext ctx) {

        List<String> a = cmd.getArgs();

        // Vérification minimale
        if (a.size() < 4) return;

        // Lecture des coordonnées
        double x1 = Double.parseDouble(a.get(0));
        double y1 = Double.parseDouble(a.get(1));
        double x2 = Double.parseDouble(a.get(2));
        double y2 = Double.parseDouble(a.get(3));

        // Ajout du segment dans la liste des primitives
        ctx.getPrimitives().add(new SegmentPrim(ctx.getCurrentColor(), x1, y1, x2, y2));

        // Rafraîchissement du dessin
        ctx.getPanel().repaint();
    }
}