package TCP;

import java.io.*;
import java.net.*;
import java.util.*;

public class TCP7Server {
    private final Map<String, ClientHandler> users = new HashMap<>();

    public static void main(String[] args) {
        TCP7Server server = new TCP7Server();
        server.start();
    }

    public void start() {
        try (ServerSocket serverSocket = new ServerSocket(6789)) {
            System.out.println("----- Server -----");
            System.out.println("Listening on port 6789...");
            while (true) {
                Socket socket = serverSocket.accept();
                System.out.println("New User Connected...");
                ClientHandler newUser = new ClientHandler(socket, this);
                newUser.start();
            }
        } catch (IOException e) {
            System.out.println("Error in the server: " + e.getMessage());
        } catch (Exception e) {
            System.out.println("Error: " + e.getMessage());
        }
    }

    void sendToEveryone(String message, ClientHandler notToUser) {
        try {
            for (Map.Entry<String, ClientHandler> aUser : users.entrySet()) {
                if (aUser.getValue() != notToUser) {
                    aUser.getValue().sendMessage(message);
                }
            }
        } catch (Exception e) {
            System.out.println("Error: " + e.getMessage());
        }
    }

    void addUser(String userName, ClientHandler userThread) {
        users.put(userName, userThread);
    }

    void removeUser(String userName) {
        users.remove(userName);
    }

    void listUsers() {
        System.out.println("--- USERS ---");
        users.keySet().stream().forEach(System.out::println);
    }
}