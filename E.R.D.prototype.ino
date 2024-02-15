const int rainPin = A0; // Yağmur sensörünün bağlı olduğu pin
int threshold = 500; // Yağmur algılama eşiği
int sensorPin = A0; // Toprak nem sensörünün analog pin bağlantısı
int humidity = 0; // Nem değerini saklayacak değişken
  #include <Adafruit_Sensor.h>
 #include "deneyap.h"
 #include "DHT.h"
 #define DHTPIN D0
 #define DHTTYPE DHT11 

DHT dht(DHTPIN, DHTTYPE);


int nemdegeri;


void setup() {
  Serial.begin(9600);
  pinMode(rainPin, INPUT);
  Serial.begin(9600);
   Serial.begin(115200);
  pinMode(A0, INPUT);
  dht.begin();
}

void loop() {
  int sensorValue = analogRead(rainPin);
  Serial.print("Yağmur Sensörü Değeri: ");
  Serial.println(sensorValue);
  
  if(sensorValue > threshold) {
    Serial.println("Yağmur algılandı!");
    // Yağmur algılandığında yapılacak işlemleri buraya ekleyin
  }
  
  delay(1000); // Sensör değerini her saniye bir oku
  humidity = analogRead(sensorPin); // Nem değerini oku
  Serial.print("Toprak Nem Değeri: ");
  Serial.println(humidity);

  // Nem değerini yorumlamak için aşağıdaki kodu kullanabilirsiniz:
  if (humidity < 300) {
    Serial.println("Toprak çok kuru!");
  } else if (humidity < 700) {
    Serial.println("Toprak ılıman nemde.");
  } else {
    Serial.println("Toprak çok nemli.");
  }

  delay(1000); // 1 saniyede bir okuma yap
  nemdegeri = analogRead(A0);
  Serial.print("nem degeri");
  Serial.println(nemdegeri);
  delay(2000);
  float nem = dht.readHumidity();
  float sicaklik = dht.readTemperature();
  float f = dht.readTemperature(true);
  float hissicaklik = dht.computeHeatIndex(sicaklik, nem, false);
  float hisf = dht.computeHeatIndex(f, nem);
  Serial.print("Nem: ");
  Serial.print("sicaklik: ");
  Serial.print(sicaklik);
  Serial.print(" C ");
  Serial.print(f);
  Serial.print(" F hissedilen sicaklik:  ");
  Serial.print(hissicaklik);
  Serial.print("C");
  Serial.print(hisf);
  Serial.println("F");
  delay(2000);
  int sensorPin = A0; // Toprak nem sensörünün analog pin bağlantısı
int humidity = 0; // Nem değerini saklayacak değişken

  humidity = analogRead(sensorPin); // Nem değerini oku
  Serial.print("Toprak Nem Değeri: ");
  Serial.println(humidity);

  // Nem değerini yorumlamak için aşağıdaki kodu kullanabilirsiniz:
  if (humidity < 300) {
    Serial.println("Toprak çok kuru!");
  } else if (humidity < 700) {
    Serial.println("Toprak ılıman nemde.");
  } else {
    Serial.println("Toprak  nemli.");
  }

  delay(1000); // 1 saniyede bir okuma yap
}