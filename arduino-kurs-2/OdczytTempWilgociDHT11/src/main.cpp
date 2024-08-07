#include <dht11.h>
#define DHT11PIN 2
dht11 DHT11;

void setup()
{
  Serial.begin(9600);
}

void loop()
{
  int chk = DHT11.read(DHT11PIN);
  Serial.print("Stan sensora: ");
  switch (chk)
  {
    case DHTLIB_OK: 
		Serial.println("OK"); 
		break;
    case DHTLIB_ERROR_CHECKSUM: 
		Serial.println("BLAD SUMY KONTROLNEJ"); 
		break;
    case DHTLIB_ERROR_TIMEOUT: 
		Serial.println("BRAK ODPOWIEDZI"); 
		break;
    default: 
		Serial.println("NIEZNANY BLAD"); 
		break;
  }
  Serial.print("STAN SENSORA: ");
  Serial.print("WILGOTNOSC (%RH): ");
  Serial.print((float)DHT11.humidity, 2);
  Serial.print(" | ");
  Serial.print("TEMPERATURA (C): ");
  Serial.println((float)DHT11.temperature, 2);
  delay(1000);
} 