/*
  ESP32 Test of DAC & external ADC ADS1015
  (c) Claus Kuehnel 2018-03-01 info@ckuehnel.ch

  ESP32 has two 8-bit DAC channels, connected to GPIO25 (Channel 1) and GPIO26 (Channel 2)
  The internal ADC is replaced by an ADS1015 breakout board
  Connect GPIO25 & A0 of ADS1015 breakout board for this test
*/
#include <Wire.h>
#include <Adafruit_ADS1015.h>

Adafruit_ADS1015 ads1015(0x49);  // check the device addr before

#define LED 2

uint8_t DAC_Channel_1 = 25;
uint8_t dac;
uint16_t adc;
float dacv, adcv, diff;

void setup() 
{
   Serial.begin(115200);
   ads1015.setGain(GAIN_ONE);  // +/- 2.048V
   ads1015.begin();
   pinMode(LED, OUTPUT);
   delay(5000);
   Serial.print("Gain = "); Serial.println(ads1015.getGain());
   Serial.println();
   Serial.println("\n DAC\tDACv\tADC\t ADCv\t DIFF");
}

void loop()
{
  for (dac = 0; dac < 256; dac++)
  {
    digitalWrite(LED, HIGH);
    dacWrite(DAC_Channel_1, dac);
    dacv =dac*3.3/256;
    delay(100);
    adc = ads1015.readADC_SingleEnded(0);
    adcv = adc * 0.002;
    diff = adcv - dacv;
    Serial.printf("%4d\t%8.4f\t%6d\t%8.4f\t%8.4f\n", dac, dacv, adc, adcv, diff);
    digitalWrite(LED, LOW);
    delay(50);
  }
}


   
