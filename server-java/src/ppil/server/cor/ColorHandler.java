package ppil.server.cor;

import java.awt.Color;
import java.util.List;

import ppil.server.command.Command;
import ppil.server.context.DrawContext;

public class ColorHandler extends Handler {

    @Override
    protected boolean canHandle(Command cmd) {
        return cmd.getName().equals("COLOR");
    }

    @Override
    protected void process(Command cmd, DrawContext ctx) {
        List<String> a = cmd.getArgs();
        if (a.size() < 1) return;

        String s = a.get(0);

        Color c = Color.BLACK;
        if (s.equals("black")) c = Color.BLACK;
        else if (s.equals("blue")) c = Color.BLUE;
        else if (s.equals("red")) c = Color.RED;
        else if (s.equals("green")) c = Color.GREEN;
        else if (s.equals("yellow")) c = Color.YELLOW;
        else if (s.equals("cyan")) c = Color.CYAN;

        ctx.setCurrentColor(c);
        System.out.println("COLOR = " + s);
    }
}