import java.net.*;

public class UDP1Server {
    public static void main(String args[]) throws Exception {
        DatagramSocket serverSocket = new DatagramSocket(6789);
        while (true) {
            byte[] receiveData = new byte[1024];
            DatagramPacket receivePacket = new DatagramPacket(receiveData, receiveData.length);
            serverSocket.receive(receivePacket);
            String clientSentence = (new String(receivePacket.getData())).trim();
            System.out.println("Client Says : " + clientSentence);
            if (clientSentence.equalsIgnoreCase("bye") || clientSentence.equalsIgnoreCase("exit")) {
                serverSocket.close();
                return;
            }
        }
    }
}
