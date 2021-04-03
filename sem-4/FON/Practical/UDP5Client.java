import java.net.*;
import java.io.*;

public class UDP5Client {

    public static void main(String[] args) throws Exception {
        String sentence;
        BufferedReader inFromUser = new BufferedReader(new InputStreamReader(System.in));
        sentence = inFromUser.readLine();
        DatagramSocket clientSocket = new DatagramSocket();
        InetAddress ipAddress = InetAddress.getLocalHost();
        byte[] sendData = sentence.getBytes();
        DatagramPacket sendPacket = new DatagramPacket(sendData, sendData.length, ipAddress, 6789);
        clientSocket.send(sendPacket);
        byte[] receiveData = new byte[1024];
        DatagramPacket receivePacket = new DatagramPacket(receiveData, receiveData.length);
        clientSocket.receive(receivePacket);
        String greeting = (new String(receivePacket.getData())).trim();
        System.out.println(greeting);
        clientSocket.close();
    }
}