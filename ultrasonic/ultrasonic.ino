/*
converts the DYP-ME007 sonar device to an equivalent of MB1240 XL-MaxSonar-EZ4
by Evan Allen
probably around September 2013
*/
// setup pins and variables for DYP-ME007 sonar device
int echoPin = 2; // DYP-ME007 echo pin (digital 2)
int initPin = 3; // DYP-ME007 trigger pin (digital 3)
unsigned long pulseTime = 0; // stores the pulse in Micro Seconds
unsigned long distance = 0; // variable for storing the distance (cm)
unsigned long volt = 0;
//setup
void setup() {
pinMode(9, OUTPUT); // sets pin 9 as output
pinMode(initPin, OUTPUT); // set init pin 3 as output
pinMode(echoPin, INPUT); // set echo pin 2 as input

// initialize the serial port, lets you view the
// distances being pinged if connected to computer
Serial.begin(9600);
}
// execute
void loop() {
digitalWrite(initPin, HIGH); // send 10 microsecond pulse
delayMicroseconds(10); // wait 10 microseconds before turning off
digitalWrite(initPin, LOW); // stop sending the pulse
pulseTime = pulseIn(echoPin, HIGH); // Look for a return pulse, it should be high as the pulse goes low-high-low
distance = (pulseTime/58);
volt = (distance/4);
//if (volt<5){
//  volt = 5;
//}
if (distance < 255) {
  analogWrite(9, volt); // Write current value to LED pins
  Serial.print("distance: ");
  Serial.println(distance, DEC);
  Serial.print("voltage: ");
  Serial.println(volt, DEC);
}
delay(100); // wait 100 milli seconds before looping again
}
