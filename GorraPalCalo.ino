//librerias del Sensor de Temperatura/Humedad
#include "DHT.h"
#include "marchaImperial.h"

#define DHTPIN 7 
#define DHTTYPE DHT11
#define TEMP_ALERTA 29
DHT dht(DHTPIN, DHTTYPE); 


void setup() {
Serial.begin(9600); //Se inicia la comunicación serial 
dht.begin(); //Se inicia el sensor
}

void loop(){
  float h = dht.readHumidity(); //se lee la humedad
  float t= dht.readTemperature(); // se lee la temperatura
  Serial.println("Humedad: "); 
  Serial.println(h); 
  Serial.println("Temperatura :"); 
  Serial.println(t); 
  // se imprime las variables de temperatura y humedad
  delay(500); 
  //con un retraso de 500 milisegundos
  
  if (t>=TEMP_ALERTA)
    marchaImperial();
}
