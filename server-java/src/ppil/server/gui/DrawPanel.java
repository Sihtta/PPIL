package ppil.server.gui;

import java.awt.Graphics;
import java.awt.Graphics2D;
import java.util.List;

import javax.swing.JPanel;

import ppil.server.model.Primitive;

public class DrawPanel extends JPanel {
    private final List<Primitive> primitives;

    public DrawPanel(List<Primitive> primitives) {
        this.primitives = primitives;
    }

    @Override
    protected void paintComponent(Graphics g) {
        super.paintComponent(g);

        Graphics2D g2 = (Graphics2D) g.create();

        if (primitives.isEmpty()) {
            g2.dispose();
            return;
        }

        ppil.server.model.Bounds b = primitives.get(0).getBounds();
        for (int i = 1; i < primitives.size(); i++) {
            b.include(primitives.get(i).getBounds());
        }

        double worldW = Math.max(1e-9, b.maxX - b.minX);
        double worldH = Math.max(1e-9, b.maxY - b.minY);

        double margin = Math.min(getWidth(), getHeight()) * 0.12;
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

        g2.setStroke(new java.awt.BasicStroke(2.0f / (float)s));

        for (Primitive p : primitives) {
            p.draw(g2);
        }

        g2.dispose();
    }
}