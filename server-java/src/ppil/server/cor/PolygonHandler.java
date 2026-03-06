package ppil.server.cor;

import java.util.List;
import ppil.server.command.Command;
import ppil.server.context.DrawContext;
import ppil.server.model.PolygonPrim;

/**
 * Handler responsable du traitement des commandes POLYGON.
 *
 * Cette commande permet de créer un polygone avec n sommets.
 *
 * Format :
 * POLYGON n x1 y1 x2 y2 ... xn yn
 */
public class PolygonHandler extends Handler {

    /**
     * Vérifie si la commande est POLYGON.
     */
    @Override
    protected boolean canHandle(Command cmd) {
        return cmd.getName().equals("POLYGON");
    }

    /**
     * Création de la primitive PolygonPrim.
     */
    @Override
    protected void process(Command cmd, DrawContext ctx) {

        List<String> a = cmd.getArgs();

        // Vérification minimale
        if (a.size() < 1) return;

        // Nombre de sommets
        int n = Integer.parseInt(a.get(0));

        // Tableaux des coordonnées
        double[] xs = new double[n];
        double[] ys = new double[n];

        // Lecture des coordonnées
        int idx = 1;
        for (int i = 0; i < n; i++) {
            xs[i] = Double.parseDouble(a.get(idx++));
            ys[i] = Double.parseDouble(a.get(idx++));
        }

        // Ajout du polygone dans le contexte
        ctx.getPrimitives().add(new PolygonPrim(ctx.getCurrentColor(), xs, ys));

        // Rafraîchissement de l'affichage
        ctx.getPanel().repaint();
    }
}