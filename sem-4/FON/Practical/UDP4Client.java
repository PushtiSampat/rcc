import java.net.*;
import java.io.*;

public class UDP4Client {

    public static void main(String[] args) throws Exception {
        String sentence;
        System.out.println("Enter Time as per 24 Hours Format (eg 17:50)");
        BufferedReader inFromUser = new BufferedReader(new InputStreamReader(System.in));
        sentence = inFromUser.readLine();
        System.out.println(sendAndReceivePacket(sentence));
    }

    private static String sendAndReceivePacket(String time) throws Exception {
        DatagramSocket clientSocket = new DatagramSocket();
        InetAddress ipAddress = InetAddress.getLocalHost();
        byte[] sendData = time.getBytes();
        DatagramPacket sendPacket = new DatagramPacket(sendData, sendData.length, ipAddress, 6789);
        clientSocket.send(sendPacket);
        byte[] receiveData = new byte[1024];
        DatagramPacket receivePacket = new DatagramPacket(receiveData, receiveData.length);
        clientSocket.receive(receivePacket);
        String greeting = (new String(receivePacket.getData())).trim();
        clientSocket.close();
        return greeting;
    }
}