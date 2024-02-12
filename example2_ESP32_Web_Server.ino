//I'm creating a simple web server on ESP32

/*

***WiFi.status() function returns the current WiFi connection status of the ESP32.***


WL_CONNECTED: The ESP32 device is successfully connected to a WiFi network.
WL_NO_SHIELD: The required hardware for WiFi connection on the ESP32 was not found (for example, there is no WiFi module).
WL_IDLE_STATUS: ESP32 is waiting without WiFi connection.
WL_NO_SSID_AVAIL: No networks were found with the specified SSID.
WL_SCAN_COMPLETED: Scanning for WiFi networks is completed.
WL_CONNECT_FAILED: Connection failed.
WL_CONNECTION_LOST: The current connection has been lost.
WL_DISCONNECTED: ESP32 is not connected to a WiFi network.

*/

#include <WiFi.h>
#include <WebServer.h>

const char* ssid = ""; // SSID of the WiFi network
const char* password = ""; // Password of WiFi network

WebServer server(80); //Port of the web server

//Function to call when server root is accessed
void handleRoot() {
  String message = "Hello Browser!!!";
  Serial.println("Sunucu kök dizinine erişildi");
  server.send(200, "text/plain", message); // Tarayıcıya mesajı gönderelim
}

void setup() {
  Serial.begin(115200);
  
  //Connecting to WiFi network
  WiFi.begin(ssid, password);

  //Wait until it connects to the wifi network
  while (WiFi.status() != WL_CONNECTED) {
    delay(1500);
    Serial.println("Connecting to WiFi..");
  }
  Serial.println("Connected to WiFi");
  
  IPAddress localIP = WiFi.localIP();
  Serial.print("Local IP address of ESP32: ");
  Serial.println(localIP);

  
  // Calling the handleRoot function when the server root is accessed
  server.on("/", handleRoot);

  // Starting the server
  server.begin();
  Serial.println("HTTP server started");
}

void loop() {
  
  server.handleClient(); // Listening to client connections. Receiving and processing requests from the client
  
}
