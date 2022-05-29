//Required libaries:
#include <Wire.h>
 
int red_light_pin= 7;// Sets which of the outputs the led strip is connected to
int green_light_pin = 8;
int blue_light_pin = 9;
int red = 255; // Turns the led strips off, 0 is on and 255 is off for each color
int blue = 255;
int green = 255;
int arrayy[1]; 
int go = false; 
int old_value  = 0;
int old_color[3];
int new_color[3];
void setup() { //Starts the setup function
  Wire.begin(0x8); //Deffine which SMBus channel which is being used
  Wire.onReceive(receiveEvent); // Activate a mode if data is being recived
  Serial.begin(9600);// Starts Serial
  pinMode(red_light_pin, OUTPUT);// Deffine the pins as outputs
  pinMode(green_light_pin, OUTPUT);
  pinMode(blue_light_pin, OUTPUT);
  arrayy[0] = 0;
}
 
// Function that executes whenever data is received from master
void receiveEvent(int howMany) {
  while (Wire.available()) { // loop through all but the last
    go = true;
    arrayy[0] = Wire.read();}} // Takes the data from the raspberry pi and put it in as a veriable


 


void loop(){
  if (old_value == 0){// set a value on startup for the colors
      old_color[0] = red;
      old_color[1] = blue;
      old_color[2] = green;}
  if  (old_value != arrayy[0]){
    old_value = arrayy[0];
    if (old_color[0]  + old_color [1] +  old_color [2] != 765){
      if (arrayy[0] == 1 && go == true){
      red = 102;
      blue = 0;
      green = 0;}
    if(arrayy[0] == 2 && go == true){
      red = 103;
      blue = 0;
      green = 0;}
    if(arrayy[0] == 3 && go == true){
      red = 51;
      blue = 0;
      green = 0;}
    if (arrayy[0] == 4 && go == true){
      red = 51;
      blue = 51;
      green = 0;} 
    if (arrayy[0] == 5 && go == true){
      red = 51;
      blue = 51;
      green = 0;}  
      if (arrayy[0] == 6 && go == true){
      red = 51;
      blue = 26;
      green = 0;}  
    if (arrayy[0] == 7 && go == true){
      red = 51;
      blue = 102;
      green = 0;}  
    if (arrayy[0] == 8 && go == true){
      red = 51;
      blue = 102;
      green = 0;}  
    if (arrayy[0] == 9 && go == true){
      red = 26;
      blue = 51;
      green = 0;}  
    if (arrayy[0] == 10 && go == true){
      red = 0;
      blue = 153;
      green = 77;}  
    if (arrayy[0] == 11 && go == true){
      red = 0;
      blue = 153;
      green = 77;}  
    if (arrayy[0] == 12 && go == true){
      red = 0;
      blue = 153;
      green = 77;}  
    if (arrayy[0] == 13 && go == true){
      red = 0;
      blue = 204;
      green = 102;}  
    if (arrayy[0] == 14 && go == true){
      red = 0;
      blue = 204;
      green = 102;}
    if (arrayy[0] == 15 && go == true){
      red = 0;
      blue = 204;
      green = 102;}  
    if (arrayy[0] == 16 && go == true){
      red = 153;
      blue = 0;
      green = 77;}  
    if (arrayy[0] == 17 && go == true){
      red = 153;
      blue = 0;
      green = 77;}  
    if (arrayy[0] == 18 && go == true){
      red = 255;
      blue = 102;
      green = 255;}  
    if (arrayy[0] == 19 && go == true){
      red = 153;
      blue = 0;
      green = 77;}  
    if (arrayy[0] == 20 && go == true){
      red = 153;
      blue = 0;
      green = 77;}  
    if (arrayy[0] == 21 && go == true){
      red = 255;
      blue = 102;
      green = 255;}  
    if (arrayy[0] == 22 && go == true){
      red = 153;
      blue = 0;
      green = 76;}  
    if (arrayy[0] == 23 && go == true){
      red = 204;
      blue = 0;
      green = 102;}  
    if (arrayy[0] == 24 && go == true){
      red = 255;
      blue = 0;
      green = 127;}  
    if (arrayy[0] == 25 && go == true){
      red = 255;
      blue = 51;
      green = 51;}  
    if (arrayy[0] == 26 && go == true){
      red = 255;
      blue = 51;
      green = 51;}  
    if (arrayy[0] == 27 && go == true){
      red = 255;
      blue = 102;
      green = 102;}  
    if (arrayy[0] == 28 && go == true){
      red = 235;
      blue = 166;
      green = 27;}  
    if (arrayy[0] == 29 && go == true){
      red = 235;
      blue = 166;
      green = 27;}  
    if (arrayy[0] == 30 && go == true){
      red = 216;
      blue = 165;
      green = 62;}  
    if (arrayy[0] == 31 && go == true){
      red = 73;
      blue = 11;
      green = 0;}  
    if (arrayy[0] == 32 && go == true){
      red = 73;
      blue = 11;
      green = 0;}  
    if (arrayy[0] == 33 && go == true){
      red = 35;
      blue = 16;
      green = 12;}  
    if (arrayy[0] == 34 && go == true){
      red = 41;
      blue = 0;
      green = 17;}  
    if (arrayy[0] == 35 && go == true){
      red = 41;
      blue = 0;
      green = 17;}  
    if (arrayy[0] == 36 && go == true){
      red = 0;
      blue = 0;
      green = 0;}
      new_color[0] = red;
      new_color[1] = blue;
      new_color[2] = green;
    }
    else{
            if (arrayy[0] == 1 && go == true){
      red = 102;
      blue = 0;
      green = 0;}
    if(arrayy[0] == 2 && go == true){
      red = 103;
      blue = 0;
      green = 0;}
    if(arrayy[0] == 3 && go == true){
      red = 51;
      blue = 0;
      green = 0;}
    if (arrayy[0] == 4 && go == true){
      red = 51;
      blue = 51;
      green = 0;} 
    if (arrayy[0] == 5 && go == true){
      red = 51;
      blue = 51;
      green = 0;}  
      if (arrayy[0] == 6 && go == true){
      red = 51;
      blue = 26;
      green = 0;}  
    if (arrayy[0] == 7 && go == true){
      red = 51;
      blue = 102;
      green = 0;}  
    if (arrayy[0] == 8 && go == true){
      red = 51;
      blue = 102;
      green = 0;}  
    if (arrayy[0] == 9 && go == true){
      red = 26;
      blue = 51;
      green = 0;}  
    if (arrayy[0] == 10 && go == true){
      red = 0;
      blue = 153;
      green = 77;}  
    if (arrayy[0] == 11 && go == true){
      red = 0;
      blue = 153;
      green = 77;}  
    if (arrayy[0] == 12 && go == true){
      red = 0;
      blue = 153;
      green = 77;}  
    if (arrayy[0] == 13 && go == true){
      red = 0;
      blue = 204;
      green = 102;}  
    if (arrayy[0] == 14 && go == true){
      red = 0;
      blue = 204;
      green = 102;}
    if (arrayy[0] == 15 && go == true){
      red = 0;
      blue = 204;
      green = 102;}  
    if (arrayy[0] == 16 && go == true){
      red = 153;
      blue = 0;
      green = 77;}  
    if (arrayy[0] == 17 && go == true){
      red = 153;
      blue = 0;
      green = 77;}  
    if (arrayy[0] == 18 && go == true){
      red = 255;
      blue = 102;
      green = 255;}  
    if (arrayy[0] == 19 && go == true){
      red = 153;
      blue = 0;
      green = 77;}  
    if (arrayy[0] == 20 && go == true){
      red = 153;
      blue = 0;
      green = 77;}  
    if (arrayy[0] == 21 && go == true){
      red = 255;
      blue = 102;
      green = 255;}  
    if (arrayy[0] == 22 && go == true){
      red = 153;
      blue = 0;
      green = 76;}  
    if (arrayy[0] == 23 && go == true){
      red = 204;
      blue = 0;
      green = 102;}  
    if (arrayy[0] == 24 && go == true){
      red = 255;
      blue = 0;
      green = 127;}  
    if (arrayy[0] == 25 && go == true){
      red = 255;
      blue = 51;
      green = 51;}  
    if (arrayy[0] == 26 && go == true){
      red = 255;
      blue = 51;
      green = 51;}  
    if (arrayy[0] == 27 && go == true){
      red = 255;
      blue = 102;
      green = 102;}  
    if (arrayy[0] == 28 && go == true){
      red = 235;
      blue = 166;
      green = 27;}  
    if (arrayy[0] == 29 && go == true){
      red = 235;
      blue = 166;
      green = 27;}  
    if (arrayy[0] == 30 && go == true){
      red = 216;
      blue = 165;
      green = 62;}  
    if (arrayy[0] == 31 && go == true){
      red = 73;
      blue = 11;
      green = 0;}  
    if (arrayy[0] == 32 && go == true){
      red = 73;
      blue = 11;
      green = 0;}  
    if (arrayy[0] == 33 && go == true){
      red = 35;
      blue = 16;
      green = 12;}  
    if (arrayy[0] == 34 && go == true){
      red = 41;
      blue = 0;
      green = 17;}  
    if (arrayy[0] == 35 && go == true){
      red = 41;
      blue = 0;
      green = 17;}  
    if (arrayy[0] == 36 && go == true){
      red = 0;
      blue = 0;
      green = 0;}
        
        
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