#include <CapacitiveSensor.h>

//LEDs
int led = 13; //LED areas
int led2 = 10;
int led3 = 12;
int led4 = 11;
int lled = 9;
int lled2 = 8;
int lled3 = 7;
int lled4 = 6;

int state = HIGH;
long time = 0;

//capacitive sensors
boolean yes; //capacitiveSensor1
boolean yes2;
boolean previous = false;
boolean previous2 = false;

int debounce = 300;

CapacitiveSensor   cs_4_2 = CapacitiveSensor(4, 2);        // 10M resistor between pins 4 & 2, pin 2 is sensor pin, add a wire and or foil if desired
// To add more sensors...//
CapacitiveSensor   cs_4_5 = CapacitiveSensor(4, 5);       // 10M resistor between pins 4 & 5, pin 6 is sensor pin, add a wire and or foil
//CapacitiveSensor   cs_4_8 = CapacitiveSensor(4,8);        // 10M resistor between pins 4 & 8, pin 8 is sensor pin, add a wire and or foil


void setup() {
  cs_4_2.set_CS_AutocaL_Millis(100000);  //Calibrate the sensor...
  //cs_4_5.set_CS_AutocaL_Millis(0xFFFFFFFF);
  //Serial.begin(9600);
  pinMode(led, OUTPUT);
  pinMode(led2, OUTPUT);
  pinMode(led3, OUTPUT);
  pinMode(led4, OUTPUT);
  pinMode(lled, OUTPUT);
  pinMode(lled2, OUTPUT);
  pinMode(lled3, OUTPUT);
  pinMode(lled4, OUTPUT);

}
void capacitive() {

  long total1 =  cs_4_2.capacitiveSensor(30);
  long total2 = cs_4_5.capacitiveSensor(30);

  if (total1 > 100) {
    yes = true;
  }
  else {
    yes = false;
  }

  if (total2 > 100) {
    yes2 = true;
  }
  else {
    yes2 = false;
  }
  //  Serial.print("first sensor:"); //for testing
  //  Serial.println(total1);
  //  Serial.print("second sensor:");
  //  Serial.println(total2);
}

void loop() {
  capacitive();
  if (yes == true && previous  == false && millis() - time > debounce && yes2 == true && previous2  == false) {
    if (state == LOW) {
      state = HIGH;
      digitalWrite(led, state); //right side, top first
      digitalWrite(lled, state); //left side, top first
      delay(500);
      digitalWrite(led2, state);
      digitalWrite(lled2, state);
      delay(500);
      digitalWrite(led3, state);
      digitalWrite(lled3, state);
      delay(500);
      digitalWrite(led4, state);
      digitalWrite(lled4, state);
    }
    else {
      state = LOW;
      time = millis();
      digitalWrite(led, state); //right side, top first
      digitalWrite(lled, state); //left side, top first
      delay(500);
      digitalWrite(led2, state);
      digitalWrite(lled2, state);
      delay(500);
      digitalWrite(led3, state);
      digitalWrite(lled3, state);
      delay(500);
      digitalWrite(led4, state);
      digitalWrite(lled4, state);
    }
  }

  if (yes == false && previous  == false && millis() - time > debounce && yes2 == true && previous2  == false) {
    if (state == LOW) {
      state = HIGH;
      digitalWrite(led, state); //right side, top first
      digitalWrite(lled, state); //left side, top first
      delay(500);
      digitalWrite(led2, state);
      digitalWrite(lled2, state);
      delay(500);
      digitalWrite(led3, state);
      digitalWrite(lled3, state);
      delay(500);
      digitalWrite(led4, state);
      digitalWrite(lled4, state);
    }
    else {
      state = LOW;
      time = millis();
      digitalWrite(lled4, state); //left side, top first
      delay(500);
      digitalWrite(led4, state);
      delay(500);
      digitalWrite(lled3, state);
      delay(500);
      digitalWrite(led3, state);
      delay(500);
      digitalWrite(lled2, state);
      delay(500);
      digitalWrite(led2, state);
      delay(500);
      digitalWrite(lled, state);
      delay(500);
      digitalWrite(led, state);
    }
  }
  if (yes == true && previous  == false && millis() - time > debounce && yes2 == false && previous2  == false) {
    if (state == LOW) {
      state = HIGH;
      digitalWrite(led, state); //right side, top first
      digitalWrite(lled, state); //left side, top first
      delay(500);
      digitalWrite(led2, state);
      digitalWrite(lled2, state);
      delay(500);
      digitalWrite(led3, state);
      digitalWrite(lled3, state);
      delay(500);
      digitalWrite(led4, state);
      digitalWrite(lled4, state);
    }
    else {
      state = LOW;
      time = millis();
      digitalWrite(led4, state); //left side, top first
      delay(500);
      digitalWrite(lled4, state);
      delay(500);
      digitalWrite(led3, state);
      delay(500);
      digitalWrite(lled3, state);
      delay(500);
      digitalWrite(led2, state);
      delay(500);
      digitalWrite(lled2, state);
      delay(500);
      digitalWrite(led, state);
      delay(500);
      digitalWrite(lled, state);
    }
  }

  previous = yes;
  previous2 = yes2;

  Serial.println(millis() - time);
  delay(10);


}
