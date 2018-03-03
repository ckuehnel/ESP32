/*
  ESP32 Test
  (c) Claus Kuehnel 2018-03-01 info@ckuehnel.ch
*/

#define LED 2   // adapt it

byte count = 0;

void getChipTemp()
{
  float temp = temperatureRead();
  Serial.print("ESP32 Chip Temperature = ");
  Serial.print(temp);
  Serial.println(" °C"); 
}

void setup() 
{
  pinMode(LED, OUTPUT);
  Serial.begin(115200);
  delay(1000); // waiting to start the monitor
  Serial.print("Hi there, here is "); 
  Serial.println("ESP32 Dev Module");     
  Serial.print("CPU clock frequency = ");
  Serial.print(ESP.getCpuFreqMHz());
  Serial.println(" MHz");
  getChipTemp();
  Serial.print("Chip Revision: ");
  Serial.println(ESP.getChipRevision());
  uint64_t chipid = ESP.getEfuseMac();     //The chip ID is essentially its MAC address(length: 6 bytes)
  Serial.printf("ESP32 Chip ID = %04X",(uint16_t)(chipid>>32));         //print High 2 bytes
  Serial.printf("%08X\n",(uint32_t)chipid);                             //print Low  4 bytes
  Serial.print("Flash available [KB]: ");
  Serial.println(ESP.getFlashChipSize()/1024);
  Serial.print("Flash Chip Size [KB]: ");
  Serial.println(ESP.getFlashChipSize()/1024);
  Serial.print("Flash frequency [MHz]: ");
  Serial.println(ESP.getFlashChipSpeed()/1000000);
  Serial.print("Free Heap [KB]: ");
  Serial.println(ESP.getFreeHeap()/1024);
}

void loop() 
{
  Serial.print(".");
  count++;
  if (count == 33)
  {
    Serial.println();
    getChipTemp();
    count=0;
  }
  digitalWrite(LED, LOW);
  delay(980);
  digitalWrite(LED, HIGH);
  delay(20);
}
