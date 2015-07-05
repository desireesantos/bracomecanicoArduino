#include <Servo.h> 
#define BAUDRATE 9600

Servo bottonBase;
Servo rightArm;
Servo leftArm;
Servo arm;
int pos;
int pin3 = 3;
int pin5 = 5;
int pin6 = 6;
int pin11 = 11;
int velocity = 10;

void setup() {   
 Serial.begin(BAUDRATE);
 leftArm.attach(pin3);
 bottonBase.attach(pin5);
 rightArm.attach(pin6);
 arm.attach(pin11); 	
} 
 
void loop() { 
 if(Serial.available() > 0){
   char command = Serial.read();
        if(command == 'R')
  	    right();
        if(command == 'L')
  	    left();

        if(command == 'F')
	     front(); 
        if(command == 'B')
	    back();

        if(command == 'U')
	    up(); 
        if(command == 'D')
	    down(); 

        if(command == 'O')
	    armOpen();  
        if(command == 'C')
	    armClose();
 } 
}


void left(){
  	for(pos = 0; pos < 180; pos += velocity) {                                  
    	bottonBase.write(pos); 
    	delay(10);                      
  	} 
} 
void right(){
  	for(pos = 180; pos>=1; pos-= velocity) {                                
    	bottonBase.write(pos);    
    	delay(10);                       
  	}
}
  
void front(){
      for(pos = 1; pos < 180; pos+= velocity) {                                
    	rightArm.write(pos);    
    	delay(10);     
}
}

void back(){
     for(pos = 180; pos>=1; pos-= velocity) {                                
    	rightArm.write(pos);     
    	delay(10);     
}
} 

void up(){
      for(pos = 1; pos < 180; pos+= velocity) {                                
    	leftArm.write(pos);    
    	delay(10);     
}
}

void  down(){
     for(pos = 180; pos>=1; pos-= velocity) {                                
    	leftArm.write(pos);     
    	delay(10);     
}
}

void armOpen(){
  for(pos = 0; pos<180; pos+= velocity) {  
        Serial.println("Entrou");    
    	arm.write(pos);     
    	delay(10);     
 }
}

void armClose(){
  for(pos= 180; pos >0; pos-= velocity) { 
        Serial.println("OI");    
    	arm.write(pos);     
    	delay(10);     
 }
}


