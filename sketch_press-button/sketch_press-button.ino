//https://www.arduino.cc/en/Reference/Constants
//https://www.arduino.cc/en/Tutorial/InputPullupSerial

// constants used here to set pin numbers:
//const int buttonPin = 7;     // the number of the pushbutton pin
const int ledPin =  13;      // the number of the LED pin
const int buttonsPins[] = {7, 9};
const int numberOfPins = 2;
unsigned long timeBetweenTwoPressSignal = 1000;

// variables will change:
boolean buttonsRelease[numberOfPins];
unsigned long buttonsPressedTime[numberOfPins];

void setup() {
  //initialize the serial port
  Serial.begin(9600);
  
  //configure pin as an input and enable the internal pull-up resistor
  for (int i = 0; i < numberOfPins; i++) {
    pinMode(buttonsPins[i], INPUT_PULLUP);
    // Initial state => consider that all buttons are release
    buttonsRelease[i] = true;
  }
  
}

void loop() {
  // For each pin
  for (int i = 0; i < numberOfPins; i++) {
    // read the state of the pushbutton value:
    int buttonState = digitalRead(buttonsPins[i]);
    
    // check if the pushbutton is pressed. The pullup means the pushbutton's logic is inverted. 
    // It goes HIGH when it's open, and LOW when it's pressed. Use this mode because no resistance:
    if (buttonState == LOW && buttonsRelease[i] == true) {
      // Detect pressed button
      // Get Time
      unsigned long time = millis();
      
      if(time - buttonsPressedTime[i] >= timeBetweenTwoPressSignal) {
        Serial.println("Button pressed");

        // Forbidden to execute again this action until button will be released
        buttonsRelease[i] = false;

        buttonsPressedTime[i] = time;
        
        // turn LED on
        digitalWrite(ledPin, HIGH);
      }
      else {
        //Serial.println("Button pressed too early");
      }
      
    } 
    else if (buttonState == HIGH && buttonsRelease[i] == false) {
      //Serial.println("Button released");
      digitalWrite(ledPin, LOW);
      buttonsRelease[i] = true;
    }
  }
}
