/*
 Name:		Mood_Detector.ino
 Created:	9/6/2019 5:20:40 PM
 Author:	Fernando
*/



#define USE_ARDUINO_INTERRUPTS true
#define BUFFERSIZE 512

//Libraries
#include <Wire.h>
#include <PulseSensorPlayground.h>
#include <SPI.h>
#include <SD.h>
#include <SimpleTimer.h>

//Memory Data
const int chipSelect = 4;

//Objects
SimpleTimer timer;

//Instances
PulseSensorPlayground pulseSensor;

//Variables       
int Threshold = 550;
int threshold = 0;
int GSRsensorValue;
int Red_ButtonState = 0;
int Blue_ButtonState = 0;
int myBPM = pulseSensor.getBeatsPerMinute();

//Analog Pins
const int PulseWire = A1;
const int GSR = A0;

//Digital Pins (Output)
int Buzzer = 9;      // Buzzer 
int Red_LED = 10;    // LED (Red)
int Yellow_LED = 8; // LED (Yellow)
int Green_LED = 9;   // LED (Green)

//Digital Pins (Input)
const int Red_Button = 2; // Button (Red)
const int Blue_Button = 3; // Button (Blue)

void setup()
{

	// Initialize Serial Ports
	Serial.begin(9600); // Debugging & Development

	//SD Card
	while (!Serial) 
	{
		; 
	}

	Serial.print("Initializing SD card");
	if (!SD.begin(chipSelect)) 
	{
		Serial.println("Card failed, or not present");
		// don't do anything more:
		while (1);
	}
	Serial.println("Card initialized");

	//=====================================================================================================
	delay(2000);
	//=====================================================================================================

	// Initialize HB sensor
	pulseSensor.analogInput(PulseWire);
	pulseSensor.setThreshold(Threshold);

	// Initialize GSR Sensor
	long sum = 0;

	for (int i = 0; i < 500; i++)
	{
		GSRsensorValue = analogRead(GSR);
		sum += GSRsensorValue;
		delay(5);
	}
	threshold = sum / 500;

	// Initialize Buttons
	pinMode(Red_Button, INPUT);
	pinMode(Blue_Button, INPUT);

	// Initialize Indicators (Led's,BBuzzers,etc.)
	pinMode(Yellow_LED, OUTPUT);
	digitalWrite(Yellow_LED, HIGH);
	digitalWrite(Yellow_LED, LOW);

	pinMode(Red_LED, OUTPUT);
	digitalWrite(Red_LED, HIGH);
	digitalWrite(Red_LED, LOW);

	pinMode(Green_LED, OUTPUT);
	digitalWrite(Green_LED, HIGH);
	digitalWrite(Green_LED, LOW);

	/*pinMode(Buzzer, OUTPUT); // Not used ATM
	digitalWrite(Buzzer, HIGH);
	digitalWrite(Buzzer, LOW);*/

	

	if (pulseSensor.begin())
	{
		delay(1000);
		Serial.print("Initializing Sensors");

		// LED Pattern to show initilization
		digitalWrite(Green_LED, HIGH);
		delay(100);
		digitalWrite(Green_LED, LOW);
		delay(100);

		digitalWrite(Yellow_LED, HIGH);
		delay(100);
		digitalWrite(Yellow_LED, LOW);
		delay(100);

		digitalWrite(Red_LED, HIGH);
		delay(100);
		digitalWrite(Red_LED, LOW);
		delay(100);

		digitalWrite(Yellow_LED, HIGH);
		delay(100);
		digitalWrite(Yellow_LED, LOW);
		delay(100);

		digitalWrite(Green_LED, HIGH);
		delay(100);
		digitalWrite(Green_LED, LOW);
		delay(100);

		digitalWrite(Yellow_LED, HIGH);
		delay(100);
		digitalWrite(Yellow_LED, LOW);
		delay(100);

		digitalWrite(Red_LED, HIGH);
		delay(100);
		digitalWrite(Red_LED, LOW);
		delay(100);

		digitalWrite(Yellow_LED, HIGH);
		delay(100);
		digitalWrite(Yellow_LED, LOW);
		delay(100);

		digitalWrite(Green_LED, HIGH);
		delay(100);
		digitalWrite(Green_LED, LOW);

	}
	

	//=====================================================================================================

}


void loop()
{

	while (pulseSensor.sawStartOfBeat())
	{
		delay(200);



		//Initialize Timer
		Serial.print("Timer (s): ");
		Serial.println(millis() / 1000);

		// Sensors

		// HeartBeat Sensor (Start)

		int Calibrate = 15;
		int BPM;

		BPM = pulseSensor.getBeatsPerMinute() - Calibrate; // BPM

		// Galvanic Skin Response Sensor (Start)

		GSRsensorValue = analogRead(GSR);

		//====================================================================================================

		// SD Card Recording


		File dataFile = SD.open("datalog.txt", FILE_WRITE);


		if (dataFile)
		{
			//Data ID
			dataFile.println("Test Subject: ");
			Serial.println("Test Subject: ");

			//Timer
			dataFile.print("Timer: ");
			dataFile.println(millis() / 1000);

			// BEATS PER MINUTE
			dataFile.print("BPM: ");
			dataFile.println(BPM);
			Serial.print("BPM: ");
			Serial.println(BPM);


			// GALVANIC SKIN RESPONSE
			dataFile.print("GSR:");
			dataFile.println(GSRsensorValue);
			Serial.print("GSR:");
			Serial.println(GSRsensorValue);


			// Initialize Button 

			Red_ButtonState = digitalRead(Red_Button);
			Blue_ButtonState = digitalRead(Blue_Button);

			// Red Button	// (Passed)
			if (Red_ButtonState == HIGH)
			{
				// Indicate the red button was pressed
				Serial.println("Angry (Manual Input)");
				dataFile.println("Angry (Manual Input)");
				delay(100);
			}
			else
			{

			}

			// Blue Button	// (Passed)
			if (Blue_ButtonState == HIGH)
			{
				// Indicate the blue button was pressed
				Serial.println("Anxious (Manual Input)");
				dataFile.println("Anxious (Manual Input)");
				delay(100);
			}
			else
			{

			}

			if (GSRsensorValue > 500)
			{
				// No Human Detected Using GSR Reading
				delay(500);
				Serial.println("No Human Detected");
				dataFile.println("No Human Detected");
				digitalWrite(Green_LED, LOW);
				digitalWrite(Yellow_LED, LOW);
				digitalWrite(Red_LED, HIGH);
			}

			dataFile.close();
		}


		else
		{
			// if the file isn't open, pop up an error:
			Serial.println("error opening datalog.txt");
		}

		//======================================================================================================================

		if (BPM < 60) // Low Heart Rate (Green Led)
		{
			digitalWrite(Green_LED, LOW);
			digitalWrite(Yellow_LED, HIGH);
			digitalWrite(Red_LED, LOW);
		}

		if (BPM > 67 && BPM < 120) // Normal Heart Rate (Green Led)
		{
			digitalWrite(Green_LED, HIGH);
			digitalWrite(Yellow_LED, LOW);
			digitalWrite(Red_LED, LOW);
		}

		if (BPM > 180) // Stressed Heart Rate (Yellow Led)
		{
			digitalWrite(Green_LED, LOW);
			delay(100);
			digitalWrite(Red_LED, LOW);
			delay(100);
			digitalWrite(Yellow_LED, HIGH);
			delay(100);
			digitalWrite(Yellow_LED, LOW);
			delay(100);

			if (GSRsensorValue < 20)
			{
				delay(100);
				digitalWrite(Green_LED, LOW);
				digitalWrite(Yellow_LED, LOW);
				digitalWrite(Red_LED, HIGH);
			}
		}

		//======================================================================================================================
		delay(200);

	}

}