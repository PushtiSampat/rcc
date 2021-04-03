import java.io.*;
import java.net.*;

public class TCP3Client {

    public static void main(String argv[]) throws Exception {
        String sentence;
        int length;

        try (BufferedReader inFromUser = new BufferedReader(new InputStreamReader(System.in));
                Socket clientSocket = new Socket(InetAddress.getLocalHost(), 6789);
                DataOutputStream outToServer = new DataOutputStream(clientSocket.getOutputStream());
                BufferedReader inFromServer = new BufferedReader(
                        new InputStreamReader(clientSocket.getInputStream()));) {
            sentence = inFromUser.readLine();

            outToServer.writeBytes(sentence + '\n');

            length = inFromServer.read();

            System.out.println("From Server: " + length);
        }
    }
}
