void setup() {
  // put your setup code here, to run once:
  Serial.begin(115200);
}

void loop() {
  // put your main code here, to run repeatedly:
  int sensorValue = analogRead(A1);
  int tdsValue = analogRead(A3);
  int pH = analogRead(A4);
  float voltage = tdsValue*5.0/1024.0;
  float ppm = 133.42 * voltage * voltage * voltage - 255.86 * voltage * voltage + 857.39 * voltage * 0.5;
  
  float caliValue = 21.34-11.9;
  float volt = (float)pH * 5.0 / 1024 / 6;
  float phValue = -5.70 * volt + caliValue;

  /*Serial.println("sensorValue");
  Serial.println(sensorValue);
  Serial.println("tdsValue");
  Serial.println(tdsValue);
  Serial.println("ppm");
  Serial.println(ppm);

  Serial.println("pH value");
  Serial.println(phValue);*/

  if (sensorValue < 614 || phValue > 8.5 || phValue < 6.5 || ppm > 500) {
    Serial.println ("not safe");
  }
  else {Serial.println("safe");}


  delay(100);

  
}
