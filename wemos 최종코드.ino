#include <DHT.h>
#include <ESP8266WiFi.h>
 

String apiKey = "ZBUQ141U25IVE0QR"; //apikey
const char* ssid = "DimiFi 2G2"; //ssid
const char* password = "newdimigo"; //password
const char* server = "api.thingspeak.com"; 
 
#define DHTPIN D2
#define DHTTYPE DHT11 
 
DHT dht(DHTPIN, DHTTYPE);
WiFiClient client;
 
void setup() 
{
Serial.begin(115200);
delay(10);
dht.begin();
 
WiFi.begin(ssid, password);
 
Serial.println();
Serial.println();
Serial.print("Connecting to ");
Serial.println(ssid);
 
WiFi.begin(ssid, password);
 
while (WiFi.status() != WL_CONNECTED) 
{
delay(500);
Serial.print(".");
}
Serial.println("");
Serial.println("WiFi connected");
 
}
 
void loop() 
{
float g = analogRead(A0); //ground
float h = dht.readHumidity(); //humidity
float t = dht.readTemperature(); //temperature
if (isnan(h) || isnan(t)) 
{
Serial.println("DHT Sensor Error");
return;
}
 
if (client.connect(server,80)) {
String postStr = apiKey;
postStr +="&field1=";
postStr += String(t);
postStr +="&field2=";
postStr += String(h);
postStr +="&field3=";
postStr += String(g);
postStr += "\r\n\r\n";
 
client.print("POST /update HTTP/1.1\n");
client.print("Host: api.thingspeak.com\n");
client.print("Connection: close\n");
client.print("X-THINGSPEAKAPIKEY: "+apiKey+"\n");
client.print("Content-Type: application/x-www-form-urlencoded\n");
client.print("Content-Length: ");
client.print(postStr.length());
client.print("\n\n");
client.print(postStr);
 
Serial.print("Temperature: ");
Serial.print(t);
Serial.print(" degrees Celsius Humidity: ");
Serial.print(h);
Serial.print("ground");
Serial.print(g);
Serial.println("Sending data to Thingspeak");
}
client.stop();
 
Serial.println("Waiting 20 secs");

delay(20000);
}
