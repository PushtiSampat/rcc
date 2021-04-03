package TCP;

import java.io.*;
import java.net.*;
import java.util.Scanner;

public class TCP7ClientWriter extends Thread {
    private PrintWriter writer;
    private final Socket socket;
    private final TCP7Client client;

    public TCP7ClientWriter(Socket socket, TCP7Client client) {
        this.socket = socket;
        this.client = client;
        try {
            OutputStream output = socket.getOutputStream();
            writer = new PrintWriter(output, true);
        } catch (Exception e) {
            System.out.println("Error: " + e.getMessage());
        }
    }

    @Override
    public void run() {
        Scanner sc = new Scanner(System.in);
        System.out.print("Enter your name: ");
        String userName = sc.nextLine();
        client.setUserName(userName);
        writer.println(userName);
        String text;
        do {
            System.out.print("From " + userName + ": ");
            text = sc.nextLine();
            writer.println(text);
        } while (!text.equalsIgnoreCase("bye"));
        try {
            socket.close();
        } catch (Exception e) {
            System.out.println("Error: " + e.getMessage());
        }
    }
}