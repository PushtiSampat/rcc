import java.io.*;
import java.net.*;

public class TCP2Server {

    public static void main(String argv[]) throws Exception {
        String clientSentence;

        ServerSocket welcomeSocket = new ServerSocket(6789);

        while (true) {
            Socket connectionSocket = welcomeSocket.accept();
            try (BufferedReader inFromClient = new BufferedReader(
                    new InputStreamReader(connectionSocket.getInputStream()));
                    DataOutputStream outToClient = new DataOutputStream(connectionSocket.getOutputStream());) {
                clientSentence = inFromClient.readLine();
                String upperCase = clientSentence.toUpperCase();
                System.out.println("Client Request String = " + clientSentence + " | Response = " + upperCase);
                outToClient.writeBytes(upperCase);
            }
        }
    }
}
