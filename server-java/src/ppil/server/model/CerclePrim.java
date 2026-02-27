package ppil.server.model;

import java.awt.Color;
import java.awt.Graphics2D;
import java.awt.geom.Ellipse2D;

public class CerclePrim implements Primitive {
    private final Color color;
    private final double cx, cy, r;

    public CerclePrim(Color color, double cx, double cy, double r) {
        this.color = color;
        this.cx = cx; this.cy = cy; this.r = r;
    }

    @Override
    public void draw(Graphics2D g) {
        g.setColor(color);
        g.draw(new Ellipse2D.Double(cx - r, cy - r, 2 * r, 2 * r));
    }

    @Override
    public Bounds getBounds() {
        return new Bounds(cx - r, cy - r, cx + r, cy + r);
    }
}