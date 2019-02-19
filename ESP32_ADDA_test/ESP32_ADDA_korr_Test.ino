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
float dacv, adcv, diffv;

void setup() 
{
   Serial.begin(115200);
   pinMode(LED, OUTPUT);
   delay(5000);
   Serial.println("\n DAC\tADC\t DIFF");
}

void loop()
{
  for (dac = 0; dac < 256; dac++)
  {
    digitalWrite(LED, HIGH);
    dacWrite(DAC_Channel_1, dac);
    delay(100);
    //adc = analogRead(ADC19);
    dacv = dac*3.3/256;
    adcv = ReadVoltage(ADC19);
    diffv = adcv - dacv;
    Serial.printf("%8.4f\t%8.4f\t%8.4f\n", dacv, adcv, diffv);
    digitalWrite(LED, LOW);
    delay(50);
  }
}

double ReadVoltage(byte pin)
{
  double reading = analogRead(pin); // Reference voltage is 3v3 so maximum reading is 3v3 = 4095 in range 0 to 4095
  if(reading < 1 || reading > 4095) return 0;
  // return -0.000000000009824 * pow(reading,3) + 0.000000016557283 * pow(reading,2) + 0.000854596860691 * reading + 0.065440348345433;
  return -0.000000000000016 * pow(reading,4) + 0.000000000118171 * pow(reading,3)- 0.000000301211691 * pow(reading,2)+ 0.001109019271794 * reading + 0.034143524634089;
} // Added an improved polynomial, use either, comment out as required


/* ADC readings v voltage
 *  y = -0.000000000009824x3 + 0.000000016557283x2 + 0.000854596860691x + 0.065440348345433
 // Polynomial curve match, based on raw data thus:
 *   464     0.5
 *  1088     1.0
 *  1707     1.5
 *  2331     2.0
 *  2951     2.5 
 *  3775     3.0
 */
   
