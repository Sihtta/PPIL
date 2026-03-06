package ppil.server.model;

import java.awt.Color;
import java.awt.Graphics2D;
import java.awt.geom.Path2D;

/**
 * Représente un polygone dessinable.
 *
 * Le polygone est défini par deux tableaux :
 * - xs : les abscisses des sommets
 * - ys : les ordonnées des sommets
 *
 * Les sommets sont reliés dans l'ordre, puis le chemin est refermé.
 */
public class PolygonPrim implements Primitive {
    /** Couleur du polygone */
    private final Color color;

    /** Abscisses des sommets */
    private final double[] xs;

    /** Ordonnées des sommets */
    private final double[] ys;

    /**
     * Construit une primitive polygone.
     *
     * @param color couleur du polygone
     * @param xs tableau des abscisses
     * @param ys tableau des ordonnées
     */
    public PolygonPrim(Color color, double[] xs, double[] ys) {
        this.color = color;
        this.xs = xs;
        this.ys = ys;
    }

    /**
     * Dessine le polygone.
     *
     * @param g contexte graphique Swing
     */
    @Override
    public void draw(Graphics2D g) {
        g.setColor(color);

        // Construction du chemin géométrique
        Path2D.Double p = new Path2D.Double();

        // Premier sommet
        p.moveTo(xs[0], ys[0]);

        // Sommets suivants
        for (int i = 1; i < xs.length; i++) p.lineTo(xs[i], ys[i]);

        // Fermeture du polygone
        p.closePath();

        g.draw(p);
    }

    /**
     * Calcule la boîte englobante du polygone.
     *
     * @return les bornes du polygone
     */
    @Override
    public Bounds getBounds() {
        // Initialisation avec le premier sommet
        double minX = xs[0], maxX = xs[0];
        double minY = ys[0], maxY = ys[0];

        // Recherche des minimums et maximums
        for (int i = 1; i < xs.length; i++) {
            minX = Math.min(minX, xs[i]);
            maxX = Math.max(maxX, xs[i]);
            minY = Math.min(minY, ys[i]);
            maxY = Math.max(maxY, ys[i]);
        }

        return new Bounds(minX, minY, maxX, maxY);
    }
}