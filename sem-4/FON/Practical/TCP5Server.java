import java.io.*;
import java.net.*;
import java.lang.Math;

public class TCP5Server {

    public static void main(String argv[]) throws Exception {
        String clientSentence;
        int random;
        String[] quotes = { "You are nice Person.", "You are good.", "You are lucky.", "You have good choice.",
                "You can do it.", "You are Awesome.", "You are Smart.", "You are my friend.", "You are stupid.",
                "Lucky to have you here." };

        ServerSocket welcomeSocket = new ServerSocket(1235);

        while (true) {
            Socket connectionSocket = welcomeSocket.accept();
            try (BufferedReader inFromClient = new BufferedReader(
                    new InputStreamReader(connectionSocket.getInputStream()));
                    DataOutputStream outToClient = new DataOutputStream(connectionSocket.getOutputStream());) {
                clientSentence = inFromClient.readLine();
                if (clientSentence.equalsIgnoreCase("hello")) {
                    random = (int) (Math.random() * 10);
                    outToClient.writeBytes(quotes[random]);
                } else {
                    outToClient.writeBytes("Hi, say hello for quotes.");
                }
            }
        }
    }
}
