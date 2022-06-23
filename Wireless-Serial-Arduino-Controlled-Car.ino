
#include <AFMotor.h>

AF_DCMotor right_motor(3);
AF_DCMotor left_motor(2);

int speed_val =150;

void setup() {
  Serial.begin(9600);

  right_motor.setSpeed(speed_val);
  right_motor.run(RELEASE);
  
  left_motor.setSpeed(speed_val);
  left_motor.run(RELEASE);
}

bool ser=false;

void loop() {


  if(Serial.available() > 0)  {
int incomingData;
  incomingData = Serial.readStringUntil('\n').toInt();
  

    switch(incomingData) { 

        case 0:
              if(ser){
           Serial.println("STOP");
        }
           right_motor.run(RELEASE);
           left_motor.run(RELEASE);

           break;

        case 1:
           // handle ‘1’
           if(ser){
           Serial.println("FORWARD");
           }
            right_motor.run(FORWARD);
            right_motor.setSpeed(speed_val);  
              
            left_motor.run(FORWARD);
            left_motor.setSpeed(speed_val);  

           break;

        case 2:
           // handle ‘2’
           if(ser){
           Serial.println("BACKWARD");
           }
            right_motor.run(BACKWARD);
            right_motor.setSpeed(speed_val);  
              
            left_motor.run(BACKWARD);
            left_motor.setSpeed(speed_val);  
           break;

        case 3:
           // handle ‘3’
           if(ser){
           Serial.println("RIGHT");
           }
            right_motor.run(BACKWARD);
            right_motor.setSpeed(speed_val);
             
            left_motor.run(FORWARD);
            left_motor.setSpeed(speed_val);  
           break;
           
        case 4:
           // handle ‘4’
           if(ser){
           Serial.println("LEFT");
           }
            right_motor.run(FORWARD);
            right_motor.setSpeed(speed_val); 
            
            left_motor.run(BACKWARD);
            left_motor.setSpeed(speed_val);  
           break;
        case 5:
           // handle ‘5’
           if(ser){
            ser= false;
           }else{
            ser=true;
            Serial.println("OUT");
           }
           break;  


          case 6:
           // handle ‘6’
           if(ser){
           Serial.println("CONNECTED");
           }
            Serial.println(6);
           break;
        default:
        if(ser){
           Serial.println("INVALID");
        }


           break;
   }
 }
  

  

}
