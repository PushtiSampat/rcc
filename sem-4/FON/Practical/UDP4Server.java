import java.net.DatagramPacket;
import java.net.DatagramSocket;
import java.net.InetAddress;

public class UDP4Server {
    public static void main(String[] args) throws Exception {
        DatagramSocket serverSocket = new DatagramSocket(6789);
        byte[] recieveData = new byte[1024];
        String greeting;
        int time = 0;
        int minute = 0;
        while (true) {
            DatagramPacket receivePacket = new DatagramPacket(recieveData, recieveData.length);
            serverSocket.receive(receivePacket);
            String clientSentence = new String(receivePacket.getData()).trim();
            try {
                time = Integer.parseInt(clientSentence.substring(0, clientSentence.indexOf(":")));
                minute = Integer
                        .parseInt(clientSentence.substring(clientSentence.indexOf(":") + 1, clientSentence.length()));

                if ((time < 0 || time > 23) || (minute > 59 || minute < 0))
                    greeting = "Invalid Time";
                else if (time > 19)
                    greeting = "Good Night";
                else if (time > 15)
                    greeting = "Good Evening";
                else if (time > 11)
                    greeting = "Good Afernoon";
                else if (time > 4)
                    greeting = "Good Morning";
                else
                    greeting = "Good MidNight";

            } catch (Exception e) {
                greeting = "Invalid Time ex";
            }

            InetAddress ipAddress = receivePacket.getAddress();
            int port = receivePacket.getPort();
            byte[] sendData = greeting.getBytes();
            DatagramPacket sendPacket = new DatagramPacket(sendData, sendData.length, ipAddress, port);
            serverSocket.send(sendPacket);
        }
    }
}