#include <ESP8266WiFi.h>

const char* ssid = "Ammaji";
const char* password = "rajeshwari";
int reed_switch = 4;//D2
int reed_status;

const int trigPin = 12;
const int echoPin = 14;

//define sound velocity in cm/uS
#define SOUND_VELOCITY 0.034
#define CM_TO_INCH 0.393701

long duration;
float distanceCm;
float distanceInch;

const char* host = "maker.ifttt.com";

void setup() 
{
    Serial.begin(115200);
    Serial.println("Email from Node Mcu");
    delay(100);
    delay(1000);

    pinMode(trigPin, OUTPUT); // Sets the trigPin as an Output
    pinMode(echoPin, INPUT); // Sets the echoPin as an Input

   connectWiFi(); 

}

void loop() 
{   
      while((!(WiFi.status() == WL_CONNECTED)))
    {
      connectWiFi();
    }               
      WiFiClient client; 
      const int httpPort = 80;  
      if (!client.connect(host, httpPort)) 
      {  
         Serial.println("connection failed");  
         return;
      } 

  // Clears the trigPin
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  // Sets the trigPin on HIGH state for 10 micro seconds
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);
  
  // Reads the echoPin, returns the sound wave travel time in microseconds
  duration = pulseIn(echoPin, HIGH);
  
  // Calculate the distance
  distanceCm = duration * SOUND_VELOCITY/2;
  
  // Convert to inches
  distanceInch = distanceCm * CM_TO_INCH;

      if (distanceCm <= 8.00){
        Serial.println("SECURITY BREACH"); 
        String url = "https://maker.ifttt.com/trigger/sms/with/key/noBni71ah2UbE0bD26K6qHmtGOSL-GE_puFn_5VpSIb"; 
        Serial.print("Requesting URL: ");
        Serial.println(url);                 
        client.print(String("GET ") + url + " HTTP/1.1\r\n" + "Host: " + host + "\r\n" + "Connection: close\r\n\r\n"); 
      }
      else
      {
        Serial.println(" NO SECURITY BREACH");
      }
      
   reed_status = digitalRead(reed_switch);
   if (reed_status == 1)
        { 
            Serial.println("NOT SAFE, SECURITY BREACH"); 
            String url = "https://maker.ifttt.com/trigger/shreyas/with/key/noBni71ah2UbE0bD26K6qHmtGOSL-GE_puFn_5VpSIb"; 
            Serial.print("Requesting URL: ");
            Serial.println(url);                 
            client.print(String("GET ") + url + " HTTP/1.1\r\n" + "Host: " + host + "\r\n" + "Connection: close\r\n\r\n");            
         }                     
          else
          {
            Serial.println("SAFE"); 
          }          
       delay(1000);  
    while((!(WiFi.status() == WL_CONNECTED)))
    {
      connectWiFi();
    }              
}

void connectWiFi()
{ 
  int i=0;
  Serial.println("Connecting to WIFI");
  WiFi.begin(ssid, password);
  while((!(WiFi.status() == WL_CONNECTED)))
  {
    Serial.println(" - "); 
    i++;
    delay(300);
    if( i>10 )    
    { 
     connectWiFi();
    }
   }  
   Serial.println("");
   Serial.println("WiFi connected");
}
