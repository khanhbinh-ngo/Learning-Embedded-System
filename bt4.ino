
// Khai báo biến
int trigPin = 7; // chân trig của cảm biến siêu âm
int echoPin = 8; // chân echo của cảm biến siêu âm
int leds[] = {2, 3, 4, 5, 6, 9, 10, 11, 12, 13}; // chân các đèn LED

void setup() {
  // Khởi tạo chân các đèn LED
  for (int i = 0; i < 10; i++) {
    pinMode(leds[i], OUTPUT);
  }
  // Khởi tạo Serial Monitor
  Serial.begin(9600);
  // Khởi tạo chân trig và echo của cảm biến siêu âm
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
}

void loop() {
  // Đo khoảng cách bằng cảm biến siêu âm
  long duration, distance;
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);

  duration = pulseIn(echoPin, HIGH);
  distance = (duration / 2) * 0.0343;

  // Biểu thị khoảng cách bằng 10 đèn
  int ledsOn = 0;
  if (distance < 4) {
    ledsOn = 10;
  } else if (distance < 8) {
    ledsOn = 9;
  } else if (distance < 12) {
    ledsOn = 8;
  } else if (distance < 16) {
    ledsOn = 7;
  } else if (distance < 20) {
    ledsOn = 6;
  } else if (distance < 24) {
    ledsOn = 5;
  } else if (distance < 28) {
    ledsOn = 4;
  } else if (distance < 32) {
    ledsOn = 3;
  } else if (distance < 36) {
    ledsOn = 2;
  } else if (distance < 40ơ) {
    ledsOn = 1;
  } else {
    ledsOn = 0;
  }
  

  // Bật/tắt các đèn LED
  for (int i = 0; i < 10; i++) {
    if (i < ledsOn) {
      digitalWrite(leds[i], HIGH);
    } else {
      digitalWrite(leds[i], LOW);
    }
  }
  delay(500);
}
