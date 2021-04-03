import java.net.*;

class UDP2Server {
    public static void main(String args[]) throws Exception {
        DatagramSocket serverSocket = new DatagramSocket(6789);
        while (true) {
            byte[] receivedData = new byte[1024];
            byte[] upperCase = new byte[1024];
            DatagramPacket receivedPacket = new DatagramPacket(receivedData, receivedData.length);
            serverSocket.receive(receivedPacket);
            String sentence = (new String(receivedPacket.getData())).trim();
            // System.out.println("Client Sended : " + sentence);
            InetAddress IPAddress = receivedPacket.getAddress();
            int port = receivedPacket.getPort();
            String capitalizedSentence = sentence.toUpperCase();
            upperCase = capitalizedSentence.getBytes();
            // String upperCase = sentence.toUpperCase();
            System.out.println("Client Request String = " + sentence + " | Response = " + capitalizedSentence);
            DatagramPacket sendPacket = new DatagramPacket(upperCase, upperCase.length, IPAddress, port);
            serverSocket.send(sendPacket);
        }
    }
}
