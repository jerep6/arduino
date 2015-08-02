//https://www.arduino.cc/en/Reference/Constants
//https://www.arduino.cc/en/Tutorial/InputPullupSerial

// constants used here to set pin numbers:
const int buttonPin = 7;     // the number of the pushbutton pin
const int ledPin =  13;      // the number of the LED pin

// variables will change:
int buttonState = 0;         // variable for reading the pushbutton status

void setup() {
  //initialize the serial port
  Serial.begin(9600);
  
  //configure pin as an input and enable the internal pull-up resistor
  pinMode(buttonPin, INPUT_PULLUP);
}

void loop(){
  // read the state of the pushbutton value:
  buttonState = digitalRead(buttonPin);

  // check if the pushbutton is pressed.
  // if it is, the buttonState is HIGH:
  if (buttonState == HIGH) {     
    // The pullup means the pushbutton's logic is inverted. 
    // It goes HIGH when it's open, and LOW when it's pressed.
    digitalWrite(ledPin, LOW);  
  } 
  else {
    // turn LED on
    digitalWrite(ledPin, HIGH); 
    Serial.println("Button pressed");
  }
}
