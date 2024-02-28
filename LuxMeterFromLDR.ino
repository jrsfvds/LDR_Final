




#define LDR_PIN                   0
#define MAX_ADC_READING           1023
#define ADC_REF_VOLTAGE           5.0
#define REF_RESISTANCE            2000 
#define LUX_CALC_SCALAR           1246135
#define LUX_CALC_EXPONENT         -1.03548

void setup(void) 
{
  Serial.begin(9600);
  Serial.println(F("Light Sensor Test")); Serial.println("");
  


  Serial.println(F("Sensor, LCD and SD Card are Configured."));
}


void loop(void) 
{  
  
  int   ldrRawData;
  float resistorVoltage, ldrVoltage;
  float ldrResistance;
  float ldrLux;

  ldrRawData = analogRead(LDR_PIN);
  
  // RESISTOR VOLTAGE_CONVERSION
  resistorVoltage = (float)ldrRawData / MAX_ADC_READING * ADC_REF_VOLTAGE;

  // voltage across the LDR is the 5V supply minus the 2k resistor voltage
  ldrVoltage = ADC_REF_VOLTAGE - resistorVoltage;
  
  // LDR_RESISTANCE_CONVERSION
  ldrResistance = ldrVoltage/resistorVoltage * REF_RESISTANCE;
  
  // LDR_LUX
  ldrLux = LUX_CALC_SCALAR * pow(ldrResistance, LUX_CALC_EXPONENT);
 
  // print out the results
  Serial.print("Raw Data   : "); Serial.println(ldrRawData);
  Serial.print("Voltage    : "); Serial.print(ldrVoltage); Serial.println(" volts");
  Serial.print("Resistance : "); Serial.print(ldrResistance); Serial.println(" Ohms");
  Serial.print("Illuminance: "); Serial.print(ldrLux); Serial.println(" lux");

  
  delay(500);
}
