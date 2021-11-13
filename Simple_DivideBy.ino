
//This is designed to run on the AtTINY85 to perform a simple customisable Divide by I/O
// This works up to about 5 KHz, but I/O Routines could be optimised to acheive much higher.

// Add These Boards to Arduino IDE for Direct ATTINY85 Compatibility
// https://raw.githubusercontent.com/damellis/attiny/ide-1.6.x-boards-manager/package_damellis_attiny_index.json.
// Select 'ATTiny Microcontrollers' from the Boards Menu

#define PIN_INPUT 0
#define PIN_OUTPUT 2

// Change this to suit your dividy by requirements
#define DIVIDEBY 100

unsigned int RxCount;
bool inputstatus;
bool outputstatus;

void setup() {
  // Setup Input Pin
  pinMode(PIN_INPUT, INPUT_PULLUP);
  digitalWrite(PIN_INPUT, HIGH);
  // Setup Output Pin
  pinMode(PIN_OUTPUT, OUTPUT);
  digitalWrite(PIN_OUTPUT, HIGH);
  // Initialise Counter
  RxCount = 0;
  outputstatus = HIGH;
}

void loop() {
  if ( inputstatus != digitalRead(PIN_INPUT) ) {
    inputstatus = digitalRead(PIN_INPUT);
    if ( inputstatus == HIGH ) {
      counting();   
    }
  }
}

void counting() {
  RxCount++;
  if ( RxCount >= ( DIVIDEBY / 2 ) ) {
    RxCount = 0;
    if ( outputstatus == HIGH ) {
      outputstatus = LOW;
    } else {
      outputstatus = HIGH;
    }
    digitalWrite(PIN_OUTPUT, outputstatus);  
  }  
}
