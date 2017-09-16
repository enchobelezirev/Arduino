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

  String distanceString = String(distance);
  String result = distanceString + "&" + "0" + "&" + "19" +"&"+ "56";
  char copy[50];
  result.toCharArray(copy, 50);
  Serial.write(copy);
  delay(200);
}
