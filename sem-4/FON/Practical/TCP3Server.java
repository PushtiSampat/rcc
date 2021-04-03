import java.io.*;
import java.net.*;

public class TCP3Server {

    public static void main(String argv[]) throws Exception {
        String clientSentence;
        int length;

        ServerSocket welcomeSocket = new ServerSocket(6789);

        while (true) {
            Socket connectionSocket = welcomeSocket.accept();
            try (BufferedReader inFromClient = new BufferedReader(
                    new InputStreamReader(connectionSocket.getInputStream()));
                    DataOutputStream outToClient = new DataOutputStream(connectionSocket.getOutputStream());) {
                clientSentence = inFromClient.readLine();
                length = clientSentence.length();
                System.out.println("Client Request String = " + clientSentence + " | Response = " + length);
                outToClient.writeByte(length);
            }
        }
    }
}
