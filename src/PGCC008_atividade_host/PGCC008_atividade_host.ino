/*
      Código: HOST (access point)
      Componentes:
        - NodeMCU ESP8266 ou Raspberry Pi
      Versão 1.0 - Versão inicial via UDP ip padrão NodeMCU - 13/Abr/2022
      Por Noberto Maciel / Gustavo Coelho - PGCC Uefs - PGCC008
*/

#include <ESP8266WiFi.h>
#include <WiFiUdp.h>

// inicializa a conexão UDP
WiFiUDP udp;
String data;

void setup(){
   pinMode(D4, OUTPUT);
   digitalWrite(D4, 1);

   Serial.begin(115200);

   WiFi.mode(WIFI_AP);
   WiFi.softAP("redePGCC008", "");
   delay(2000);

   udp.begin(555);
}

void loop(){
   listen();
}

void listen(){
   if (udp.parsePacket() > 0){
       data = "";
       while (udp.available() > 0){
           char z = udp.read();
           data += z;
       }

       Serial.println(data);

       digitalWrite(D4, 0);
       delay(5);
       digitalWrite(D4, 1);
    }
}
