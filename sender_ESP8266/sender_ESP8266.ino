/*
    This sketch sends controller input to a local server as a POST request

*/
#include <ESP8266HTTPClient.h>
#include <ESP8266WiFi.h>
#include <ArduinoJson.h>

/***** WIFI stuff *****/
char ssid[] = "******************";   // your network SSID (name)
char pass[] = "******************";   // your network password
String serverIp = "http://192.168.*.*:5000/api/request-screen"; //server IP + API endpoint
WiFiEventHandler gotIpEventHandler, disconnectedEventHandler;
boolean connected = false;            //Are we currently connected?

/***** Controller varaiables *****/
#define arrowNum  4
int arrow[arrowNum];
int prev_arrow[arrowNum];

/*********** ARDUINO JSON STUFF ***********/
StaticJsonDocument<200> jsonContent;

void setup() {

  Serial.begin(115200);

  pinMode(5, INPUT_PULLUP); //D1, arrow FRONT
  pinMode(4, INPUT_PULLUP); //D2, arrow RIGHT
  pinMode(0, INPUT_PULLUP); //D3, arrow LEFT
  pinMode(2, INPUT_PULLUP); //D4, arrow DOWN
  pinMode(16, OUTPUT);      //D0, WiFi connection LED

  for (int i = 0; i < arrowNum; i++) {
    arrow[i] = 0;
    prev_arrow[i] = HIGH;
  }

  //Connect to the WiFi network
  connectToWiFi();
}

void loop() {

  if(connected){

    arrow[0] = digitalRead(5);
    arrow[1] = digitalRead(4);
    arrow[2] = digitalRead(0);
    arrow[3] = digitalRead(2);

    for (int i = 0; i < arrowNum; i++) {
      //when joystick is pushed
      if (arrow[i] == LOW && prev_arrow[i] != LOW) {
        Serial.print(i + 1);
        Serial.println(" 1");
        prev_arrow[i] = LOW;

        //send POST request to local server
        HTTPClient http;
        String jsonString;
        http.begin(serverIp);  //Specify server IP + API endpoint
        http.addHeader("Content-Type", "application/json");         //Specify content-type header
        switch (i) {
          case 0:
            jsonContent["color"] = "red";
            break;
          case 1:
            jsonContent["color"] = "green";
            break;
          case 2:
            jsonContent["color"] = "blue";
            break;
          case 3:
            jsonContent["color"] = "yellow";
            break;
        }
        serializeJsonPretty(jsonContent, Serial); //print JSON content to Serial
        serializeJson(jsonContent, jsonString);   // Serialize JSON document
        int httpCode = http.POST(jsonString);     //Send the request
        String payload = http.getString();        //Get the response payload
        Serial.println(httpCode);                 //Print HTTP return code
        Serial.println(payload);                  //Print request response payload
        http.end();                               //Close connection
        jsonContent.clear();                      //reset json content
      }

      //when joystick is released
      if (arrow[i] == HIGH && prev_arrow[i] != HIGH) {
        Serial.print(i + 1);
        Serial.println(" 0");
        prev_arrow[i] = HIGH;
      }
    }

    delay(10);
  }

}

void connectToWiFi(){

  gotIpEventHandler = WiFi.onStationModeGotIP([](const WiFiEventStationModeGotIP& event)
  {
    Serial.print("WiFi connected, IP: ");
    Serial.println(WiFi.localIP());
    connected = true;
    Serial.println("Starting UDP");
    digitalWrite(16, HIGH);//turn white LED on
  });

  disconnectedEventHandler = WiFi.onStationModeDisconnected([](const WiFiEventStationModeDisconnected& event)
  {
    Serial.println("WiFi disconnected");
    connected = false;
    digitalWrite(16, LOW);//turn white LED on
  });

  // Connect to WiFi network
  Serial.print("Connecting to ");
  Serial.println(ssid);
  WiFi.mode(WIFI_STA);
  //WiFi.config(ip, gateway, subnet); // Static IP Setup Info
  WiFi.begin(ssid, pass);

}
