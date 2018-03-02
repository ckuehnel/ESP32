//
// Title        : IO Loop
// Author       : Claus Kuehnel
// Date         : 2018-03-01
// Id           : IOLoop_arduino_ESP32.ino
// Version      : 1.8.5
// based on     : 
//
// DISCLAIMER:
// The author is in no way responsible for any problems or damage caused by
// using this code. Use at your own risk.
//
// LICENSE:
// This code is distributed under the GNU Public License
// which can be found at http://www.gnu.org/licenses/gpl.txt
//

#define SERIAL Serial

const int IOPin = 2;    
unsigned long t = 0;


void setup() 
{ 
  pinMode(IOPin, OUTPUT);

  delay(5000);
  SERIAL.begin(115200);
  SERIAL.println("I/O Loop - ESP32");
  SERIAL.print("CPU clock frequency = ");
  SERIAL.print(ESP.getCpuFreqMHz());
  SERIAL.println(" MHz");
  SERIAL.println("Measure IO frequency on Pin 2");
  t = micros();
  digitalWrite(IOPin, HIGH);                  
  digitalWrite(IOPin, LOW);
  t = micros() - t;
    
  SERIAL.print("Runtime = ");
  SERIAL.print(t);
  SERIAL.println(" us\n");
} 
  
void loop() 
{  
  digitalWrite(IOPin, HIGH);                    
  digitalWrite(IOPin, LOW); 
}
