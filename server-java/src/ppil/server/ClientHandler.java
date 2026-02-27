package ppil.server;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.net.Socket;

import ppil.server.command.Command;
import ppil.server.context.DrawContext;
import ppil.server.cor.CercleHandler;
import ppil.server.cor.ColorHandler;
import ppil.server.cor.EndHandler;
import ppil.server.cor.Handler;
import ppil.server.cor.OpenHandler;
import ppil.server.cor.PolygonHandler;
import ppil.server.cor.SegmentHandler;

public class ClientHandler implements Runnable {

    private final Socket socket;

    public ClientHandler(Socket socket) {
        this.socket = socket;
    }

   @Override
    public void run() {

        DrawContext context = new DrawContext();

        Handler chain = new OpenHandler();
        chain
            .setNext(new ColorHandler())
            .setNext(new SegmentHandler())
            .setNext(new CercleHandler())
            .setNext(new PolygonHandler())
            .setNext(new EndHandler());

        try (
            BufferedReader in = new BufferedReader(
                new InputStreamReader(socket.getInputStream())
            )
        ) {
            String line;
            while ((line = in.readLine()) != null) {
                Command cmd = new Command(line);
                chain.handle(cmd, context);
            }

        } catch (IOException e) {
            e.printStackTrace();
        }
    }
}