package ppil.server.gui;

import java.awt.Graphics;
import java.awt.Graphics2D;
import java.util.List;
import javax.swing.JPanel;
import ppil.server.model.Primitive;

/**
 * Panneau graphique chargé d'afficher les primitives.
 *
 * Cette classe est responsable du rendu graphique.
 * Elle utilise Swing et redessine toutes les primitives
 * à chaque appel de paintComponent.
 *
 * Le panneau calcule également une transformation
 * pour adapter automatiquement le dessin à la taille
 * de la fenêtre (zoom et centrage).
 */
public class DrawPanel extends JPanel {

    /** Liste des primitives à dessiner */
    private final List<Primitive> primitives;

    /**
     * Crée un panneau de dessin.
     *
     * @param primitives liste des primitives à afficher
     */
    public DrawPanel(List<Primitive> primitives) {
        this.primitives = primitives;
    }

    /**
     * Méthode Swing appelée pour redessiner le composant.
     */
    @Override
    protected void paintComponent(Graphics g) {

        // Toujours appeler le parent
        super.paintComponent(g);

        // On travaille avec Graphics2D
        Graphics2D g2 = (Graphics2D) g.create();

        // Si aucune primitive, rien à dessiner
        if (primitives.isEmpty()) {
            g2.dispose();
            return;
        }

        // Calcul de la bounding box globale
        ppil.server.model.Bounds b = primitives.get(0).getBounds();

        for (int i = 1; i < primitives.size(); i++) {
            b.include(primitives.get(i).getBounds());
        }

        // Dimensions du monde
        double worldW = Math.max(1e-9, b.maxX - b.minX);
        double worldH = Math.max(1e-9, b.maxY - b.minY);

        // Marge autour du dessin
        double margin = Math.min(getWidth(), getHeight()) * 0.12;

        // Facteurs d'échelle
        double sx = (getWidth() - 2 * margin) / worldW;
        double sy = (getHeight() - 2 * margin) / worldH;
        double s = Math.min(sx, sy);

        // centre en pixels
        double cxPix = getWidth() / 2.0;
        double cyPix = getHeight() / 2.0;

        // centre en monde
        double cxW = (b.minX + b.maxX) / 2.0;
        double cyW = (b.minY + b.maxY) / 2.0;

        // On veut Y vers le haut : on inverse l'axe
        g2.translate(cxPix, cyPix);
        g2.scale(s, -s);
        g2.translate(-cxW, -cyW);

        // Ajustement de l'épaisseur du trait
        g2.setStroke(new java.awt.BasicStroke(2.0f / (float)s));

        // Dessin de toutes les primitives
        for (Primitive p : primitives) {
            p.draw(g2);
        }

        g2.dispose();
    }
}