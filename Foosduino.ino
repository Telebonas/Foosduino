#define SENSORPIN 2
 
// variables will change:
int sensorState = 0, lastState=0;         // variable for reading the pushbutton status
 
void setup() {
  // initialize the sensor pin as an input:
  pinMode(SENSORPIN, INPUT);     
  digitalWrite(SENSORPIN, HIGH); // turn on the pullup
  
  Serial.begin(9600);
}
 
void loop(){
  // read the state of the pushbutton value:
  handleBreakBeamUpdates();
}

void handleBreakBeamUpdates(){
   sensorState = digitalRead(SENSORPIN);
 
  // check if the sensor beam is broken
  // if it is, the sensorState is LOW:
  
  if (sensorState && !lastState) {
    Serial.println("Unbroken");
  } 
  if (!sensorState && lastState) {
    Serial.println("Broken");
  }
  lastState = sensorState;
}
