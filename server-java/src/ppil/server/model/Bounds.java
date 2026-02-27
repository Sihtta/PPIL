package ppil.server.model;

public class Bounds {
    public double minX, minY, maxX, maxY;

    public Bounds(double minX, double minY, double maxX, double maxY) {
        this.minX = minX; this.minY = minY; this.maxX = maxX; this.maxY = maxY;
    }

    public void include(Bounds b) {
        if (b == null) return;
        minX = Math.min(minX, b.minX);
        minY = Math.min(minY, b.minY);
        maxX = Math.max(maxX, b.maxX);
        maxY = Math.max(maxY, b.maxY);
    }
}