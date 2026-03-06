package ppil.server.model;

import java.awt.Color;
import java.awt.Graphics2D;
import java.awt.geom.Ellipse2D;

/**
 * Représente un cercle dessinable.
 *
 * Cette primitive mémorise sa couleur, son centre et son rayon.
 * Elle sait se dessiner elle-même et fournir sa boîte englobante.
 */
public class CerclePrim implements Primitive {
    /** Couleur du cercle */
    private final Color color;

    /** Coordonnées du centre et rayon */
    private final double cx, cy, r;

    /**
     * Construit une primitive cercle.
     *
     * @param color couleur du cercle
     * @param cx abscisse du centre
     * @param cy ordonnée du centre
     * @param r rayon
     */
    public CerclePrim(Color color, double cx, double cy, double r) {
        this.color = color;
        this.cx = cx; this.cy = cy; this.r = r;
    }

    /**
     * Dessine le cercle dans le contexte graphique reçu.
     *
     * @param g contexte graphique Swing
     */
    @Override
    public void draw(Graphics2D g) {
        g.setColor(color);

        // Un cercle est dessiné ici comme une ellipse dont largeur = hauteur
        g.draw(new Ellipse2D.Double(cx - r, cy - r, 2 * r, 2 * r));
    }

    /**
     * Retourne la boîte englobante du cercle.
     *
     * @return les bornes du cercle
     */
    @Override
    public Bounds getBounds() {
        return new Bounds(cx - r, cy - r, cx + r, cy + r);
    }
}