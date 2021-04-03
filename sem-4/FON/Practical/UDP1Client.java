import java.io.*;
import java.net.*;

public class UDP1Client {
    public static void main(String args[]) throws Exception {
        BufferedReader inFromUser = new BufferedReader(new InputStreamReader(System.in));
        DatagramSocket clientSocket = new DatagramSocket();
        InetAddress IPAddress = InetAddress.getLocalHost();
        byte[] sendData = new byte[1024];
        String clientSentence;

        do {
            clientSentence = inFromUser.readLine();
            sendData = clientSentence.getBytes();
            DatagramPacket sendPacket = new DatagramPacket(sendData, sendData.length, IPAddress, 6789);
            clientSocket.send(sendPacket);
        } while (!clientSentence.equalsIgnoreCase("bye") && !clientSentence.equalsIgnoreCase("exit"));
        clientSocket.close();
    }
}
