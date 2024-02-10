//I scan wireless networks using ESP32 and print the SSID and RSSI values of the found networks to the serial monitor.


#include "WiFi.h"

void setup() {
  Serial.begin(115200);// Serial communication is starting
  Serial.println("WiFi Scanning Program is Starting...");
  Serial.println(" WiFi mode set to client");
  WiFi.mode(WIFI_STA); // WiFi mode set to client
 
}

void loop() {
  
  Serial.println("Scanning..."); //Scanning started message printing

  //Assigning the number of networks found to the network count variable
  int network_count = WiFi.scanNetworks();
  
  Serial.println("Scan completed!"); 

  //If the number of networks found is 0, that is, no network is found
  if (network_count == 0) {
    Serial.println("No network found."); 
  } 

  //If the network is found
  else {
    Serial.println();
    //Printing the number of networks found
    Serial.print(network_count);
    Serial.println(" network found");
    
    for (int i = 0; i < network_count; ++i) {
      
      // SSID and RSSI values of each network found are printed
      Serial.print(i + 1);
      Serial.print(":");
      Serial.print(" SSID:");
      Serial.print(WiFi.SSID(i)); // SSID is printing
      Serial.print(" RSSI:");
      Serial.println(WiFi.RSSI(i)); //RSSI is printing
     
   
      delay(10);
      
    }
  }
  Serial.println("");


  delay(4000);
}
