package ppil.server.context;

import ppil.server.gui.DrawPanel;
import ppil.server.model.Primitive;

import javax.swing.JFrame;
import java.awt.Color;
import java.util.ArrayList;
import java.util.List;

public class DrawContext {
    private Color currentColor = Color.BLACK;

    private JFrame frame;
    private DrawPanel panel;
    private final List<Primitive> primitives = new ArrayList<>();

    public Color getCurrentColor() { return currentColor; }
    public void setCurrentColor(Color c) { currentColor = c; }

    public JFrame getFrame() { return frame; }
    public DrawPanel getPanel() { return panel; }
    public List<Primitive> getPrimitives() { return primitives; }

    public void openWindow(int w, int h) {
        if (frame != null) return;

        frame = new JFrame("PPIL - Dessin");
        panel = new DrawPanel(primitives);
        frame.setContentPane(panel);
        frame.setSize(w, h);
        frame.setDefaultCloseOperation(JFrame.DISPOSE_ON_CLOSE);
        frame.setVisible(true);
    }
}