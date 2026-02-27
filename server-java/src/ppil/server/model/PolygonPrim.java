package ppil.server.model;

import java.awt.Color;
import java.awt.Graphics2D;
import java.awt.geom.Path2D;

public class PolygonPrim implements Primitive {
    private final Color color;
    private final double[] xs;
    private final double[] ys;

    public PolygonPrim(Color color, double[] xs, double[] ys) {
        this.color = color;
        this.xs = xs;
        this.ys = ys;
    }

    @Override
    public void draw(Graphics2D g) {
        g.setColor(color);

        Path2D.Double p = new Path2D.Double();
        p.moveTo(xs[0], ys[0]);
        for (int i = 1; i < xs.length; i++) p.lineTo(xs[i], ys[i]);
        p.closePath();

        g.draw(p);
    }

    @Override
    public Bounds getBounds() {
        double minX = xs[0], maxX = xs[0];
        double minY = ys[0], maxY = ys[0];
        for (int i = 1; i < xs.length; i++) {
            minX = Math.min(minX, xs[i]);
            maxX = Math.max(maxX, xs[i]);
            minY = Math.min(minY, ys[i]);
            maxY = Math.max(maxY, ys[i]);
        }
        return new Bounds(minX, minY, maxX, maxY);
    }
}