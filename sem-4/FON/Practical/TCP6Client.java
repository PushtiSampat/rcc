import java.io.*;
import java.net.*;

public class TCP6Client {

    public static void main(String argv[]) throws Exception {
        String sentence;
        String age;

        try (BufferedReader inFromUser = new BufferedReader(new InputStreamReader(System.in));
                Socket clientSocket = new Socket(InetAddress.getLocalHost(), 6789);
                DataOutputStream outToServer = new DataOutputStream(clientSocket.getOutputStream());
                BufferedReader inFromServer = new BufferedReader(
                        new InputStreamReader(clientSocket.getInputStream()));) {
            System.out.print("Enter Birth Date (eg : day/month/year) : ");
            sentence = inFromUser.readLine();
            outToServer.writeBytes(sentence + '\n');
            age = inFromServer.readLine();
            System.out.println("From Server: " + age);
        }
    }
}
