package ppil.server.model;

import java.awt.Graphics2D;

public interface Primitive {
    void draw(Graphics2D g);
    Bounds getBounds();
}