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

/**
 * Gère la communication avec un client connecté au serveur.
 *
 * Chaque instance de ClientHandler est exécutée dans un thread
 * séparé. Le rôle principal est de lire les commandes envoyées
 * par le client (ligne par ligne) et de les transmettre à la
 * chaîne de responsabilité (COR).
 *
 * Le client envoie des instructions de dessin sous forme de texte.
 * Ces instructions sont converties en objets Command puis traitées
 * par les différents handlers (open, color, segment, cercle, etc.).
 */
public class ClientHandler implements Runnable {

    /** Socket représentant la connexion avec le client */
    private final Socket socket;

    /**
     * Crée un handler pour un client donné.
     *
     * @param socket socket ouverte avec le client
     */
    public ClientHandler(Socket socket) {
        this.socket = socket;
    }

   /**
    * Point d'entrée du thread.
    *
    * Cette méthode lit en continu les commandes envoyées par
    * le client jusqu'à fermeture de la connexion.
    */
   @Override
    public void run() {

        // Contexte partagé par tous les handlers.
        // Contient les primitives, la couleur courante et la fenêtre.
        DrawContext context = new DrawContext();

        // Construction de la chaîne de responsabilité.
        // Chaque handler est responsable d'un type de commande.
        Handler chain = new OpenHandler();
        chain
            .setNext(new ColorHandler())
            .setNext(new SegmentHandler())
            .setNext(new CercleHandler())
            .setNext(new PolygonHandler())
            .setNext(new EndHandler());

        try (
            // Lecture des données envoyées par le client
            BufferedReader in = new BufferedReader(
                new InputStreamReader(socket.getInputStream())
            )
        ) {
            String line;

            // Lecture ligne par ligne jusqu'à fermeture du flux
            while ((line = in.readLine()) != null) {

                // Transformation de la ligne texte en objet Command
                Command cmd = new Command(line);

                // Passage de la commande dans la chaîne COR
                chain.handle(cmd, context);
            }

        } catch (IOException e) {
            // En cas d'erreur réseau on affiche la stacktrace
            e.printStackTrace();
        }
    }
}