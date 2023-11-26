const int soundSensorPin = A0; // analog for sound sensor

const int lightPin_1 = 9; // LED number 1

const int lightPin_2 = 11; // LED number 2

int clapCount = 0;

void setup() {

  Serial.begin(9600);

  pinMode(soundSensorPin, INPUT);

  pinMode(lightPin_1, OUTPUT);

  pinMode(lightPin_2, OUTPUT);
}

void loop() {
  int soundValue = analogRead(soundSensorPin);
  Serial.print("Sound value: \n");
  Serial.print(soundValue);

  // check if sound is big enough 
  if(soundValue >= 400){
    clapCount++;
    Serial.print("clap count = \n");
    Serial.print(clapCount);

    if(clapCount == 1){
      turnLightOn(1);
    }else if(clapCount == 2){
      turnLightOn(2);
    }else if(clapCount == 3){
      turnLightOff();
      clapCount = 0;
    }
    delay(1000); // delay 1s to avoid multiple clap sound in one section
  }
  delay(100); // delay 0.1s before receive next signals
}


void turnLightOn(int numLights){
  // if it doesn't work, I have to choose other options to fix this 
  digitalWrite(lightPin_1, numLights >= 1 ? HIGH : LOW);
  digitalWrite(lightPin_2, numLights >= 2 ? HIGH : LOW);

}
void turnLightOff() {
  digitalWrite(lightPin_1, LOW);
  digitalWrite(lightPin_2, LOW);
}