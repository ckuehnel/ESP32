/*
  ESP32 Test of DAC & ADC
  (c) Claus Kuehnel 2018-03-01 info@ckuehnel.ch

  ESP32 has two 8-bit DAC channels, connected to GPIO25 (Channel 1) and GPIO26 (Channel 2)
  There are 16 ADC channels. ADC19 goes to GPIO26. 
  Connect GPIO25 & GPIO26 fpr this test.
*/

#define LED 2

uint8_t DAC_Channel_1 = 25;
uint8_t ADC19 = 26;
uint8_t dac;
uint16_t adc;

void setup() 
{
   Serial.begin(115200);
   pinMode(LED, OUTPUT);
   delay(5000);
   Serial.println("\n DAC\tADC\t DIFF");
}

void loop()
{
  int16_t diff;
  
  for (dac = 0; dac < 256; dac++)
  {
    digitalWrite(LED, HIGH);
    delay(100);
    dacWrite(DAC_Channel_1, dac);
    delay(100);
    adc = analogRead(ADC19);
    diff = 16 * dac - adc;
    Serial.printf("%4d\t%6d\t%4d\n", dac, adc, diff);
    digitalWrite(LED, LOW);
    delay(900);
  }
}


   
