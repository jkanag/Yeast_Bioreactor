  //Include libraries
#include <OneWire.h>
#include <DallasTemperature.h>  //data librairy that we are going to use

// Data wire is plugged into pin 31 on the Arduino
#define ONE_WIRE_BUS 31
// Setup a oneWire instance to communicate with any OneWire devices (not just Maxim/Dallas temperature ICs)
OneWire oneWire(ONE_WIRE_BUS);
// Pass our oneWire reference to Dallas Temperature. 
DallasTemperature sensors(&oneWire);
float temp;   //use float because temp isn't a integrer 
float x=27.7;

void setup(void)
{
 pinMode(31, OUTPUT); //input for
 Serial.begin(9600); //Begin serial communication
 Serial.println("Arduino Digital Temperature // Serial Monitor Version"); //Print a message
 sensors.begin();
 pinMode(8, OUTPUT); //input of the heater 
 pinMode(33, OUTPUT); //input of the LED
 pinMode(35, OUTPUT); //input of the pump 
 pinMode(37, OUTPUT); //input of the motor 
}

void loop(void)
{
// Send the command to get temperatures, switch on the motor and the pump
 digitalWrite(35, LOW );
 digitalWrite(37, HIGH);
 sensors.requestTemperatures(); 
 temp = sensors.getTempCByIndex(0);
 Serial.println(temp);// Why "byIndex"? You can have more than one IC on the same bus. 0 refers to the first IC on the wire
 //Update value every 1 sec.
 //delay(1000);
 if (temp <= x) {  //
  digitalWrite(33,HIGH); //switch on the LED
  digitalWrite(8, HIGH); //switch on the heater
  //delay(100);
     } 
 else {
   digitalWrite(33,LOW); //switch off the LED 
   digitalWrite(8,LOW); //switch off the heater 
   // delay(1000);
  } 
}
