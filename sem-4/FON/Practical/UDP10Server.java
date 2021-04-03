import java.io.*;
import java.net.*;
import java.nio.ByteBuffer;
import java.util.Arrays;

public class UDP10Server {
    private static String source = "102";
    private static String destination = "103";

    public static void main(String args[]) throws Exception {
        ServerSocket welcomeSocket = new ServerSocket(6789);
        while (true) {
            Socket connectionSocket = welcomeSocket.accept();
            DataInputStream inFromClient = new DataInputStream(connectionSocket.getInputStream());
            DataOutputStream outToClient = new DataOutputStream(connectionSocket.getOutputStream());
            byte[] clientData = new byte[70];
            inFromClient.read(clientData);
            String sSourceAddress = new String(Arrays.copyOfRange(clientData, 0, 10));
            String sDestinationAddress = new String(Arrays.copyOfRange(clientData, 10, 20));
            String receivedData = new String(Arrays.copyOfRange(clientData, 20, 70));
            System.out.println("_____From Client_____");
            System.out.println("Sender Source Address: " + sSourceAddress);
            System.out.println("Sender Destination Address: " + sDestinationAddress);
            System.out.println("Client - Data: " + receivedData);
            byte[] sourceAddress = Arrays.copyOf(source.getBytes(), 10);
            byte[] destinationAddress = Arrays.copyOf(destination.getBytes(), 10);
            byte[] newPacket = ByteBuffer.allocate(90).put(sourceAddress).put(destinationAddress).put(clientData)
                    .array();
            outToClient.write(newPacket);
        }
    }
}
