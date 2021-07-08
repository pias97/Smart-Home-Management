//Name : Ranabir Devnath  
//ID   : 011 171 288 
// Node 3 code

#include <Wire.h>
int x=0;


void setup() {
  pinMode(10, OUTPUT); //RED 
  pinMode(9,OUTPUT); //GREEN
  pinMode(8,OUTPUT); //BLUE 
  // Start the I2C Bus as Slave on address 12
  Wire.begin(12); 
  // Attach a function to trigger when something is received.
  Wire.onReceive(receiveEvent);
  Serial.begin(9600);
  Serial.println("Node 3 Reading");
}

void receiveEvent(int bytes) {
  x = Wire.read();    // read one character from the I2C
}

void loop() {
   Serial.print("Distance Received: ");
   Serial.print(x);
   Serial.println(" Meter");
   Serial.println();

    
   if(x<=4)
   {
      digitalWrite(10, 0);
      digitalWrite(9, 0);
      digitalWrite(8, 255);
   }
    if(x==5)
   {
      digitalWrite(10, 130);
      digitalWrite(9, 0);
      digitalWrite(8, 100);
   }
   if(x==6)
   {
      digitalWrite(10, 90);
      digitalWrite(9, 0);
      digitalWrite(8, 170);
   }
   if(x==7)
   {
      digitalWrite(10, 60);
      digitalWrite(9, 0);
      digitalWrite(8, 200);
   }
   if(x==8 || x>8)
   {
      digitalWrite(10, 255);
      digitalWrite(9, 0);
      digitalWrite(8, 0);
   }
 
 delay(1000);
}
