#include <Wire.h>
 
int red_light_pin= 7;
int green_light_pin = 8;
int blue_light_pin = 9;
int red = 255;
int blue = 255;
int green = 255;
int arrayy[1];
int x = 0;
int go = false;
void setup() {
  Wire.begin(0x8);
  Wire.onReceive(receiveEvent);
  Serial.begin(9600);
  pinMode(red_light_pin, OUTPUT);
  pinMode(green_light_pin, OUTPUT);
  pinMode(blue_light_pin, OUTPUT);
  arrayy[0] = 0;
}
 
// Function that executes whenever data is received from master
void receiveEvent(int howMany) {
  while (Wire.available()) { // loop through all but the last
    x= 0;
    go = true;
    arrayy[0] = Wire.read();}}


 


void loop() {
  if (arrayy[0] == 12 && go == true){
    red = 0;
    blue = 0;
    green = 255;
  }
  if(arrayy[0] == 6 && go true){
    red = 0;
    blue = 0;
    green = 0;
  }

  RGB_color(red, blue, green);

}


void RGB_color(int red_light_value, int green_light_value, int blue_light_value)
 {
  if (go == true){
    Serial.print(green_light_value);
  analogWrite(red_light_pin, red_light_value);
  analogWrite(green_light_pin, green_light_value);
  analogWrite(blue_light_pin, blue_light_value);}}