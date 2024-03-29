/*
ARDUINO UNO R3 + DMX SHIELD CTC-DRA-10-R2  + SPOTLIGHT RGB 4 COLORS + BUTTONS PULLUP
----------------------------------------------------------
DMX SHIELD CTC-DRA-10-R2  
jumpers config:
EN(run) <==  EN¯ (updt fw) ! Please For update firmware disconect battery 7-12v only usb 3.5v or arduino can dead !
Slave   ==>  DE  (master)
TX-io   <==  TX-uart
RX-io   <==  RX-uart
Pins 2,3,4 are used to transmit DMX signals
xlr output to xlr input rgb
-----------------------------------------------------------
SPOTLIGHT RGB 4 COLORS dmx commands
Spotlight mode dmx512 option menu D001 
1 CH  TOTAL DIMMING  0-255 : 0-100%
2 CH  TOTAL STROBE   0-2 : Reserved
                     3-191 : Pulse Strobe (Slow to Fast)
                     192-255 : Random Strobe (Speed from slow to fast)
3 CH  FUNCTION       0-50 : DMX channel control 
      SELECCTION     51-100 : Jump change
                     101-150 : Gradient
                     151-200 : Pulses
                     201-255 : Change of voice color combination                    
4 CH FUNTIONAL SPEED 0-255 : (Speed is slow to fast)
5 CH R DIMMING       0-255 : 0-100% (Linear dimming)
6 CH G DIMMING       0-255 : 0-100% (Linear dimming)
7 CH B DIMMING       0-255 : 0-100% (Linear dimming)
8 CH W DIMMING       0-255 : 0-100% (Linear dimming)
---------------------------------------------------------
Arduino buttons pullup hardware layout:
5V___Button____R10k ___Gnd
           |___Arduino pin 5,6,7        
                   
pin 5,6,7 buttons 
pin 13 led 
--------------------------------------------------------- 
Library DmxSimple 
https://github.com/PaulStoffregen/DmxSimple 
*/
#include <DmxSimple.h>

const int buttonPin1 = 5;   // buttons    
const int buttonPin2 = 6;   // buttons    
const int buttonPin3 = 7;   // buttons    
const int ledPin = 13;      // Pin Led push indicator

int buttonState1 = 0; 
int buttonState2 = 0; 
int buttonState3 = 0;    

void setup() {

int buttonState1 = 0; 
int buttonState2 = 0; 
int buttonState3 = 0;    
  
pinMode(2, OUTPUT);
digitalWrite(2, HIGH);
DmxSimple.usePin(4);
DmxSimple.maxChannel(8); //my number of channels

}
void loop() 
{
 buttonState1 = digitalRead(buttonPin1);
 buttonState2 = digitalRead(buttonPin2);
 buttonState3 = digitalRead(buttonPin3);

    if (buttonState1 == LOW)  
      { 
       digitalWrite(ledPin, HIGH); // led pin13 on    
       DmxSimple.write(3, 200);    // mode pulses
       DmxSimple.write(4, 252);    // increment speed
       digitalWrite(ledPin, LOW);  // led pin13 off 
      }

    if (buttonState2 == LOW)  
      { 
       digitalWrite(ledPin, HIGH); 
       DmxSimple.write(3, 200);
       DmxSimple.write(4, 253);  
       digitalWrite(ledPin, LOW);
      }
      
    if (buttonState3 == LOW)  
      { 
       digitalWrite(ledPin, HIGH);       
       DmxSimple.write(3, 200);
       DmxSimple.write(4, 255);
       digitalWrite(ledPin, LOW);
      }

}
