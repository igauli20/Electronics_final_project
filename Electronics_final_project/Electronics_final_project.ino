
const int flexindex = A2;
const int flexmiddle = A3;
const int flexring = A4;
const int flexthumb = A5;

const int rightWheelRelay = 9;      //Controls the relay that communicates to the right wheel
const int leftWheelRelay = 8;       //Controls the relay that communicates to the left wheel
const int mainRelayLogic = 7;       //Controsl the relay that supplies power to the rest of the relays
//const int motorRightLogic2 = 6;

int initialflexindex = 0;
int initialflexmiddle = 0;
int initialflexring = 0;
int initialflexthumb = 0;

void Initialize();
void Forward();
void RightTurn();
void LeftTurn();
void Reverse();


void setup() {
     
     Serial.begin(9600);
     pinMode(rightWheelRelay, OUTPUT); 
     pinMode(leftWheelRelay, OUTPUT);
     pinMode(mainRelayLogic, OUTPUT);
     Initialize();
}

void loop() 
{
   int flexpositionindex = analogRead(flexindex);
   int flexpositionmiddle = analogRead(flexmiddle);
    
   if(flexpositionindex >= (initialflexindex + 100)){
    Forward();
   }
   else if (flexpositionmiddle >= (initialflexmiddle + 100)){
    LeftTurn();
   }
   else
      digitalWrite(mainRelayLogic, LOW);

}

void Initialize(){

   initialflexindex = analogRead(flexindex);
   initialflexmiddle = analogRead(flexmiddle);
}

void Forward(){
    //Send logic to the wheel so that they know what to do before power is supplied
     
    Serial.println("Low");
    digitalWrite(rightWheelRelay, HIGH);
    digitalWrite(leftWheelRelay, HIGH);
    //Supply power
    digitalWrite(mainRelayLogic, HIGH); 
    
  
}

void LeftTurn(){
    //Send logic to the wheel so that they know what to do before power is supplied
    Serial.println("Tank");
    digitalWrite(rightWheelRelay, LOW);
    digitalWrite(leftWheelRelay, HIGH);
    //Supply power
    digitalWrite(mainRelayLogic, HIGH);
}

void RightTurn(){
    //Send logic to the wheel so that they know what to do before power is supplied
    Serial.println("Tank");
    digitalWrite(rightWheelRelay, HIGH);
    digitalWrite(leftWheelRelay, LOW);
    //Supply power
    digitalWrite(mainRelayLogic, HIGH);
  
}

void Reverse(){
    //Send logic to the wheel so that they know what to do before power is supplied
    Serial.println("Backing up");
    digitalWrite(rightWheelRelay, LOW);
    digitalWrite(leftWheelRelay, LOW);
    //Supply power
    digitalWrite(mainRelayLogic, HIGH);
  
}



