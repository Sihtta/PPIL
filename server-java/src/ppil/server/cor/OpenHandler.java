package ppil.server.cor;

import ppil.server.command.Command;
import ppil.server.context.DrawContext;

public class OpenHandler extends Handler {

    @Override
    protected boolean canHandle(Command cmd) {
        return cmd.getName().equals("OPEN");
    }

    @Override
    protected void process(Command cmd, DrawContext ctx) {
        int w = Integer.parseInt(cmd.getArgs().get(0));
        int h = Integer.parseInt(cmd.getArgs().get(1));
        ctx.openWindow(w, h);
        System.out.println("OPEN window " + cmd.getArgs());
    }
}