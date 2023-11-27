#include <DHT.h>
#define DHTPIN 2    // Data pin of DHT is set to sock 2 digital signal
#define DHTTYPE DHT11   // suppose for DHT11 or DHT22 is okey

DHT dht(DHTPIN, DHTTYPE);

void setup() {
  Serial.begin(9600);
  dht.begin();
}

void loop() {
  delay(2000);  // Interval 2 sec

  float humidity = dht.readHumidity();
  float temperature = dht.readTemperature();

  // If cannot connect or read sensor data then print error to serial
  if (isnan(humidity) || isnan(temperature)) {
    Serial.println("Không đọc được cảm biến bây ơi ");
    return;
  }

  // print data to Serial Monitor
  Serial.print("Độ ẩm =  ");
  Serial.print(humidity);
  Serial.println(" phần trăm");

  Serial.print("Nhiệt độ =  ");
  Serial.print(temperature);
  Serial.println(" độ C");
}
