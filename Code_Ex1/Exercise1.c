// Khai báo số lượng đèn LED và chân kết nối
const int numLEDs = 12;     // Số lượng đèn LED
const int analogPin = A0;   // Chân kết nối biến trở

// Mảng lưu trữ các chân kết nối đèn LED
int ledPins[numLEDs] = {2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13};

void setup() {
  // Khởi tạo chân kết nối đèn LED
  for (int i = 0; i < numLEDs; i++) {
    pinMode(ledPins[i], OUTPUT);
  }
}

void loop() {
  // Đọc giá trị từ biến trở
  int sensorValue = analogRead(analogPin);

  // Chuyển đổi giá trị từ biến trở thành số lượng đèn LED sáng
  int numLEDsOn = map(sensorValue, 0, 1023, 0, numLEDs);

  // Bật các đèn LED tương ứng với số lượng cần sáng
  for (int i = 0; i < numLEDsOn; i++) {  // Thay đổi điều kiện kiểm tra ở đây
    digitalWrite(ledPins[i], HIGH);     // Bật đèn LED
  }

  // Tắt các đèn LED còn lại
  for (int i = numLEDsOn; i < numLEDs; i++) {
    digitalWrite(ledPins[i], LOW);      // Tắt đèn LED
  }
}
