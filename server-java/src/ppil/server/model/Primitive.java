package ppil.server.model;

import java.awt.Graphics2D;

/**
 * Interface commune à toutes les primitives graphiques.
 *
 * Une primitive doit :
 * - savoir se dessiner
 * - savoir fournir sa boîte englobante
 *
 * Cela permet au panneau graphique de traiter toutes les formes
 * de manière uniforme, sans connaître leur type exact.
 */
public interface Primitive {

    /**
     * Dessine la primitive.
     *
     * @param g contexte graphique Swing
     */
    void draw(Graphics2D g);

    /**
     * Retourne la boîte englobante de la primitive.
     *
     * @return bornes de la primitive
     */
    Bounds getBounds();
}