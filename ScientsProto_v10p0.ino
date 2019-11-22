#if CONFIG_FREERTOS_UNICORE
#define ARDUINO_RUNNING_CORE 0
#else
#define ARDUINO_RUNNING_CORE 1
#endif

#include "heltec.h"

// define two tasks for Blink & AnalogRead
void TaskBlink( void *pvParameters );
void TaskAnalogReadA3( void *pvParameters );


void setup() {
 // initialize serial communication at 115200 bits per second:
  Serial.begin(115200);

   Heltec.begin(true /*DisplayEnable Enable*/, false /*LoRa Disable*/, true /*Serial Enable*/);
   
 
  
  // Now set up two tasks to run independently.
  xTaskCreatePinnedToCore(
    TaskBlink
    ,  "TaskBlink"   // A name just for humans
    ,  1024  // This stack size can be checked & adjusted by reading the Stack Highwater
    ,  NULL
    ,  2  // Priority, with 3 (configMAX_PRIORITIES - 1) being the highest, and 0 being the lowest.
    ,  NULL 
    ,  ARDUINO_RUNNING_CORE);

  xTaskCreatePinnedToCore(
    TaskAnalogReadA3
    ,  "AnalogReadA3"
    ,  1024  // Stack size
    ,  NULL
    ,  1  // Priority
    ,  NULL 
    ,  ARDUINO_RUNNING_CORE);

  // Now the task scheduler, which takes over control of scheduling individual tasks, is automatically started.
  

}

void loop() {
  // put your main code here, to run repeatedly:

}


void TaskBlink(void *pvParameters)  // This is a task.
{
  (void) pvParameters;

/*
  Blink
  Turns on an LED on for one second, then off for one second, repeatedly.
    
  If you want to know what pin the on-board LED is connected to on your ESP32 model, check
  the Technical Specs of your board.
*/

  // initialize digital LED_BUILTIN on pin 13 as an output.
  pinMode(LED_BUILTIN, OUTPUT);

  for (;;) // A Task shall never return or exit.
  {
      Heltec.display->clear();
    digitalWrite(LED_BUILTIN, HIGH);   // turn the LED on (HIGH is the voltage level)
      Heltec.display->drawString(64, 15, "ON");
      Heltec.display->display();
    vTaskDelay(1000);  // one tick delay (100ms) in between reads for stability
      Heltec.display->clear();
      Heltec.display->drawString(64, 15, "OFF");
      Heltec.display->display();
    digitalWrite(LED_BUILTIN, LOW);    // turn the LED off by making the voltage LOW
    vTaskDelay(1000);  // one tick delay (100ms) in between reads for stability
  }
}

void TaskAnalogReadA3(void *pvParameters)  // This is a task.
{
  (void) pvParameters;
  
/*
  AnalogReadSerial
  Reads an analog input on pin A3, prints the result to the serial monitor.
  Graphical representation is available using serial plotter (Tools > Serial Plotter menu)
  Attach the center pin of a potentiometer to pin A3, and the outside pins to +5V and ground.

  This example code is in the public domain.
*/

  for (;;)
  {
    // read the input on analog pin A26:
    int sensorValueA3 = analogRead(26);
    // print out the value you read:
    Serial.println(sensorValueA3);
    vTaskDelay(10);  // one tick delay (15ms) in between reads for stability
  }
}
