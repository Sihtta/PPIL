package ppil.server.cor;

import java.awt.Color;
import java.util.List;
import ppil.server.command.Command;
import ppil.server.context.DrawContext;

/**
 * Handler chargé de modifier la couleur courante du dessin.
 *
 * La commande COLOR permet de changer la couleur utilisée
 * pour les primitives suivantes.
 *
 * Exemple :
 * COLOR red
 */
public class ColorHandler extends Handler {

    /**
     * Vérifie si la commande est une commande COLOR.
     */
    @Override
    protected boolean canHandle(Command cmd) {
        return cmd.getName().equals("COLOR");
    }

    /**
     * Met à jour la couleur courante dans le contexte.
     */
    @Override
    protected void process(Command cmd, DrawContext ctx) {

        List<String> a = cmd.getArgs();

        // Il faut au moins un argument (le nom de la couleur)
        if (a.size() < 1) return;

        String s = a.get(0);

        // Couleur par défaut
        Color c = Color.BLACK;

        // Conversion simple texte -> objet Color
        if (s.equals("black")) c = Color.BLACK;
        else if (s.equals("blue")) c = Color.BLUE;
        else if (s.equals("red")) c = Color.RED;
        else if (s.equals("green")) c = Color.GREEN;
        else if (s.equals("yellow")) c = Color.YELLOW;
        else if (s.equals("cyan")) c = Color.CYAN;

        // Mise à jour de la couleur dans le contexte
        ctx.setCurrentColor(c);
    }
}