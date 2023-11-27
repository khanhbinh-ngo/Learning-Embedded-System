const int soundSensorPin = A0; // analog for sound sensor

const int thresh_hole = 800; // setup for clapping.

unsigned long lastClapTime;
const int clapInterval = 500;
const int lightPin_1 = 9; // LED number 1

const int lightPin_2 = 11; // LED number 2

int clapCount = 0;

void setup() {

  Serial.begin(9600);
  pinMode(soundSensorPin, INPUT);
  pinMode(lightPin_1, OUTPUT);
  digitalWrite(lightPin_1, HIGH);
  digitalWrite(lightPin_2, HIGH);
  pinMode(lightPin_2, OUTPUT);
}

void loop() {
  int soundValue = analogRead(soundSensorPin);
  Serial.print("Sound value: ");
  Serial.println(soundValue);

  if(soundValue >= thresh_hole){
    if(millis() - lastClapTime >= clapInterval){
      clapCount++;
    }
    delay(1000); // delay 1s to avoid multiple clap sound in one section
  }
  delay(500); // delay 0.5s before receive next signals
  Serial.print("Clap time: ");
  Serial.println(clapCount);
    if(clapCount == 1){
      digitalWrite(lightPin_1, LOW); 
      digitalWrite(lightPin_2, HIGH);
    }else if(clapCount == 2){
      digitalWrite(lightPin_1, LOW);
      digitalWrite(lightPin_2, LOW);
    }else if(clapCount == 3){
      digitalWrite(lightPin_1, HIGH);
      digitalWrite(lightPin_2, HIGH);
      clapCount = 0;
    }
}