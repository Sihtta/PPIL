package ppil.server.command;

import java.util.Arrays;
import java.util.List;

public class Command {
    private final String name;
    private final List<String> args;

    public Command(String line) {
        String[] tokens = line.trim().split("\\s+");
        this.name = tokens[0];
        this.args = Arrays.asList(tokens).subList(1, tokens.length);
    }

    public String getName() {
        return name;
    }

    public List<String> getArgs() {
        return args;
    }
}