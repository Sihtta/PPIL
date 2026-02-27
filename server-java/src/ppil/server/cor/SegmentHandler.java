package ppil.server.cor;

import java.util.List;

import ppil.server.command.Command;
import ppil.server.context.DrawContext;
import ppil.server.model.SegmentPrim;

public class SegmentHandler extends Handler {

    @Override
    protected boolean canHandle(Command cmd) {
        return cmd.getName().equals("SEGMENT");
    }

    @Override
    protected void process(Command cmd, DrawContext ctx) {
        List<String> a = cmd.getArgs();
        if (a.size() < 4) return;

        double x1 = Double.parseDouble(a.get(0));
        double y1 = Double.parseDouble(a.get(1));
        double x2 = Double.parseDouble(a.get(2));
        double y2 = Double.parseDouble(a.get(3));

        ctx.getPrimitives().add(new SegmentPrim(ctx.getCurrentColor(), x1, y1, x2, y2));
        ctx.getPanel().repaint();
    }
}