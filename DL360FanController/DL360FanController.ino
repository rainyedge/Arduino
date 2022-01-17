

uint16_t fans[6][2]={
    {A5,11},
    {A4,10},
    {A3,9},
    {A2,6},
    {A1,5},
    {A0,3},
};

double cor_fact[6]={0.15,0.15,0.20,0.20,0.15,0};
double min_fan[6]={0.13,0.14,0.15,0.15,0.14,0.13};

void setup() {
 uint8_t i;
 for(i=0;i<6;i++){
    pinMode(fans[i][0], INPUT);
    pinMode(fans[i][1], OUTPUT);
 }
  Serial.begin(115200);
  Serial.println("HP fan proxy");

}


void loop() {
 uint8_t i;
 uint16_t ana_in;
 double pwm,out;
 uint8_t pwm_out;
 for(i=0;i<6;i++){
    ana_in=analogRead(fans[i][0]);
    //5V=1023
    //3.3V=673
    //inverted PWM so 1-
    pwm = (double)(715-ana_in)/715;
    if((pwm>0.2)&&(pwm <0.5)){
      out = pwm-cor_fact[i];
      if (out<min_fan[i]) {
        out = min_fan[i];
      }
    } else {
      out = pwm;
    }
    pwm_out=255-out*255;
    analogWrite(fans[i][1],pwm_out);
    Serial.print(" Fan[");Serial.print(i);Serial.print("] iLO:");Serial.print(pwm*100);Serial.print("% Me:");Serial.print(out*100);Serial.print("% Diff:");Serial.print((pwm-out)*100);Serial.println("%");
 }
  Serial.println("---");
  delay(1000);                       // wait for a second
}
