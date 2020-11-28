#include <PulseSensorPlayground.h>
#define USE_ARDUINO_INTERRUPTS true
#include <PulseSensorPlayground.h>

const int PulseWire = A0;
int Threshold = 550;
int relay=12;

PulseSensorPlayground pulseSensor;

void setup() {
  pinMode(relay,OUTPUT);
  pulseSensor.analogInput(PulseWire);
  pulseSensor.setThreshold(Threshold);
  if (pulseSensor.begin()==1) {
  Serial.println("We created a pulseSensor Object !");
  }
}

void loop() {
  int myBPM = pulseSensor.getBeatsPerMinute();
  if (pulseSensor.sawStartOfBeat() && myBPM<125) {
  Serial.println("♥ A HeartBeat Happened ! ");
  Serial.print("BPM: ");
  Serial.println(myBPM);

  if(myBPM>90)
  { 
    Serial.println("Attack!");
    digitalWrite(relay,HIGH);
    delay(5000);
    digitalWrite(relay,LOW);
    delay(5000);
  }

 }
delay(20);
}
