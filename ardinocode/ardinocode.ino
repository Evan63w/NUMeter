/* This code was written for Northwestern University's 2023 IEEE Showcase
// The NUMeter is a device that uses pH, TDS, and turbidity to determine
whether a water sample is safe to drink */

void setup()
{
  Serial.begin(115200);
}

void loop()
{
  int turbidityValue = analogRead(A1);
  int tdsValue = analogRead(A3);
  int pH = analogRead(A4);
  float voltage = tdsValue * 5.0 / 1024.0;
  float ppm = 133.42 * voltage * voltage * voltage - 255.86 * voltage * voltage + 857.39 * voltage * 0.5;

  float caliValue = 21.34 - 11.9; // value used to calibrate sensor to known pH test value
  float volt = (float)pH * 5.0 / 1024 / 6;
  float phValue = -5.70 * volt + caliValue;

  if (sensorValue < 614 || phValue > 8.5 || phValue < 6.5 || ppm > 500)
  {
    Serial.println("not safe");
  }
  else
  {
    Serial.println("safe");
  }

  delay(100);
}
