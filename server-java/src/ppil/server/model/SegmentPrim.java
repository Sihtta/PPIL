package ppil.server.model;

import java.awt.Color;
import java.awt.Graphics2D;
import java.awt.geom.Line2D;

/**
 * Représente un segment dessinable.
 *
 * Cette primitive mémorise ses deux extrémités ainsi que sa couleur.
 * Elle sait se dessiner et calculer ses propres bornes.
 */
public class SegmentPrim implements Primitive {
    /** Couleur du segment */
    private final Color color;

    /** Coordonnées des deux extrémités */
    private final double x1, y1, x2, y2;

    /**
     * Construit une primitive segment.
     *
     * @param color couleur du segment
     * @param x1 abscisse du premier point
     * @param y1 ordonnée du premier point
     * @param x2 abscisse du second point
     * @param y2 ordonnée du second point
     */
    public SegmentPrim(Color color, double x1, double y1, double x2, double y2) {
        this.color = color;
        this.x1 = x1; this.y1 = y1; this.x2 = x2; this.y2 = y2;
    }

    /**
     * Dessine le segment.
     *
     * @param g contexte graphique Swing
     */
    @Override
    public void draw(Graphics2D g) {
        g.setColor(color);

        // Le segment est représenté par une ligne entre deux points
        g.draw(new Line2D.Double(x1, y1, x2, y2));
    }

    /**
     * Retourne la boîte englobante du segment.
     *
     * @return bornes du segment
     */
    @Override
    public Bounds getBounds() {
        double minX = Math.min(x1, x2);
        double maxX = Math.max(x1, x2);
        double minY = Math.min(y1, y2);
        double maxY = Math.max(y1, y2);

        return new Bounds(minX, minY, maxX, maxY);
    }
}