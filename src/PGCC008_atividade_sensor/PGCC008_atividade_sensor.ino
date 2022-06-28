/*
      Código: SENSOR (station)
      Componentes:
        - NodeMCU ESP8266
        - Sensor UVM-30a
        - Sensor SW-420
      Versão 1.0 - Versão inicial via UDP ip padrão NodeMCU - 13/Abr/2022
      Por Noberto Maciel / Gustavo Coelho - PGCC Uefs - PGCC008
*/

// Inclusão das bibliotecas
#include <ESP8266WiFi.h>
#include <ESP8266WebServer.h>
#include <WiFiUdp.h>
#include <DateTime.h>
#include <TimeElapsed.h>
#include <DateTimeTZ.h>
#include <ESPDateTime.h>

// Configração do WiFi
char* ssid = "Palmeiras";  // SSID Wifi da rede principal
char* pass = "26081914";             // Senha Wifi da rede principal
char* ip = "10.0.0.129";
int porta = 555;

// sensor UV
#define sensorUVPin A0 // define analogical pin (A0) to sensorUVPin
int dataSensorUV = 0;
int indexUV = 0;

// sensor Vibration
#define sensorVBPin D0 // define digital pin (D0) to sensorVBPin 
int dataSensorVB = 0;

// localization
float latitude = -12.197422000000014;
float longitude = -38.96674600000001;
char* timezone = "America/Bahia";

// Período de leitura de dados do sensor
float T_sensor = 0.5;

// Start udp wifi
WiFiUDP udp;


void setup() {
  // Start Serial port
  Serial.begin(115200);
  delay(300);
  
  // Start WiFi connection
  WiFi.mode(WIFI_STA);
  WiFi.begin(ssid, pass);

  // Start TimeZone
  DateTime.setTimeZone(timezone);
  DateTime.begin(/* timeout param */);
  if (!DateTime.isTimeValid()) {
    Serial.println("Failed to get time from server.");
  }
}

void loop() {
   conecta(); // try to connect host
   enviaDados(); // send data to host
}

void readSensorVB(){
  // read UV sensor to variable
  dataSensorVB = digitalRead(sensorVBPin);
}

void readSensorUV(){
  byte numOfReadings = 5; // define readings number
  dataSensorUV = 0;
  for (int i=0; i< numOfReadings; i++){
    dataSensorUV += analogRead(sensorUVPin); // read sensor and sum the readings
  }
  dataSensorUV /= numOfReadings; // extract the average
  dataSensorUV = (dataSensorUV * (3.3 / 1023.0))*1000; // calculate the UV index (reading range equal 0 to 1023 , where 0=0v and 1023=3.3v) in mv (*1000)
  indexCalculate();
}

void indexCalculate(){
    if (dataSensorUV < 227) indexUV = 0; // UV index vs milivolts table equivalence
    else if (227 <= dataSensorUV && dataSensorUV < 318) indexUV = 1;
    else if (318 <= dataSensorUV && dataSensorUV < 408) indexUV = 2;
    else if (408 <= dataSensorUV && dataSensorUV < 503) indexUV = 3;
    else if (503 <= dataSensorUV && dataSensorUV < 606) indexUV = 4;    
    else if (606 <= dataSensorUV && dataSensorUV < 696) indexUV = 5;
    else if (696 <= dataSensorUV && dataSensorUV < 795) indexUV = 6;
    else if (795 <= dataSensorUV && dataSensorUV < 881) indexUV = 7; 
    else if (881 <= dataSensorUV && dataSensorUV < 976) indexUV = 8;
    else if (976 <= dataSensorUV && dataSensorUV < 1079) indexUV = 9;  
    else if (1079 <= dataSensorUV && dataSensorUV < 1170) indexUV = 10;
    else indexUV = 11;
}

void conecta(){
   if (WiFi.status() != WL_CONNECTED){    // check if connected
      WiFi.begin(ssid, pass);             // try to connect to host
      delay(5000);                        // waint to connection
      Serial.println(".");                // print result to Serial Port
      Serial.print("Rede WiFi: ");
      Serial.println(ssid);
      Serial.print("Endereço IP: ");
      Serial.println(WiFi.localIP());
   }
}

void enviaDados(){
   if (WiFi.status() == WL_CONNECTED){     // check if connected to host
      if(udp.beginPacket(ip, porta)){      // start UDP connection
          delay(T_sensor*1000);
          
          int timestamp = DateTime.now();  // get timestamp
          
          readSensorVB();                  // get sensor data function
          readSensorUV();
          
          // concat sensors data
          String data = String(timestamp) + "@" + String(latitude) + "@" + String(longitude) + "@" + String(indexUV) + "@" + String(dataSensorVB);
          
          Serial.println(".");             // print result to Serial Port
          Serial.println("Enviando UDP:");
          Serial.println(data);
          Serial.println(udp.remoteIP());  // print IP udp host to Serial Port
          udp.println(data);
          udp.endPacket();                 // send UDO package
      }
   }
}
