// Predictive Maintenance System

const int tempPin = A0;
const int buttonPin = 7;

const int greenLED = 8;
const int motorIN4 = 9;
const int motorIN3 = 11;
const int redLED = 12;
const int buzzer = 13;

void setup()
{
  pinMode(buttonPin, INPUT_PULLUP);

  pinMode(greenLED, OUTPUT);
  pinMode(redLED, OUTPUT);
  pinMode(buzzer, OUTPUT);

  pinMode(motorIN3, OUTPUT);
  pinMode(motorIN4, OUTPUT);

  Serial.begin(9600);

  Serial.println("Predictive Maintenance System Started");
}

void loop()
{
  // TMP36 Reading
  int sensorValue = analogRead(tempPin);

  float voltage = sensorValue * (5.0 / 1023.0);

  float temperature = (voltage - 0.5) * 100.0;

  // Button Reading
  bool vibrationDetected = false;

  if (digitalRead(buttonPin) == LOW)
  {
    vibrationDetected = true;
  }

  Serial.print("Temperature: ");
  Serial.print(temperature);
  Serial.print(" C | Vibration: ");

  if (vibrationDetected)
    Serial.println("DETECTED");
  else
    Serial.println("NORMAL");


  // FAULT CONDITION

  if (temperature > 80)
  {
    Serial.println("STATUS: FAULT");

    digitalWrite(greenLED, LOW);
    digitalWrite(redLED, HIGH);
    digitalWrite(buzzer, HIGH);

    // Motor OFF
    digitalWrite(motorIN3, LOW);
    digitalWrite(motorIN4, LOW);
  }

  // WARNING CONDITION

  else if (temperature >= 40 || vibrationDetected)
  {
    Serial.println("STATUS: WARNING");

    digitalWrite(greenLED, LOW);
    digitalWrite(redLED, HIGH);
    digitalWrite(buzzer, LOW);

    // Motor ON
    digitalWrite(motorIN3, HIGH);
    digitalWrite(motorIN4, LOW);
  }


  // HEALTHY CONDITION

  else
  {
    Serial.println("STATUS: HEALTHY");

    digitalWrite(greenLED, HIGH);
    digitalWrite(redLED, LOW);
    digitalWrite(buzzer, LOW);

    // Motor ON
    digitalWrite(motorIN3, HIGH);
    digitalWrite(motorIN4, LOW);
  }

  Serial.println("----------------------------");

  delay(1000);
}