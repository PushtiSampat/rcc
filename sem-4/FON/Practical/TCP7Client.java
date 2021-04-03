import java.net.*;
import java.io.*;

public class TCP7Client {
    private final String host;
    private final int port;
    private String username;

    public TCP7Client(String host, int port) {
        this.host = host;
        this.port = port;
    }

    public static void main(String[] args) {
        TCP7Client client = new TCP7Client("localhost", 6789);
        client.start();
    }

    public void start() {
        try {
            Socket socket = new Socket(host, port);
            System.out.println("Connected to the server...");
            var writeHandler = new TCP7ClientWriter(socket, this);
            var readHandler = new TCP7ClientReader(socket, this);
            writeHandler.start();
            readHandler.start();
        } catch (Exception e) {
            System.out.println("Error: " + e.getMessage());
        }
    }

    void setUserName(String username) {
        this.username = username;
    }

    String getUsername() {
        return this.username;
    }
}
