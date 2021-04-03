import java.io.*;
import java.net.*;

public class TCP4Server {

    public static void main(String argv[]) throws Exception {
        String clientSentence;
        int time = 0;
        int minute = 0;
        ServerSocket welcomeSocket = new ServerSocket(6789);

        while (true) {
            Socket connectionSocket = welcomeSocket.accept();
            try (BufferedReader inFromClient = new BufferedReader(
                    new InputStreamReader(connectionSocket.getInputStream()));
                    DataOutputStream outToClient = new DataOutputStream(connectionSocket.getOutputStream());) {
                clientSentence = inFromClient.readLine();
                try {
                    time = Integer.parseInt(clientSentence.substring(0, clientSentence.indexOf(":")));
                    minute = Integer.parseInt(
                            clientSentence.substring(clientSentence.indexOf(":") + 1, clientSentence.length()));

                    if ((time < 0 || time > 23) || (minute > 59 || minute < 0))
                        outToClient.writeBytes("Invalid Time");
                    else if (time > 19)
                        outToClient.writeBytes("Good Night");
                    else if (time > 15)
                        outToClient.writeBytes("Good Evening");
                    else if (time > 11)
                        outToClient.writeBytes("Good Afernoon");
                    else if (time > 4)
                        outToClient.writeBytes("Good Morning");
                    else
                        outToClient.writeBytes("Good MidNight");

                } catch (Exception e) {
                    outToClient.writeBytes("Invalid Time");
                }
                // System.out.println("Client Request String = " + clientSentence + " | Response
                // = " + length);
            }
        }
    }
}
