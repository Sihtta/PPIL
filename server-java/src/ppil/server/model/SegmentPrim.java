package ppil.server.model;

import java.awt.Color;
import java.awt.Graphics2D;
import java.awt.geom.Line2D;

public class SegmentPrim implements Primitive {
    private final Color color;
    private final double x1, y1, x2, y2;

    public SegmentPrim(Color color, double x1, double y1, double x2, double y2) {
        this.color = color;
        this.x1 = x1; this.y1 = y1; this.x2 = x2; this.y2 = y2;
    }

    @Override
    public void draw(Graphics2D g) {
        g.setColor(color);
        g.draw(new Line2D.Double(x1, y1, x2, y2));
    }

    @Override
    public Bounds getBounds() {
        double minX = Math.min(x1, x2);
        double maxX = Math.max(x1, x2);
        double minY = Math.min(y1, y2);
        double maxY = Math.max(y1, y2);
        return new Bounds(minX, minY, maxX, maxY);
    }
}