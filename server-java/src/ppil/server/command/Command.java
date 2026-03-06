package ppil.server.command;

import java.util.Arrays;
import java.util.List;

/**
 * Représente une commande envoyée par le client.
 *
 * Une commande correspond à une ligne de texte reçue
 * sur le socket. Elle est découpée en deux parties :
 *
 * - le nom de la commande (ex: SEGMENT, CERCLE, COLOR)
 * - une liste d'arguments associés.
 *
 * Cette classe sert uniquement à faciliter le traitement
 * des commandes dans la chaîne de responsabilité.
 */
public class Command {

    /** Nom de la commande */
    private final String name;

    /** Arguments de la commande */
    private final List<String> args;

    /**
     * Construit une commande à partir d'une ligne texte.
     *
     * Exemple :
     * "SEGMENT 10 10 50 50"
     *
     * name = SEGMENT
     * args = [10,10,50,50]
     *
     * @param line ligne reçue depuis le client
     */
    public Command(String line) {

        // Découpage de la ligne par espaces
        String[] tokens = line.trim().split("\\s+");

        // Premier élément = nom de commande
        this.name = tokens[0];

        // Les autres éléments = arguments
        this.args = Arrays.asList(tokens).subList(1, tokens.length);
    }

    /**
     * Retourne le nom de la commande.
     */
    public String getName() {
        return name;
    }

    /**
     * Retourne la liste des arguments.
     */
    public List<String> getArgs() {
        return args;
    }
}