import java.io.*;
import java.net.*;

public class UDP3Server {
    public static void main(String argv[]) throws Exception {
        DatagramSocket serverSocket = new DatagramSocket(6789);
        while (true) {
            byte[] receivedData = new byte[1024];
            byte[] len = new byte[1024];
            DatagramPacket receivedPacket = new DatagramPacket(receivedData, receivedData.length);
            serverSocket.receive(receivedPacket);
            String sentence = (new String(receivedPacket.getData())).trim();
            InetAddress IPAddress = receivedPacket.getAddress();
            int port = receivedPacket.getPort();
            len = ("" + sentence.length()).getBytes();
            System.out.println("Client Request String = " + sentence + " | Response = " + sentence.length());
            DatagramPacket sendPacket = new DatagramPacket(len, len.length, IPAddress, port);
            serverSocket.send(sendPacket);
        }
    }
}
