import java.io.*;
import java.net.*;
import java.nio.ByteBuffer;
import java.util.Arrays;

public class UDP10Client {
    private static String source = "101";
    private static String destination = "102";

    public static void main(String args[]) throws Exception {
        String sentence;
        BufferedReader inFromUser = new BufferedReader(new InputStreamReader(System.in));
        Socket clientSocket = new Socket(InetAddress.getLocalHost(), 6789);
        DataOutputStream outToServer = new DataOutputStream(clientSocket.getOutputStream());
        DataInputStream inFromServer = new DataInputStream(clientSocket.getInputStream());
        sentence = inFromUser.readLine();
        byte[] sourceAddress = Arrays.copyOf(source.getBytes(), 10);
        byte[] destinationAddress = Arrays.copyOf(destination.getBytes(), 10);
        byte[] data = Arrays.copyOf(sentence.getBytes(), 50);
        byte[] packet = ByteBuffer.allocate(70).put(sourceAddress).put(destinationAddress).put(data).array();
        outToServer.write(packet);
        byte[] response = new byte[90];
        inFromServer.read(response);
        String rSourceAddress = new String(Arrays.copyOfRange(response, 0, 10));
        String rDestinationAddress = new String(Arrays.copyOfRange(response, 10, 20));
        String sSourceAddress = new String(Arrays.copyOfRange(response, 20, 30));
        String sDestinationAddress = new String(Arrays.copyOfRange(response, 30, 40));
        String receivedData = new String(Arrays.copyOfRange(response, 40, 90));
        System.out.println("Sender Source Address: " + sSourceAddress);
        System.out.println("Sender Destination Address: " + sDestinationAddress);
        System.out.println("Receiver Source Address: " + rSourceAddress);
        System.out.println("Receiver Destination Address: " + rDestinationAddress);
        System.out.println("Data: " + receivedData);
        clientSocket.close();
    }
}
