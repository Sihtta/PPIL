package ppil.server.context;

import java.awt.Color;
import java.util.ArrayList;
import java.util.List;
import javax.swing.JFrame;
import ppil.server.gui.DrawPanel;
import ppil.server.model.Primitive;

/**
 * Contexte partagé pendant le traitement des commandes.
 *
 * Cette classe contient toutes les informations nécessaires
 * pour construire et afficher le dessin :
 *
 * - la couleur courante
 * - la fenêtre graphique
 * - le panneau de dessin
 * - la liste des primitives créées
 *
 * Les handlers de la chaîne COR utilisent ce contexte pour
 * modifier l'état du dessin.
 */
public class DrawContext {

    /** Couleur actuellement utilisée pour dessiner */
    private Color currentColor = Color.BLACK;

    /** Fenêtre Swing affichant le dessin */
    private JFrame frame;

    /** Panneau graphique où les primitives sont dessinées */
    private DrawPanel panel;

    /** Liste des primitives à afficher */
    private final List<Primitive> primitives = new ArrayList<>();

    public Color getCurrentColor() { return currentColor; }

    /**
     * Change la couleur courante utilisée pour les primitives.
     */
    public void setCurrentColor(Color c) { currentColor = c; }

    public JFrame getFrame() { return frame; }

    public DrawPanel getPanel() { return panel; }

    public List<Primitive> getPrimitives() { return primitives; }

    /**
     * Ouvre la fenêtre graphique si elle n'existe pas déjà.
     *
     * @param w largeur
     * @param h hauteur
     */
    public void openWindow(int w, int h) {

        // On évite d'ouvrir plusieurs fenêtres
        if (frame != null) return;

        frame = new JFrame("PPIL - Dessin");

        // Le panel reçoit la liste de primitives à afficher
        panel = new DrawPanel(primitives);

        frame.setContentPane(panel);
        frame.setSize(w, h);

        // La fermeture de la fenêtre détruit simplement la fenêtre
        frame.setDefaultCloseOperation(JFrame.DISPOSE_ON_CLOSE);

        frame.setVisible(true);
    }
}