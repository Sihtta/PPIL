package ppil.server.cor;

import ppil.server.command.Command;
import ppil.server.context.DrawContext;

public abstract class Handler {

    protected Handler next;

    public Handler setNext(Handler next) {
        this.next = next;
        return next;
    }

    public void handle(Command cmd, DrawContext ctx) {
        if (canHandle(cmd)) {
            process(cmd, ctx);
        } else if (next != null) {
            next.handle(cmd, ctx);
        } else {
            System.out.println("Commande inconnue: " + cmd.getName());
        }
    }

    protected abstract boolean canHandle(Command cmd);
    protected abstract void process(Command cmd, DrawContext ctx);
}