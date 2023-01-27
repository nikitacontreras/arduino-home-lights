#define PORT 9
#define DELAY 500
#define REPEAT 5

void setup() {
  pinMode(PORT, OUTPUT);
  Serial.begin(9600);
}

void loop() {
  int i = 2;
  while (1)
  {
    switch (i){
      case 0:
        fifth_blink();
        Serial.println();
        i++;
      break;
      case 1:
        smooth_slide();
        i++;
      case 2:
        solid_to_dark();
        i=0;
      break;
    }
  }

}

void fifth_blink(){
  for (int i = 0; i < REPEAT; i++){
    digitalWrite(PORT, HIGH);
    delay(DELAY);
    digitalWrite(PORT, LOW);
    delay(DELAY);
  }
}
void smooth_slide(){
  for (int i = 0; i < REPEAT; i++){
    for (int fadeValue = 0 ; fadeValue <= 255; fadeValue = fadeValue+5) {
			// sets the value (range from 0 to 255):
			analogWrite(PORT, fadeValue);
			// wait for 30 milliseconds to see the dimming effect
			delay(30);
		}

		// fade out from max to min in increments of 5 points:
		for (int fadeValue = 255 ; fadeValue >= 0; fadeValue = fadeValue-5) {
			// sets the value (range from 0 to 255):
			analogWrite(PORT, fadeValue);
			// wait for 30 milliseconds to see the dimming effect
			delay(30);
		}    
  }
}

void solid_to_dark(){
  for (int i = 0; i < REPEAT; i++){
    for (int fadeValue = 255 ; fadeValue >= 0; fadeValue = fadeValue-5) {
			// sets the value (range from 0 to 255):
			analogWrite(PORT, fadeValue);
			// wait for 60 milliseconds to see the dimming effect
			delay(60);
		}
    for (int fadeValue = 0 ; fadeValue <= 255; fadeValue = fadeValue+5) {
			// sets the value (range from 0 to 255):
			analogWrite(PORT, fadeValue);
			// wait for 30 milliseconds to see the dimming effect
			delay(3);
		}
  }
}