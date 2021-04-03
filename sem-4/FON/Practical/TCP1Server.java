import java.io.*;
import java.net.*;

public class TCP1Server {

    public static void main(String argv[]) throws Exception {
        String clientSentence;
        ServerSocket welcomeSocket = new ServerSocket(6789);
        System.out.println("Searching Client.....");
        while (true) {
            Socket connectionSocket = welcomeSocket.accept();
            try (BufferedReader inFromClient = new BufferedReader(
                    new InputStreamReader(connectionSocket.getInputStream()));) {
                clientSentence = inFromClient.readLine();
                System.out.println("Client String = " + clientSentence);
            }
            if (clientSentence.equalsIgnoreCase("exit") || clientSentence.equalsIgnoreCase("bye")) {
                connectionSocket.close();
                break;
            }
        }
    }
}
