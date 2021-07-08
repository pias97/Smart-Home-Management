//Name : Ranabir Devnath  
//ID   : 011 171 288
// Node 1 code

const int echoPin = 2; // Echo Pin of Ultrasonic Sensor
const int pingPin = 3; // Trigger Pin of Ultrasonic Sensor

#include <Wire.h>
#include <VirtualWire.h>
#include <dht.h>
dht DHT; // making objecr of DHT 11 (DHT the object)
void setup() {
  Serial.begin(9600);
  pinMode(pingPin, OUTPUT); // initialising pin 3 as output
  pinMode(echoPin, INPUT); // initialising pin 2 as input



  Serial.println("****Node 1 Monitor*****");
  // Start the I2C Bus as Master
  Wire.begin(); 
}

void loop() {

  ///////// Temperature Measure /////////
  DHT.read11(13); /// reading the temperature of humidity from pin 13 using DHT
  int temp=DHT.temperature;
  Serial.print("Temperature Measure: ");
  Serial.print(temp);
  Serial.print("Celcius");
  Serial.println();
  Serial.println();


  ////////// Distance measure Code ////////////////////
  long duration, inches, meter;
  
  digitalWrite(pingPin, LOW);
  delayMicroseconds(2);
  
  digitalWrite(pingPin, HIGH);
  delayMicroseconds(10);
  
  digitalWrite(pingPin, LOW);
  
  duration = pulseIn(echoPin, HIGH); // using pulsin function to determine total time
  inches = microsecondsToInches(duration); // calling method
  meter= inches/39.37;
  Serial.print("Distance Measure: ");
  Serial.print(meter);
  Serial.print(" Meter ");
  Serial.println();


  /////////// Sending Temperature to Node 2 /////////////////////

  Wire.beginTransmission(9); // transmit to device #9
  Wire.write(temp);              // sends inches 
  Wire.endTransmission();    // stop transmitting

  /////////// Sending Distance to Node 3/////////////////////

  Wire.beginTransmission(12); // transmit to device #12
  Wire.write(meter);              // sends meter
  Wire.endTransmission();    // stop transmitting


 
  delay(1000);
}

long microsecondsToInches(long microseconds) // method to covert microsec to inches 
{
 return microseconds / 74 / 2;
}
