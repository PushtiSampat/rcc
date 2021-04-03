import java.io.*;
import java.net.*;

public class TCP1Client {

    public static void main(String argv[]) throws Exception {
        String sentence;
        while (true) {
            Socket clientSocket = new Socket("localhost", 6789);
            BufferedReader inFromUser = new BufferedReader(new InputStreamReader(System.in));
            DataOutputStream outToServer = new DataOutputStream(clientSocket.getOutputStream())
            sentence = inFromUser.readLine();
            outToServer.writeBytes(sentence + '\n');
            if (sentence.equalsIgnoreCase("exit") || sentence.equalsIgnoreCase("bye")) {
                clientSocket.close();
                break;
            }
        }
    }
}

