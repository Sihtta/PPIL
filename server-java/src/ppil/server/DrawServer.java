package ppil.server;

import java.io.IOException;
import java.net.ServerSocket;
import java.net.Socket;

/**
 * Serveur principal de l'application de dessin.
 *
 * Ce serveur écoute un port TCP et attend les connexions des clients.
 * Lorsqu'un client se connecte, un nouveau thread est créé pour gérer
 * la communication avec ce client.
 *
 * Le protocole est simple : le client envoie des commandes de dessin
 * sous forme de texte (segment, cercle, couleur, etc.).
 */
public class DrawServer {

    /**
     * Point d'entrée du serveur.
     *
     * Lance un ServerSocket et attend les connexions entrantes.
     * Chaque client est traité dans un thread indépendant.
     */
    public static void main(String[] args) {
        int port = 12345; // port utilisé par le serveur

        try (ServerSocket serverSocket = new ServerSocket(port)) {

            System.out.println("Serveur demarre sur le port " + port);

            // Boucle infinie : le serveur reste actif
            while (true) {

                // Attente d'une connexion client
                Socket client = serverSocket.accept();

                System.out.println("Client connecte: " + client.getInetAddress());

                // Création d'un thread pour gérer ce client
                Thread t = new Thread(new ClientHandler(client));
                t.start();
            }

        } catch (IOException e) {
            // Erreur réseau ou problème de socket
            e.printStackTrace();
        }
    }
}