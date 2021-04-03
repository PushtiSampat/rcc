import java.io.*;
import java.net.*;

public class TCP9Client {
    public static void main(String args[]) throws Exception {
        Socket clientSocket = new Socket(InetAddress.getLocalHost(), 6789);
        DataOutputStream outToServer = new DataOutputStream(clientSocket.getOutputStream());
        BufferedReader inFromServer = new BufferedReader(new InputStreamReader(clientSocket.getInputStream()));
        String response = inFromServer.readLine();
        System.out.println("From Server: " + response);
        clientSocket.close();
    }
}
