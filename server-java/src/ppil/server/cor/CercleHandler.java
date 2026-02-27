package ppil.server.cor;

import java.util.List;

import ppil.server.command.Command;
import ppil.server.context.DrawContext;
import ppil.server.model.CerclePrim;

public class CercleHandler extends Handler {

    @Override
    protected boolean canHandle(Command cmd) {
        return cmd.getName().equals("CERCLE");
    }

    @Override
    protected void process(Command cmd, DrawContext ctx) {
        List<String> a = cmd.getArgs();
        if (a.size() < 3) return;

        double cx = Double.parseDouble(a.get(0));
        double cy = Double.parseDouble(a.get(1));
        double r  = Double.parseDouble(a.get(2));

        ctx.getPrimitives().add(new CerclePrim(ctx.getCurrentColor(), cx, cy, r));
        ctx.getPanel().repaint();
    }
}