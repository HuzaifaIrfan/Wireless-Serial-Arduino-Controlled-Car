

#include <LiquidCrystal.h>


const int rs = 8, en = 9, d4 = 4, d5 = 5, d6 = 6, d7 = 7;
LiquidCrystal lcd(rs, en, d4, d5, d6, d7);


const int Analog_Button_Pin = A0; 


int adc_key_val[5] ={50, 200, 400, 600, 800 };
int NUM_KEYS = 5;
int adc_key_in;
int key=-1;
int oldkey=-1;


int get_key(unsigned int input)
{
    int k;
    for (k = 0; k < NUM_KEYS; k++)
    {
      if (input < adc_key_val[k])
      {
        return k;
      }
    }   
    if (k >= NUM_KEYS)k = -1;  // No valid key pressed
    return k;
}

bool is_connected=false;

void setup() {
  // put your setup code here, to run once:
  pinMode(Analog_Button_Pin, INPUT_PULLUP);  // set pull-up on analog pin 0
  Serial.begin(9600);

    lcd.begin(16, 2);
    
  lcd.clear();
  lcd.setCursor(0, 0);
  lcd.print("Arduino Car");
  lcd.setCursor(0, 1);
  lcd.print("Initializing");
  Serial.println(6);

}

void display_msg(String msg){
    lcd.clear();
  lcd.setCursor(0, 0);
  lcd.print("Arduino Car ");
  if (is_connected){
    lcd.print("Con");
  }
  lcd.setCursor(0, 1);
  lcd.print(msg);
}

void loop() {



if(is_connected){
   adc_key_in = analogRead(Analog_Button_Pin);    // read the value from the sensor 
   key = get_key(adc_key_in);  // convert into key press
   if (key != oldkey)   // if keypress is detected
   {
     delay(50);  // wait for debounce time
     adc_key_in = analogRead(Analog_Button_Pin);    // read the value from the sensor 
     key = get_key(adc_key_in);    // convert into key press
     if (key != oldkey)    
     {   
      oldkey = key;
     
//  Serial.println(key);

// Right

   if (key == 0){
Serial.println(3);
    display_msg("  RIGHT");
   }

// Up
   if (key == 1){
    Serial.println(1);
    display_msg("  UP");
   }

// Down

   if (key == 2){
    Serial.println(2);
   display_msg("  DOWN");
   }

// Left

   if (key == 3){

Serial.println(4);
    display_msg("  LEFT");
   }

//   Select key

 if (key == 4){
  Serial.println(0);
  display_msg("  STOP");
 }

     }
   }

  
}else{
  delay(200);
  Serial.println(6);
}

   

     if(Serial.available() > 0)  {
int incomingData;
  incomingData = Serial.readStringUntil('\n').toInt();

switch(incomingData){
  
case 6:
  is_connected=true;
  display_msg("  Connected");
break;
default:
break;
     }
     }

}
