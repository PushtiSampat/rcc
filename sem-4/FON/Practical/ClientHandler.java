package TCP;

import java.io.*;
import java.net.*;

public class ClientHandler extends Thread {
    private final Socket socket;
    private final TCP7Server server;
    private PrintWriter writer;
    public String username;

    public ClientHandler(Socket socket, TCP7Server server) {
        this.socket = socket;
        this.server = server;
    }

    @Override
    public void run() {
        try {
            BufferedReader reader = new BufferedReader(new InputStreamReader(socket.getInputStream()));
            writer = new PrintWriter(socket.getOutputStream(), true);
            username = reader.readLine();
            server.addUser(username, this);
            server.listUsers();
            String serverMessage = "New User Connected: " + username;
            server.sendToEveryone(serverMessage, this);
            String clientMessage;
            do {
                clientMessage = reader.readLine().trim();
                serverMessage = "From " + username + ": " + clientMessage;
                System.out.println(serverMessage);
                server.sendToEveryone(serverMessage, this);
            } while (!clientMessage.equalsIgnoreCase("bye"));
        } catch (Exception e) {
            System.out.println("Error: " + e.getMessage());
        } finally {
            try {
                server.removeUser(username);
                socket.close();
                String serverMessage = username + " disconnected...";
                server.sendToEveryone(serverMessage, this);
            } catch (Exception e) {
                System.out.println("Error: " + e.getMessage());
            }
        }
    }

    void sendMessage(String message) {
        writer.println(message);
    }
}
