package ppil.server.cor;

import java.util.List;

import ppil.server.command.Command;
import ppil.server.context.DrawContext;
import ppil.server.model.PolygonPrim;

public class PolygonHandler extends Handler {

    @Override
    protected boolean canHandle(Command cmd) {
        return cmd.getName().equals("POLYGON");
    }

    @Override
    protected void process(Command cmd, DrawContext ctx) {
        List<String> a = cmd.getArgs();
        if (a.size() < 1) return;

        int n = Integer.parseInt(a.get(0));
        double[] xs = new double[n];
        double[] ys = new double[n];

        int idx = 1;
        for (int i = 0; i < n; i++) {
            xs[i] = Double.parseDouble(a.get(idx++));
            ys[i] = Double.parseDouble(a.get(idx++));
        }

        ctx.getPrimitives().add(new PolygonPrim(ctx.getCurrentColor(), xs, ys));
        ctx.getPanel().repaint();
    }
}