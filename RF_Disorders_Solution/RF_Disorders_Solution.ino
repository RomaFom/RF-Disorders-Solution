int pin_LEDgreen = 10;
int pin_LEDyellow = 9;

int pin_LEDred=11;
int pin_LEDblue=12;

int pin_switch1 = 2;
int pin_switch2=4;

// variables to hold the new and old switch states
boolean oldSwitchState1 = LOW;
boolean newSwitchState1 = LOW;

boolean oldSwitchState2 = LOW;
boolean newSwitchState2 = LOW;
byte state1 = 0;
byte state2=0;
int time = 500;


int startPressed1 = 0;    // the moment the button was pressed
int startPressed2 = 0;    // the moment the button was pressed

int endPressed1 = 0;      // the moment the button was released
int endPressed2 = 0;      // the moment the button was released

int holdTime1 = 0;        // how long the button was hold
int holdTime2 = 0;        // how long the button was hold



int idleTime = 0; 



void setup()
{
  Serial.begin(9600);
  pinMode(pin_LEDgreen, OUTPUT);    digitalWrite(pin_LEDgreen, LOW);
  pinMode(pin_LEDyellow, OUTPUT);   digitalWrite(pin_LEDyellow, LOW);
  pinMode(pin_LEDred, OUTPUT);   digitalWrite(pin_LEDred, LOW);
  pinMode(pin_LEDblue, OUTPUT);   digitalWrite(pin_LEDblue, LOW);
  
  pinMode(pin_switch1, OUTPUT);
  pinMode(pin_switch2, OUTPUT);
}

void Gate(byte& state,boolean& oldSwitchState, boolean& newSwitchState, int pin1, int pin2){
   
      Serial.println("Gate Start"); 
      Serial.println(newSwitchState); 
      state++;
      if (state > 2) {
        state = 1;
      }
      
      digitalWrite(pin1, LOW);
      digitalWrite(pin2, LOW);
      
      if (state == 1) {
        digitalWrite(pin1, HIGH);
        delay(time);
        digitalWrite(pin1, LOW);
      }
      if (state == 2) {
        digitalWrite(pin2, HIGH);
        delay(time);
        digitalWrite(pin2, LOW);
        
      }
   
    //}
    newSwitchState=LOW;
    Serial.println("Gate End"); 
    Serial.println(newSwitchState); 


  }

void updateState(int& startPressed,byte& state,boolean& oldSwitchState, boolean& newSwitchState, int pin1, int pin2,int& endPressed,int& holdTime, int& pin_switch) {
  if (newSwitchState == HIGH) {
      startPressed = millis();
  while(true){

    newSwitchState=digitalRead(pin_switch);
      if(newSwitchState == LOW){
          endPressed=millis();
          break;
  }
  }

  if(endPressed-startPressed>100){
    Serial.println("WORKING"); 
    Gate(state,oldSwitchState,newSwitchState,pin1,pin2);
  }
   }
    }



void loop(){

newSwitchState1 = digitalRead(pin_switch1);
newSwitchState2 = digitalRead(pin_switch2);

if ( newSwitchState1 == HIGH ){
  updateState(startPressed1,state1,oldSwitchState1,newSwitchState1,10,9,endPressed1,holdTime1,pin_switch1);
}

if ( newSwitchState2 == HIGH ){
   updateState(startPressed2,state2,oldSwitchState2,newSwitchState2,11,12,endPressed2,holdTime2,pin_switch2);
     

}
}
