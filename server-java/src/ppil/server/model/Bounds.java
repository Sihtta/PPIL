package ppil.server.model;

/**
 * Représente une boîte englobante.
 *
 * Cette classe sert à stocker les limites d'une primitive
 * ou d'un ensemble de primitives :
 * - minX / minY : coin inférieur gauche
 * - maxX / maxY : coin supérieur droit
 *
 * Elle est utilisée par le panneau de dessin pour calculer
 * le cadrage automatique de la scène.
 */
public class Bounds {
    /** Abscisse minimale */
    public double minX;

    /** Ordonnée minimale */
    public double minY;

    /** Abscisse maximale */
    public double maxX;

    /** Ordonnée maximale */
    public double maxY;

    /**
     * Construit une boîte englobante à partir de ses bornes.
     *
     * @param minX borne minimale en x
     * @param minY borne minimale en y
     * @param maxX borne maximale en x
     * @param maxY borne maximale en y
     */
    public Bounds(double minX, double minY, double maxX, double maxY) {
        this.minX = minX; this.minY = minY; this.maxX = maxX; this.maxY = maxY;
    }

    /**
     * Étend la boîte courante pour inclure une autre boîte.
     *
     * Si la boîte passée en paramètre est nulle, rien n'est fait.
     *
     * @param b boîte à inclure
     */
    public void include(Bounds b) {
        if (b == null) return;

        // Mise à jour des bornes minimales
        minX = Math.min(minX, b.minX);
        minY = Math.min(minY, b.minY);

        // Mise à jour des bornes maximales
        maxX = Math.max(maxX, b.maxX);
        maxY = Math.max(maxY, b.maxY);
    }
}