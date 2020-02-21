// animation code for LED Open Sign
// by Seth Kerr


// Seth the open letter pins to control each led array
const int oPin = PD2;
const int pPin = PD3;
const int ePin = PD4;
const int nPin = PD5;

// Animation selection pins
const int animation1 = PD6;
const int animation2 = PD7;

// Set the initial LED states
int oState = LOW;
int pState = LOW;
int eState = LOW;
int nState = LOW;

// Delay timer 
unsigned long previousMillis = 0;

// Set the interval to 1 second or 1000msec
const long interval = 1000;

void setup() {
  // Set the letter pins to outputs
  pinMode(oPin, OUTPUT);
  pinMode(pPin, OUTPUT);
  pinMode(ePin, OUTPUT);
  pinMode(nPin, OUTPUT);

  // set the animation control signal to input with internal pullup resistors
  pinMode(animation1, INPUT_PULLUP);
  pinMode(animation2, INPUT_PULLUP);

}

void loop() {
  // put your main code here, to run repeatedly:

  // get the current time in milliseconds
  unsigned long currentMillis = millis();

  // tell the code when to change the LED state
  if (currentMillis - previousMillis >= interval) {
    previousMillis = currentMillis;

    // check the animation output selection
    // The first sequence runs through turning one letter off at a time.
    if (digitalRead(animation1) == HIGH && digitalRead(animation2) == LOW) {
      if (oState == LOW) {
        oState = HIGH;
        pState = LOW;
        eState = HIGH;
        nState = HIGH;
      } else if (pState == LOW) {
        oState = HIGH;
        pState = HIGH;
        eState = LOW;
        nState = HIGH;
      } else if (eState == LOW) {
        oState = HIGH;
        pState = HIGH;
        eState = HIGH;
        nState = LOW;
      } else if (nState == LOW) {
        oState = LOW;
        pState = HIGH;
        eState = HIGH;
        nState = HIGH;
      } //else {
      //oState = HIGH;
      //pState = HIGH;
      //eState = HIGH;
      //nState = HIGH;
    //}
    }

    // this just blinks the OPEN sign on and off
    else if (digitalRead(animation1) == LOW && digitalRead(animation2) == LOW) {
      
      
      if (oState == LOW && pState == LOW && eState == LOW && nState == LOW) {
        oState = HIGH;
        pState = HIGH;
        eState = HIGH;
        nState = HIGH;
      } else {
        oState = LOW;
        pState = LOW;
        eState = LOW;
        nState = LOW;
      }
    } else if (digitalRead(animation1) == LOW && digitalRead(animation2) == HIGH) {
      
      
      if (oState == LOW && pState == LOW && eState == HIGH && nState == HIGH) {
        oState = HIGH;
        pState = HIGH;
        eState = LOW;
        nState = LOW;
      } else {
        oState = LOW;
        pState = LOW;
        eState = HIGH;
        nState = HIGH;
      }
    } else if (digitalRead(animation1) == HIGH && digitalRead(animation2) == HIGH) {
      oState = HIGH;
        pState = HIGH;
        eState = HIGH;
        nState = HIGH;
    }

    

  }
  //digitalRead(animation1);
  //digitalRead(animation2);
  digitalWrite(oPin, oState);
  digitalWrite(pPin, pState);
  digitalWrite(ePin, eState);
  digitalWrite(nPin, nState);

}
