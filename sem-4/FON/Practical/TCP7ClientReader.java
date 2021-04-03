package TCP;

import java.io.*;
import java.net.*;

public class TCP7ClientReader extends Thread {
    private BufferedReader reader;
    private final Socket socket;
    private final TCP7Client client;

    public TCP7ClientReader(Socket socket, TCP7Client client) {
        this.socket = socket;
        this.client = client;
        try {
            reader = new BufferedReader(new InputStreamReader(socket.getInputStream()));
        } catch (Exception e) {
            System.out.println("Error: " + e.getMessage());
        }
    }

    @Override
    public void run() {
        while (true) {
            try {
                String response = reader.readLine();
                System.out.println("\n" + response);
                if (client.getUsername() != null) {
                    System.out.print("From " + client.getUsername() + ":");
                }
            } catch (Exception e) {
                System.out.println("Error: " + e.getMessage());
                break;
            }
        }
    }
}
