// For LCD
#include <LiquidCrystal.h>
#define LCD_RS_PIN A4
// RW to Ground
#define LCD_E_PIN A5
#define LCD_D4_PIN 2
#define LCD_D5_PIN 3
#define LCD_D6_PIN 4
#define LCD_D7_PIN 5

LiquidCrystal lcd(LCD_RS_PIN, LCD_E_PIN, LCD_D4_PIN, LCD_D5_PIN, LCD_D6_PIN, LCD_D7_PIN);


// For DHT11
#include <DHT.h>
#define DHTPIN A0
#define DHTTYPE DHT11
// Initialize DHT sensor
DHT dht(DHTPIN, DHTTYPE);


void setup() {
  lcd.begin(20,4);
  lcd.setCursor(0, 1);
  lcd.print("Starting...");

  dht.begin();

  delay(2000);
  lcd.clear();
}

void loop() {
  // Fetch data from the sensor
  float h = dht.readHumidity();                 // Humidity (%)
  float t = dht.readTemperature();              // Temperature (Celcius) (for farenheit add attribute - false)
  float hix = dht.computeHeatIndex(t, h, false); // Heat Index (Celcius)(false, because default is farenheit)

  // Display data to LCD
  lcd.setCursor(0, 0);
  lcd.print("Temperature: " + String(t) + "\xDF" "C");
  lcd.setCursor(0, 1);
  lcd.print("Humidity: " + String(h) + "%");
  lcd.setCursor(0, 2);
  lcd.print("Heat Index: " + String(hix) + "\xDF" "C");
}
