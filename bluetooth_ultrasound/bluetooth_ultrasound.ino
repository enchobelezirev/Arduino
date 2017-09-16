#include <string.h> 
using namespace std;

char data = 0; 
const int trigPin = 9;
const int echoPin = 10;
// defines variables
long duration;
int distance;
void setup()
{
    Serial.begin(9600);   //Sets the baud for serial data transmission                               
    pinMode(13, OUTPUT);  //Sets digital pin 13 as output pin
    pinMode(trigPin, OUTPUT); // Sets the trigPin as an Output
    pinMode(echoPin, INPUT); // Sets the echoPin as an Input
}
void loop()
{
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  // Sets the trigPin on HIGH state for 10 micro seconds
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);
  // Reads the echoPin, returns the sound wave travel time in microseconds
  duration = pulseIn(echoPin, HIGH);
  // Calculating the distance
  distance= duration*0.034/2;
  // Prints the distance on the Serial Monitor
  char * b = (char*)&distance;
  char buffer1 [33];
  char test[] = "-1";
  char *intStr = itoa(distance, buffer1, 10);
  Serial.write(buffer1 + "&");
  Serial.flush();
  delayMicroseconds(10000);
//  Serial.write("Distance: ");
//  Serial.write(distance);
//  Serial.write("\n");
//      data = Serial.read();        //Read the incoming data & store into data
//      Serial.print(data);          //Print Value inside data in Serial monitor
//      Serial.print("\n");        
//      if(data == '1')              // Checks whether value of data is equal to 1
//         digitalWrite(13, HIGH);   //If value is 1 then LED turns ON
//      else if(data == '0')         //  Checks whether value of data is equal to 0
//         digitalWrite(13, LOW);    //If value is 0 then LED turns OFF
//   }
}
