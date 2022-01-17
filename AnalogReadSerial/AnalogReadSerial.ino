/*
  AnalogReadSerial
  Reads an analog input on pin 0, prints the result to the serial monitor.
  Attach the center pin of a potentiometer to pin A0, and the outside pins to +5V and ground.
 
 This example code is in the public domain.
 */
const int sensorValue_Max = 400;
int lc = 0;

// the setup routine runs once when you press reset:
void setup() {
  // initialize serial communication at 9600 bits per second:
  pinMode(3,OUTPUT);
  Serial.begin(4800);
}

// the loop routine runs over and over again forever:
void loop() {
  // read the input on analog pin 0:
  // 0-1023
    //int sensorValue = analogRead(A1);
    int sensorValue = analogRead(A1);
    int sensorValue2 = analogRead(A2);

    // 0-460
    //Serial.println("SensorValue1="+String(sensorValue));

    if (sensorValue < 0) {
      sensorValue = 0;
    }
    if (sensorValue > sensorValue_Max) {
      sensorValue = sensorValue_Max;
    }    

    int intensity = map(sensorValue,0,sensorValue_Max,0,255);
    analogWrite(3,intensity);
    analogWrite(4,intensity);

    lc++;
    if (lc % 100 == 0) {
      Serial.print("SensorValue1="+String(sensorValue));
      Serial.print("\t\tSensorValue2="+String(sensorValue2));
      Serial.println("\t\tintensity="+String(intensity));
      lc=0;
    }

    delay(10);        // delay in between reads for stability
}
