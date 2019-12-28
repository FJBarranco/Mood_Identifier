///*
// Name:		Mood_Detector.ino
// Created:	9/6/2019 5:20:40 PM
// Author:	Fernando
//*/
//
//
//
//#define USE_ARDUINO_INTERRUPTS true
//#define BUFFERSIZE 512
//
////Libraries
//#include <Wire.h>
//#include <PulseSensorPlayground.h>
//#include <SPI.h>
//#include <SD.h>
////#include <SimpleTimer.h>
//
////Memory Data
//const int chipSelect = 4;
//
////Objects
////SimpleTimer timer;
//
////Instances
//PulseSensorPlayground pulseSensor;
//
////Variables       
//int Threshold = 550;
//int threshold = 0;
//int GSRsensorValue;
//int Red_ButtonState = 0;
//int Blue_ButtonState = 0;
//
////Analog Pins
//const int PulseWire = 1;
//const int GSR = 0;
//
////Digital Pins (Output)
//int Buzzer = 9;      // Buzzer 
//int Red_LED = 10;    // LED (Red)
//int Yellow_LED = 8; // LED (Yellow)
//int Green_LED = 9;   // LED (Green)
//
////Digital Pins (Input)
//const int Red_Button = 2; // Button (Red)
//const int Blue_Button = 3; // Button (Blue)
//
//void setup()
//{
//	// Initialize Serial Ports
//	Serial.begin(9600); // Debugging & Development
//
//	////SD Card
//	//while (!Serial) 
//	//{
//	//	; 
//	//}
//
//	//Serial.print("Initializing SD card");
//	//if (!SD.begin(chipSelect)) 
//	//{
//	//	Serial.println("Card failed, or not present");
//	//	// don't do anything more:
//	//	while (1);
//	//}
//	//Serial.println("Card initialized");
//
//	//=====================================================================================================
//	delay(2000);
//	//=====================================================================================================
//
//	// Initialize HB sensor
//	pulseSensor.analogInput(PulseWire);
//	pulseSensor.setThreshold(Threshold);
//
//	// Initialize GSR Sensor
//	long sum = 0;
//
//	for (int i = 0; i < 500; i++)
//	{
//		GSRsensorValue = analogRead(GSR);
//		sum += GSRsensorValue;
//		delay(5);
//	}
//	threshold = sum / 500;
//
//	// Initialize Buttons
//	pinMode(Red_Button, INPUT);
//	pinMode(Blue_Button, INPUT);
//
//	// Initialize Indicators (Led's,BBuzzers,etc.)
//	pinMode(Yellow_LED, OUTPUT);
//	digitalWrite(Yellow_LED, HIGH);
//	digitalWrite(Yellow_LED, LOW);
//
//	pinMode(Red_LED, OUTPUT);
//	digitalWrite(Red_LED, HIGH);
//	digitalWrite(Red_LED, LOW);
//
//	pinMode(Green_LED, OUTPUT);
//	digitalWrite(Green_LED, HIGH);
//	digitalWrite(Green_LED, LOW);
//
//	/*pinMode(Buzzer, OUTPUT); // Not used ATM
//	digitalWrite(Buzzer, HIGH);
//	digitalWrite(Buzzer, LOW);*/
//
//	int myBPM = pulseSensor.getBeatsPerMinute();
//
//	if (pulseSensor.begin())
//	{
//		delay(1000);
//		Serial.print("Initializing Sensors");
//
//		// LED Pattern to show initilization
//		digitalWrite(Green_LED, HIGH);
//		delay(100);
//		digitalWrite(Green_LED, LOW);
//		delay(100);
//
//		digitalWrite(Yellow_LED, HIGH);
//		delay(100);
//		digitalWrite(Yellow_LED, LOW);
//		delay(100);
//
//		digitalWrite(Red_LED, HIGH);
//		delay(100);
//		digitalWrite(Red_LED, LOW);
//		delay(100);
//
//		digitalWrite(Yellow_LED, HIGH);
//		delay(100);
//		digitalWrite(Yellow_LED, LOW);
//		delay(100);
//
//		digitalWrite(Green_LED, HIGH);
//		delay(100);
//		digitalWrite(Green_LED, LOW);
//		delay(100);
//
//		digitalWrite(Yellow_LED, HIGH);
//		delay(100);
//		digitalWrite(Yellow_LED, LOW);
//		delay(100);
//
//		digitalWrite(Red_LED, HIGH);
//		delay(100);
//		digitalWrite(Red_LED, LOW);
//		delay(100);
//
//		digitalWrite(Yellow_LED, HIGH);
//		delay(100);
//		digitalWrite(Yellow_LED, LOW);
//		delay(100);
//
//		digitalWrite(Green_LED, HIGH);
//		delay(100);
//		digitalWrite(Green_LED, LOW);
//
//	}
//	
//
//	//=====================================================================================================
//
//}
//
//
//void loop()
//{
//
//	//// LED Pattern to show initilization
//	//digitalWrite(Green_LED, HIGH);
//	//delay(100);
//	//digitalWrite(Green_LED, LOW);
//	//delay(100);
//
//	//digitalWrite(Yellow_LED, HIGH);
//	//delay(100);
//	//digitalWrite(Yellow_LED, LOW);
//	//delay(100);
//
//	//digitalWrite(Red_LED, HIGH);
//	//delay(100);
//	//digitalWrite(Red_LED, LOW);
//	//delay(100);
//
//	//digitalWrite(Yellow_LED, HIGH);
//	//delay(100);
//	//digitalWrite(Yellow_LED, LOW);
//	//delay(100);
//
//	//digitalWrite(Green_LED, HIGH);
//	//delay(100);
//	//digitalWrite(Green_LED, LOW);
//	//delay(100);
//
//	//digitalWrite(Yellow_LED, HIGH);
//	//delay(100);
//	//digitalWrite(Yellow_LED, LOW);
//	//delay(100);
//
//	//digitalWrite(Red_LED, HIGH);
//	//delay(100);
//	//digitalWrite(Red_LED, LOW);
//	//delay(100);
//
//	//digitalWrite(Yellow_LED, HIGH);
//	//delay(100);
//	//digitalWrite(Yellow_LED, LOW);
//	//delay(100);
//
//	//digitalWrite(Green_LED, HIGH);
//	//delay(100);
//	//digitalWrite(Green_LED, LOW);
//
//
//
//	while (pulseSensor.sawStartOfBeat())
//	{
//		//delay(200);
//
//
//
//		////Initialize Timer
//		//Serial.print("Timer (s): ");
//		//Serial.println(millis() / 1000);
//
//		// Sensors
//
//		// HeartBeat Sensor (Start)
//
//		int calibrate = 0;
//		int BPM;
//
//		BPM = pulseSensor.getBeatsPerMinute() - calibrate; // Calibration
//
//		int myBPM = BPM;
//
//		// Galvanic Skin Response Sensor (Start)
//
//		GSRsensorValue = analogRead(GSR);
//
//		//====================================================================================================
//
//		// SD Card Recording
//
//
//		//File dataFile = SD.open("datalog.txt", FILE_WRITE);
//
//
//		//if (dataFile)
//		//{
//		//	//Data ID
//		//	dataFile.println("Test Subject: ");
//		//	Serial.println("Test Subject: ");
//
//		//	//Timer
//		//	dataFile.print("Timer: ");
//		//	dataFile.println(millis() / 1000);
//
//		//	// BEATS PER MINUTE
//		//	dataFile.print("BPM: ");
//		//	dataFile.println(myBPM);
//		//	Serial.print("BPM: ");
//		//	Serial.println(myBPM);
//
//
//		//	// GALVANIC SKIN RESPONSE
//		//	dataFile.print("GSR:");
//		//	dataFile.println(GSRsensorValue);
//		//	Serial.print("GSR:");
//		//	Serial.println(GSRsensorValue);
//
//
//		//	// Initialize Button 
//
//		//	Red_ButtonState = digitalRead(Red_Button);
//		//	Blue_ButtonState = digitalRead(Blue_Button);
//
//		//	// Red Button	// (Passed)
//		//	if (Red_ButtonState == HIGH)
//		//	{
//		//		// Indicate the red button was pressed
//		//		Serial.println("Angry (Manual Input)");
//		//		dataFile.println("Angry (Manual Input)");
//		//		delay(100);
//		//	}
//		//	else
//		//	{
//
//		//	}
//
//		//	// Blue Button	// (Passed)
//		//	if (Blue_ButtonState == HIGH)
//		//	{
//		//		// Indicate the blue button was pressed
//		//		Serial.println("Anxious (Manual Input)");
//		//		dataFile.println("Anxious (Manual Input)");
//		//		delay(100);
//		//	}
//		//	else
//		//	{
//
//		//	}
//
//		//	if (GSRsensorValue > 400)
//		//	{
//		//		// No Human Detected Using GSR Reading
//		//		delay(500);
//		//		Serial.println("No Human Detected");
//		//		dataFile.println("No Human Detected");
//		//		digitalWrite(Green_LED, LOW);
//		//		digitalWrite(Yellow_LED, LOW);
//		//		digitalWrite(Red_LED, HIGH);
//		//	}
//
//		//	dataFile.close();
//		//}
//
//
//		//else
//		//{
//		//	// if the file isn't open, pop up an error:
//		//	Serial.println("error opening datalog.txt");
//		//}
//
//		Serial.print("BPM: ");
//		Serial.println(BPM);
//		Serial.print("GSR:");
//		Serial.println(GSRsensorValue);
//
//		//if (Red_ButtonState == HIGH)
//		//{
//		//	// Indicate the red button was pressed
//		//	Serial.println("Angry (Manual Input)");
//		//	//dataFile.println("Angry (Manual Input)");
//		//	//delay(100);
//		//}
//		//else
//		//{
//
//		//}
//
//		//// Blue Button	// (Passed)
//		//if (Blue_ButtonState == HIGH)
//		//{
//		//	// Indicate the blue button was pressed
//		//	Serial.println("Anxious (Manual Input)");
//		//	//dataFile.println("Anxious (Manual Input)");
//		//	//delay(100);
//		//}
//		//else
//		//{
//
//		//}
//
//		//if (GSRsensorValue > 500)
//		//{
//		//	// No Human Detected Using GSR Reading
//		//	//delay(500);
//		//	Serial.println("No Human Detected");
//		//	//dataFile.println("No Human Detected");
//		//	digitalWrite(Green_LED, LOW);
//		//	digitalWrite(Yellow_LED, LOW);
//		//	digitalWrite(Red_LED, HIGH);
//		//}
//
//		////======================================================================================================================
//
//		//if (myBPM < 60) // Low Heart Rate (Green Led)
//		//{
//		//	digitalWrite(Green_LED, LOW);
//		//	digitalWrite(Yellow_LED, HIGH);
//		//	digitalWrite(Red_LED, LOW);
//		//}
//
//		//if (myBPM > 67 && myBPM < 180) // Normal Heart Rate (Green Led)
//		//{
//		//	digitalWrite(Green_LED, HIGH);
//		//	digitalWrite(Yellow_LED, LOW);
//		//	digitalWrite(Red_LED, LOW);
//		//}
//
//		//if (myBPM > 180) // Stressed Heart Rate (Yellow Led)
//		//{
//		//	digitalWrite(Green_LED, LOW);
//		//	delay(100);
//		//	digitalWrite(Red_LED, LOW);
//		//	delay(100);
//		//	digitalWrite(Yellow_LED, HIGH);
//		//	delay(100);
//		//	digitalWrite(Yellow_LED, LOW);
//		//	delay(100);
//
//		//	if (GSRsensorValue < 100)
//		//	{
//		//		//delay(100);
//		//		digitalWrite(Green_LED, LOW);
//		//		digitalWrite(Yellow_LED, LOW);
//		//		digitalWrite(Red_LED, HIGH);
//		//	}
//		//}
//
//		//======================================================================================================================
//		delay(500);
//	}
//
//}




//  Variables
int pulsePin = A1;                 // Pulse Sensor purple wire connected to analog pin 0
int blinkPin = 8;                // pin to blink led at each beat
int fadePin = 10;                  // pin to do fancy classy fading blink at each beat
int fadeRate = 0;                 // used to fade LED on with PWM on fadePin


// Volatile Variables, used in the interrupt service routine!
volatile int BPM;                   // int that holds raw Analog in 0. updated every 2mS
volatile int Signal;                // holds the incoming raw data
volatile int IBI = 600;             // int that holds the time interval between beats! Must be seeded! 
volatile boolean Pulse = false;     // "True" when User's live heartbeat is detected. "False" when not a "live beat". 
volatile boolean QS = false;        // becomes true when Arduoino finds a beat.

// Regards Serial OutPut  -- Set This Up to your needs
static boolean serialVisual = true;   // Set to 'false' by Default.  Re-set to 'true' to see Arduino Serial Monitor ASCII Visual Pulse 

volatile int rate[10];                      // array to hold last ten IBI values
volatile unsigned long sampleCounter = 0;          // used to determine pulse timing
volatile unsigned long lastBeatTime = 0;           // used to find IBI
volatile int P = 512;                      // used to find peak in pulse wave, seeded
volatile int T = 512;                     // used to find trough in pulse wave, seeded
volatile int thresh = 525;                // used to find instant moment of heart beat, seeded
volatile int amp = 100;                   // used to hold amplitude of pulse waveform, seeded
volatile boolean firstBeat = true;        // used to seed rate array so we startup with reasonable BPM
volatile boolean secondBeat = false;      // used to seed rate array so we startup with reasonable BPM

void setup()
{
	pinMode(blinkPin, OUTPUT);         // pin that will blink to your heartbeat!
	pinMode(fadePin, OUTPUT);          // pin that will fade to your heartbeat!
	Serial.begin(9600);             // we agree to talk fast!
	interruptSetup();                 // sets up to read Pulse Sensor signal every 2mS 
									  // IF YOU ARE POWERING The Pulse Sensor AT VOLTAGE LESS THAN THE BOARD VOLTAGE, 
									  // UN-COMMENT THE NEXT LINE AND APPLY THAT VOLTAGE TO THE A-REF PIN
									  //   analogReference(EXTERNAL);   
}


//  Where the Magic Happens
void loop()
{
	String Graph;
	serialOutput();

	if (QS == true) // A Heartbeat Was Found
	{
		// BPM and IBI have been Determined
		// Quantified Self "QS" true when arduino finds a heartbeat
		fadeRate = 255; // Makes the LED Fade Effect Happen, Set 'fadeRate' Variable to 255 to fade LED with pulse
		serialOutputWhenBeatHappens(); // A Beat Happened, Output that to serial.     
		QS = false; // reset the Quantified Self flag for next time    
	}

	ledFadeToBeat(); // Makes the LED Fade Effect Happen 
	delay(20); //  take a break

}

void ledFadeToBeat()
{
	fadeRate -= 15;                         //  set LED fade value
	fadeRate = constrain(fadeRate, 0, 255);   //  keep LED fade value from going into negative numbers!
	analogWrite(fadePin, fadeRate);          //  fade LED
}

void interruptSetup()
{
	// Initializes Timer2 to throw an interrupt every 2mS.
	TCCR2A = 0x02;     // DISABLE PWM ON DIGITAL PINS 3 AND 11, AND GO INTO CTC MODE
	TCCR2B = 0x06;     // DON'T FORCE COMPARE, 256 PRESCALER 
	OCR2A = 0X7C;      // SET THE TOP OF THE COUNT TO 124 FOR 500Hz SAMPLE RATE
	TIMSK2 = 0x02;     // ENABLE INTERRUPT ON MATCH BETWEEN TIMER2 AND OCR2A
	sei();             // MAKE SURE GLOBAL INTERRUPTS ARE ENABLED      
}

void serialOutput()
{   // Decide How To Output Serial. 
	if (serialVisual == true)
	{
		arduinoSerialMonitorVisual('-', Signal);   // goes to function that makes Serial Monitor Visualizer
	}
	else
	{
		sendDataToSerial('S', Signal);     // goes to sendDataToSerial function
	}
}

void serialOutputWhenBeatHappens()
{
	if (serialVisual == true) //  Code to Make the Serial Monitor Visualizer Work
	{
		Serial.print("*** Heart-Beat Happened *** ");  //ASCII Art Madness
		Serial.print("BPM: ");
		Serial.println(BPM);
	}
	else
	{
		sendDataToSerial('B', BPM);   // send heart rate with a 'B' prefix
		sendDataToSerial('Q', IBI);   // send time between beats with a 'Q' prefix
	}
}

void arduinoSerialMonitorVisual(char symbol, int data)
{
	const int sensorMin = 0;      // sensor minimum, discovered through experiment
	const int sensorMax = 1024;    // sensor maximum, discovered through experiment
	int sensorReading = data; // map the sensor range to a range of 12 options:
	int range = map(sensorReading, sensorMin, sensorMax, 0, 11);
	// do something different depending on the 
	// range value:
	switch (range)
	{
	case 0:
		Serial.println("");     /////ASCII Art Madness
		break;
	case 1:
		Serial.println("---");
		break;
	case 2:
		Serial.println("------");
		break;
	case 3:
		Serial.println("---------");
		break;
	case 4:
		Serial.println("------------");
		break;
	case 5:
		Serial.println("--------------|-");
		break;
	case 6:
		Serial.println("--------------|---");
		break;
	case 7:
		Serial.println("--------------|-------");
		break;
	case 8:
		Serial.println("--------------|----------");
		break;
	case 9:
		Serial.println("--------------|----------------");
		break;
	case 10:
		Serial.println("--------------|-------------------");
		break;
	case 11:
		Serial.println("--------------|-----------------------");
		break;
	}
}


void sendDataToSerial(char symbol, int data)
{
	Serial.print(symbol);
	Serial.println(data);
}

ISR(TIMER2_COMPA_vect) //triggered when Timer2 counts to 124
{
	cli();                                      // disable interrupts while we do this
	Signal = analogRead(pulsePin);              // read the Pulse Sensor 
	sampleCounter += 2;                         // keep track of the time in mS with this variable
	int N = sampleCounter - lastBeatTime;       // monitor the time since the last beat to avoid noise
												//  find the peak and trough of the pulse wave
	if (Signal < thresh && N >(IBI / 5) * 3) // avoid dichrotic noise by waiting 3/5 of last IBI
	{
		if (Signal < T) // T is the trough
		{
			T = Signal; // keep track of lowest point in pulse wave 
		}
	}

	if (Signal > thresh && Signal > P)
	{          // thresh condition helps avoid noise
		P = Signal;                             // P is the peak
	}                                        // keep track of highest point in pulse wave

  //  NOW IT'S TIME TO LOOK FOR THE HEART BEAT
  // signal surges up in value every time there is a pulse
	if (N > 250)
	{                                   // avoid high frequency noise
		if ((Signal > thresh) && (Pulse == false) && (N > (IBI / 5) * 3))
		{
			Pulse = true;                               // set the Pulse flag when we think there is a pulse
			digitalWrite(blinkPin, HIGH);                // turn on pin 13 LED
			int Graph = 1;
			IBI = sampleCounter - lastBeatTime;         // measure time between beats in mS
			lastBeatTime = sampleCounter;               // keep track of time for next pulse

			if (secondBeat)
			{                        // if this is the second beat, if secondBeat == TRUE
				secondBeat = false;                  // clear secondBeat flag
				for (int i = 0; i <= 9; i++) // seed the running total to get a realisitic BPM at startup
				{
					rate[i] = IBI;
				}
			}

			if (firstBeat) // if it's the first time we found a beat, if firstBeat == TRUE
			{
				firstBeat = false;                   // clear firstBeat flag
				secondBeat = true;                   // set the second beat flag
				sei();                               // enable interrupts again
				return;                              // IBI value is unreliable so discard it
			}
			// keep a running total of the last 10 IBI values
			word runningTotal = 0;                  // clear the runningTotal variable    

			for (int i = 0; i <= 8; i++)
			{                // shift data in the rate array
				rate[i] = rate[i + 1];                  // and drop the oldest IBI value 
				runningTotal += rate[i];              // add up the 9 oldest IBI values
			}

			rate[9] = IBI;                          // add the latest IBI to the rate array
			runningTotal += rate[9];                // add the latest IBI to runningTotal
			runningTotal /= 10;                     // average the last 10 IBI values 
			BPM = 60000 / runningTotal;               // how many beats can fit into a minute? that's BPM!
			QS = true;                              // set Quantified Self flag 
			// QS FLAG IS NOT CLEARED INSIDE THIS ISR

		}

	}

	if (Signal < thresh && Pulse == true)
	{   // when the values are going down, the beat is over
		digitalWrite(blinkPin, LOW);            // turn off pin 13 LED
		int Graph = 0;
		Pulse = false;                         // reset the Pulse flag so we can do it again
		amp = P - T;                           // get amplitude of the pulse wave
		thresh = amp / 2 + T;                    // set thresh at 50% of the amplitude
		P = thresh;                            // reset these for next time
		T = thresh;
	}

	if (N > 2500)
	{                           // if 2.5 seconds go by without a beat
		thresh = 512;                          // set thresh default
		P = 512;                               // set P default
		T = 512;                               // set T default
		lastBeatTime = sampleCounter;          // bring the lastBeatTime up to date        
		firstBeat = true;                      // set these to avoid noise
		secondBeat = false;                    // when we get the heartbeat back
	}



	sei();                                   // enable interrupts when youre done!
}// end isr





