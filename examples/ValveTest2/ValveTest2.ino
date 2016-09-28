// Example testing sketch for various DHT humidity/temperature sensors
// Written by ladyada, public domain

#include "DHT.h"

#define DHTPIN0 2     // what digital pin we're connected to
#define DHTPIN1 4     // what digital pin we're connected to
#define DHTPIN2 5     // what digital pin we're connected to
#define DHTPIN3 6     // what digital pin we're connected to
#define ValvePin 4
#define ledPin 13

// Uncomment whatever type you're using!
//#define DHTTYPE DHT11   // DHT 11
#define DHTTYPE DHT22   // DHT 22  (AM2302), AM2321
//#define DHTTYPE DHT21   // DHT 21 (AM2301)

// Connect pin 1 (on the left) of the sensor to +5V
// NOTE: If using a board with 3.3V logic like an Arduino Due connect pin 1
// to 3.3V instead of 5V!
// Connect pin 2 of the sensor to whatever your DHTPIN is
// Connect pin 4 (on the right) of the sensor to GROUND
// Connect a 10K resistor from pin 2 (data) to pin 1 (power) of the sensor

// Initialize DHT sensor.
// Note that older versions of this library took an optional third parameter to
// tweak the timings for faster processors.  This parameter is no longer needed
// as the current DHT reading algorithm adjusts itself to work on faster procs.
DHT dht0(DHTPIN0, DHTTYPE);
DHT dht1(DHTPIN1, DHTTYPE);
DHT dht2(DHTPIN2, DHTTYPE);
DHT dht3(DHTPIN3, DHTTYPE);
int ValvePinState = LOW;
int ledPinState = LOW;

void setup() {
  Serial.begin(9600);
  Serial.println("DHTxx test!");
//  pinMode(ValvePin,OUTPUT); 
//  pinMode(ledPin,OUTPUT); 

  dht0.begin();
  dht1.begin();
  dht2.begin();
  dht3.begin();
}

void loop() {
  // Wait a few seconds between measurements.
  delay(300);

  // Reading temperature or humidity takes about 250 milliseconds!
  // Sensor readings may also be up to 2 seconds 'old' (its a very slow sensor)
  float h0 = dht0.readHumidity();
  // Read temperature as Celsius (the default)
  float t0 = dht0.readTemperature();
  // Read temperature as Fahrenheit (isFahrenheit = true)
  float f0 = dht0.readTemperature(true);

  float h1 = dht1.readHumidity();
  float t1 = dht1.readTemperature();
  float f1 = dht1.readTemperature(true);
  float h2 = dht2.readHumidity();
  float t2 = dht2.readTemperature();
  float f2 = dht2.readTemperature(true);
  float h3 = dht3.readHumidity();
  float t3 = dht3.readTemperature();
  float f3 = dht3.readTemperature(true);

  // Check if any reads failed and exit early (to try again).
  if (isnan(h0) || isnan(t0) || isnan(f0)) {
    Serial.println("Failed to read from DHT0 sensor!");
    return;
  }
  if (isnan(h1) || isnan(t1) || isnan(f1)) {
    Serial.println("Failed to read from DHT1 sensor!");
    return;
  }
  if (isnan(h2) || isnan(t2) || isnan(f2)) {
    Serial.println("Failed to read from DHT2 sensor!");
    return;
  }
  if (isnan(h3) || isnan(t3) || isnan(f3)) {
    Serial.println("Failed to read from DHT3 sensor!");
    return;
  }

  // Compute heat index in Fahrenheit (the default)
  float hif0 = dht0.computeHeatIndex(f0, h0);
  // Compute heat index in Celsius (isFahreheit = false)
  float hic0 = dht0.computeHeatIndex(t0, h0, false);
  float hif1 = dht1.computeHeatIndex(f1, h1);
  float hic1 = dht1.computeHeatIndex(t1, h1, false);
  float hif2 = dht2.computeHeatIndex(f2, h2);
  float hic2 = dht2.computeHeatIndex(t2, h2, false);
  float hif3 = dht3.computeHeatIndex(f3, h3);
  float hic3 = dht3.computeHeatIndex(t3, h3, false);

  Serial.print("S0 Humidity: ");
  Serial.print(h0);
  Serial.print(" %\t");
  Serial.print("Temperature: ");
  Serial.print(t0);
  Serial.print(" *C ");
  Serial.print(f0);
  Serial.print(" *F\t");
  Serial.print("Heat index: ");
  Serial.print(hic0);
  Serial.print(" *C ");
  Serial.print(hif0);
  Serial.println(" *F");

  Serial.print("S1 Humidity: ");
  Serial.print(h1);
  Serial.print(" %\t");
  Serial.print("Temperature: ");
  Serial.print(t1);
  Serial.print(" *C ");
  Serial.print(f1);
  Serial.print(" *F\t");
  Serial.print("Heat index: ");
  Serial.print(hic1);
  Serial.print(" *C ");
  Serial.print(hif1);
  Serial.println(" *F");
  
  Serial.print("S2 Humidity: ");
  Serial.print(h2);
  Serial.print(" %\t");
  Serial.print("Temperature: ");
  Serial.print(t2);
  Serial.print(" *C ");
  Serial.print(f2);
  Serial.print(" *F\t");
  Serial.print("Heat index: ");
  Serial.print(hic2);
  Serial.print(" *C ");
  Serial.print(hif2);
  Serial.println(" *F");
  
  Serial.print("S3 Humidity: ");
  Serial.print(h3);
  Serial.print(" %\t");
  Serial.print("Temperature: ");
  Serial.print(t3);
  Serial.print(" *C ");
  Serial.print(f3);
  Serial.print(" *F\t");
  Serial.print("Heat index: ");
  Serial.print(hic3);
  Serial.print(" *C ");
  Serial.print(hif3);
  Serial.println(" *F");
}
