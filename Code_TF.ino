#include <SPI.h>
#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>
#define WIRE Wire
/*
  Analog Input

  Demonstrates analog input by reading an analog sensor on analog pin 0 and
  turning on and off a light emitting diode(LED) connected to digital pin 13.
  The amount of time the LED will be on and off depends on the value obtained
  by analogRead().

  The circuit:
  - potentiometer
    center pin of the potentiometer to the analog input 0
    one side pin (either one) to ground
    the other side pin to +5V
  - LED
    anode (long leg) attached to digital output 13 through 220 ohm resistor
    cathode (short leg) attached to ground

  - Note: because most Arduinos have a built-in LED attached to pin 13 on the
    board, the LED is optional.

  created by David Cuartielles
  modified 30 Aug 2011
  By Tom Igoe

  This example code is in the public domain.

  https://www.arduino.cc/en/Tutorial/BuiltInExamples/AnalogInput
*/

int sensorPin = A0;   // select the input pin for the potentiometer
int ledPin = 13;      // select the pin for the LED
float sensorValue = 0;  // variable to store the value coming from the sensor
float sensorValue1 = 0; 
int cont = 0;
//Instância objeto
Adafruit_SSD1306 display = Adafruit_SSD1306(128, 32, &WIRE);

void setup() {
  // initialize serial communication at 9600 bits per second:
  Serial.begin(9600);
  // declare the ledPin as an OUTPUT:
  pinMode(ledPin, OUTPUT);
   //Inicializando o display
  
}

void loop() {
  // read the value from the sensor:
  sensorValue = analogRead(sensorPin);
  sensorValue1 = (sensorValue-10)/5;
  Serial.println(sensorValue1);
  if(sensorValue1 > 0){
    // turn the ledPin on
    digitalWrite(ledPin, HIGH);
    // stop the program for <sensorValue> milliseconds:
    //delay(1000);
  }else{
    // turn the ledPin off:
    digitalWrite(ledPin, LOW);
    // stop the program for for <sensorValue> milliseconds:
    //delay(sensorValue);
  }
  mostrarDisplay(sensorValue1);
}

void mostrarDisplay(float temp){
  if(cont==0){
  display.begin(SSD1306_SWITCHCAPVCC, 0x3C); // Address 0x3C for 128x32
  // Show image buffer on the display hardware.
  // Since the buffer is intialized with an Adafruit splashscreen
  // internally, this will display the splashscreen.
  display.display();
  delay(1000);
  cont=cont+1;
  }

  if(temp > 0){
    // Clear the buffer.
  display.clearDisplay();
  display.display();
    // text display tests
  display.setTextSize(1);
  display.setTextColor(SSD1306_WHITE);
  display.setCursor(0,0);
  display.println("Emergencia");
  display.println("Temperatura acima 0");
  display.print("Temperatura: ");
  display.print(temp);
  //delay(1000);
  //display.print("Connecting to SSID\n'adafruit':");
  //display.print("connected!");
  //display.println("IP: 10.0.1.23");
  //display.println("Sending val #0");
  display.setCursor(0,0);
  display.display(); // actually display all of the above
  }else{
     // Clear the buffer.
  display.clearDisplay();
  display.display();
    // text display tests
  display.setTextSize(1);
  display.setTextColor(SSD1306_WHITE);
  display.setCursor(0,0);
  display.println("Temperatura abaixo 0");
  display.print("Temperatura:");
  display.print(temp);
  //delay(1000);
  //display.print("Connecting to SSID\n'adafruit':");
  //display.print("connected!");
  //display.println("IP: 10.0.1.23");
  //display.println("Sending val #0");
  display.setCursor(0,0);
  display.display(); // actually display all of the above
  }
}









