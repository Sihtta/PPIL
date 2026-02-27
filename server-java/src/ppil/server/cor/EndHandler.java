package ppil.server.cor;

import ppil.server.command.Command;
import ppil.server.context.DrawContext;

public class EndHandler extends Handler {

    @Override
    protected boolean canHandle(Command cmd) {
        return cmd.getName().equals("END");
    }

    @Override
    protected void process(Command cmd, DrawContext ctx) {
        System.out.println("END");
        if (ctx.getPanel() != null) ctx.getPanel().repaint();
    }
}