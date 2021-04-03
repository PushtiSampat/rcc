import java.io.*;
import java.net.*;

public class TCP8Client {
    public static void main(String args[]) throws Exception {
        Socket clientSocket = new Socket(InetAddress.getLocalHost(), 6789);
        DataOutputStream outToServer = new DataOutputStream(clientSocket.getOutputStream());
        BufferedReader inFromServer = new BufferedReader(new InputStreamReader(clientSocket.getInputStream()));
        String response = inFromServer.readLine();
        System.out.println("Response from Server: " + response);
        clientSocket.close();
    }
}
