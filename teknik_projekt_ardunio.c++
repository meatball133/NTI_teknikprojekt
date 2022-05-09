#include <Wire.h>
 
int red_light_pin= 7;
int green_light_pin = 8;
int blue_light_pin = 9;
int red = 255;
int blue = 255;
int green = 255;
int arrayy[1];
int go = false; 
int old_value  = 0;
int old_color[3];
int new_color[3];
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
    go = true;
    arrayy[0] = Wire.read();}}


 


void loop(){
  if (old_value == 0){
      old_color[0] = red;
      old_color[1] = blue;
      old_color[2] = green;
  Serial.print("1");}
  if  (old_value != arrayy[0]){
    old_value = arrayy[0];
    Serial.print("2");
    if (old_color[0]  + old_color [1] +  old_color [2] != 765){
       if (arrayy[0] == 12 && go == true){
        Serial.print("3");
    	red = 0;
    	blue = 0;
    	green = 255;
    }
      if (arrayy[0] == 10 && go == true){
      	red = 255;
      	blue = 255;
        green = 0;}
      new_color[0] = red;
      new_color[1] = blue;
      new_color[2] = green;
    }
    else{
      Serial.print("hi");
      if (arrayy[0] == 12 && go == true){
      red = 0;
      blue = 0;
      green = 255;
      Serial.print("4");
      
  }
      if (arrayy[0] == 10 && go == true){
      red = 255;
      blue = 255;
      green = 0;
      Serial.print("4");}
        
        
     old_color[0] = red;
     old_color[1] = blue;
     old_color[2] = green;
    }
  }

  if (old_color != new_color && new_color != 0){
    if (old_color[0] > new_color[0]){
      old_color[0] = old_color[0]  -1;
    }
    if (old_color[0] < new_color[0]){
      old_color[0] = old_color[0]  +1;
    }
    if (old_color[1] > new_color[1]){
      old_color[1] = old_color[1]  -1;
    }
    if (old_color[1] < new_color[1]){
      old_color[1] = old_color[1]  +1;
    if (old_color[2] > new_color[2]){
      old_color[2] = old_color[2]  -1;
    }
    if (old_color[2] < new_color[2]){
      old_color[2] = old_color[2]  +1;
    }
  }

  	RGB_color(old_color[0],old_color[1],old_color[2]);
	delay(100);
    arrayy[0] = 10;
}
}

void RGB_color(int red_light_value, int green_light_value, int blue_light_value){
  if (go == true){
  Serial.print(red_light_value);
  analogWrite(red_light_pin, red_light_value);
  analogWrite(green_light_pin, green_light_value);
  analogWrite(blue_light_pin, blue_light_value);}}