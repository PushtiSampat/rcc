import java.net.*;
import java.lang.Math;

public class UDP5Server {
    public static void main(String[] args) throws Exception {
        DatagramSocket serverSocket = new DatagramSocket(6789);
        byte[] recieveData = new byte[1024];
        byte[] sendData = new byte[1024];
        String selectedData;
        int random;
        String[] quotes = { "You are nice Person.", "You are good.", "You are lucky.", "You have good choice.",
                "You can do it.", "You are Awesome.", "You are Smart.", "You are my friend.", "You are stupid.",
                "Lucky to have you here." };
        while (true) {
            DatagramPacket receivePacket = new DatagramPacket(recieveData, recieveData.length);
            serverSocket.receive(receivePacket);
            String clientSentence = new String(receivePacket.getData()).trim();
            InetAddress ipAddress = receivePacket.getAddress();
            int port = receivePacket.getPort();
            if (clientSentence.equalsIgnoreCase("hello")) {
                random = (int) (Math.random() * 10);
                selectedData = quotes[random];
            } else {
                selectedData = "Hi, say hello for quotes.";
            }
            sendData = selectedData.getBytes();
            DatagramPacket sendPacket = new DatagramPacket(sendData, sendData.length, ipAddress, port);
            serverSocket.send(sendPacket);
        }
    }
}