package ppil.server;

import java.io.IOException;
import java.net.ServerSocket;
import java.net.Socket;

public class DrawServer {

    public static void main(String[] args) {
        int port = 12345;

        try (ServerSocket serverSocket = new ServerSocket(port)) {
            System.out.println("Serveur demarre sur le port " + port);

            while (true) {
                Socket client = serverSocket.accept();
                System.out.println("Client connecte: " + client.getInetAddress());

                Thread t = new Thread(new ClientHandler(client));
                t.start();
            }

        } catch (IOException e) {
            e.printStackTrace();
        }
    }
}