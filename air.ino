#include <DHT.h> // Include the DHT library


// Constants
#include <Adafruit_Sensor.h>

#define DHTPIN 2       // Pin where the DHT11 sensor is connected
#define DHTTYPE DHT11  // Type of DHT sensor
#define MQ135PIN A0    // Pin where the MQ135 is connected
#define BUZZERPIN 8    // Pin for the buzzer
#define AIR_QUALITY_THRESHOLD 200  // Threshold for air quality to trigger buzzer
String quality="";
// Variables
DHT dht(DHTPIN, DHTTYPE); // Initialize DHT sensor
int airQuality; // Variable to store air quality reading
float temperature, humidity; // Variables to store temperature and humidity readings

void setup() {
  Serial.begin(9600); // Start serial communication
  dht.begin(); // Initialize DHT sensor
  pinMode(BUZZERPIN, OUTPUT); // Set buzzer pin as output
}

void loop() {
  // Read temperature and humidity from DHT11
  temperature = dht.readTemperature(); // Get temperature in Celsius
  humidity = dht.readHumidity(); // Get humidity
  
  // Check for failed reading
  if (isnan(temperature) || isnan(humidity)) {
    Serial.println("Failed to read from DHT sensor!");
    return;
  }

  // Read air quality from MQ-135
  airQuality = analogRead(MQ135PIN); // Get air quality reading

  

  if (airQuality < 151) {
    quality = "GOOD!";
  } else if (airQuality > 150 && airQuality < 200) {
    quality = "Poor!";
  } else if (airQuality > 200 && airQuality < 300) {
    quality = "Very bad!";
  } else if (airQuality > 300 && airQuality < 500) {
    quality = "Toxic!";
  } else {
    quality = "Extremely Toxic!";
  }
  
  // Print temperature, humidity, and air quality to serial monitor
  
  Serial.print("Temperature: ");
  Serial.print(temperature);
  Serial.println(" °C");
  Serial.print("Humidity: ");
  Serial.println(humidity);
  Serial.print("Air Quality: ");
  Serial.print(airQuality);
  Serial.print(" - ");
  Serial.println(quality);
  

  // If air quality exceeds the threshold, sound the buzzer
  if (airQuality > AIR_QUALITY_THRESHOLD) {
    digitalWrite(BUZZERPIN, HIGH); // Activate buzzer
  } else {
    digitalWrite(BUZZERPIN, LOW); // Deactivate buzzer
  }

  delay(5000); // Delay between readings (2 seconds)
}