// Define constants for LED pin and blink durations
const int builtInLedPin = LED_BUILTIN;
const int dotBlinkDuration = 200; // Duration for a dot blink
const int dashBlinkDuration = 3 * dotBlinkDuration; // Duration for a dash blink
const int letterDelay = 3 * dotBlinkDuration; // Delay between letters

void setup() {
  Serial.begin(9600); // Initialize serial communication
  pinMode(builtInLedPin, OUTPUT); // Set LED pin as output
  pinMode(2, INPUT); // Set pin 2 as input for button
}

void loop() {
  int buttonPin = digitalRead(2); // Read the state of the button
  if (buttonPin == 0) { // If button is pressed
    blinkMorse("AKALJOT"); // call function to blink morse code of any string 
  }
}

// Function to blink a dot
void blinkDot() {
  digitalWrite(builtInLedPin, HIGH); // Turn LED on
  delay(dotBlinkDuration); // Wait for dot duration
  digitalWrite(builtInLedPin, LOW); // Turn LED off
  delay(dotBlinkDuration); // Wait for dot duration
}

// Function to blink a dash
void blinkDash() {
  digitalWrite(builtInLedPin, HIGH); // Turn LED on
  delay(dashBlinkDuration); // Wait for dash duration
  digitalWrite(builtInLedPin, LOW); // Turn LED off
  delay(dotBlinkDuration); // Wait for dot duration
}

// Function to blink Morse code for a given text
void blinkMorse(String text) {
  for (int i = 0; i < text.length(); i++) { // Loop through each character in the text
    char c = text.charAt(i); // Get the current character
    blinkCharacter(c); // Blink the Morse code for the character
    delay(letterDelay); // Wait for letter delay
  }
}

// Function to blink Morse code for a given character
void blinkCharacter(char c) {
  switch (c) {
    case 'A': blinkDot(); blinkDash(); break;
    case 'B': blinkDash(); blinkDot(); blinkDot(); blinkDot(); break;
    case 'C': blinkDash(); blinkDot(); blinkDash(); blinkDot(); break;
    case 'D': blinkDash(); blinkDot(); blinkDot(); break;
    case 'E': blinkDot(); break;
    case 'F': blinkDot(); blinkDot(); blinkDash(); blinkDot(); break;
    case 'G': blinkDash(); blinkDash(); blinkDot(); break;
    case 'H': blinkDot(); blinkDot(); blinkDot(); blinkDot(); break;
    case 'I': blinkDot(); blinkDot(); break;
    case 'J': blinkDot(); blinkDash(); blinkDash(); blinkDash(); break;
    case 'K': blinkDash(); blinkDot(); blinkDash(); break;
    case 'L': blinkDot(); blinkDash(); blinkDot(); blinkDot(); break;
    case 'M': blinkDash(); blinkDash(); break;
    case 'N': blinkDash(); blinkDot(); break;
    case 'O': blinkDash(); blinkDash(); blinkDash(); break;
    case 'P': blinkDot(); blinkDash(); blinkDash(); blinkDot(); break;
    case 'Q': blinkDash(); blinkDash(); blinkDot(); blinkDash(); break;
    case 'R': blinkDot(); blinkDash(); blinkDot(); break;
    case 'S': blinkDot(); blinkDot(); blinkDot(); break;
    case 'T': blinkDash(); break;
    case 'U': blinkDot(); blinkDot(); blinkDash(); break;
    case 'V': blinkDot(); blinkDot(); blinkDot(); blinkDash(); break;
    case 'W': blinkDot(); blinkDash(); blinkDash(); break;
    case 'X': blinkDash(); blinkDot(); blinkDot(); blinkDash(); break;
    case 'Y': blinkDash(); blinkDot(); blinkDash(); blinkDash(); break;
    case 'Z': blinkDash(); blinkDash(); blinkDot(); blinkDot(); break;
  }
}
