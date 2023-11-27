const int soundSensorPin = A0;   // Cổng analog mà cảm biến âm thanh được kết nối
const int ledPins[] = {2, 3, 4, 5, 6, 7, 8, 9, 10, 11};  // Các cổng digital cho 10 đèn LED
const int numLEDs = 10;
const int minIntensity = 0;
const int maxIntensity = 255;
const int animationSpeed = 500;  // Thời gian mỗi bước sóng (milliseconds)

void setup() {
  Serial.begin(9600);  // Khởi động cổng Serial để theo dõi dữ liệu

  // Khai báo đèn LED là OUTPUT
  for (int i = 0; i < numLEDs; i++) {
    pinMode(ledPins[i], OUTPUT);
  }
}

void loop() {
  // Đọc giá trị từ cảm biến âm thanh
  int soundValue = analogRead(soundSensorPin);

  // Hiển thị giá trị cường độ âm thanh lên Serial Monitor
  Serial.print("Sound Value: ");
  Serial.println(soundValue);

  // Hiển thị cường độ âm thanh lên các đèn LED
  displaySoundIntensity(soundValue);

  delay(100);  // Đợi một khoảng thời gian trước khi đọc giá trị tiếp theo
}

void displaySoundIntensity(int soundValue) {
  // Chia phạm vi giá trị âm thanh thành 10 mức độ
  int intensityLevel = map(soundValue, 0, 1023, minIntensity, maxIntensity);

  // Tính giá trị cường độ ánh sáng dựa trên hàm sine wave
  int brightness = calculateSineWave(intensityLevel);

  // Bật đèn LED tương ứng với mức độ cường độ âm thanh
  for (int i = 0; i < numLEDs; i++) {
    analogWrite(ledPins[i], brightness);
    delay(animationSpeed / numLEDs);  // Tốc độ sóng điều chỉnh được
  }

  // Tắt tất cả đèn LED
  for (int i = 0; i < numLEDs; i++) {
    analogWrite(ledPins[i], minIntensity);
  }
}

int calculateSineWave(int x) {
  // Hàm sine wave để tạo hiệu ứng sóng điều chỉnh được
  return (sin(2 * PI * x / maxIntensity) + 1) * maxIntensity / 2;
}
