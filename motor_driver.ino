// ---------- EMG TO MOTOR CONTROL ----------

const int emgPin = A0;

const int IN1 = 7;
const int IN2 = 6;
const int ENA = 5;

const int samples = 10;

// Adjust after testing
int threshold = 50;     

void setup() {

  Serial.begin(9600);

  pinMode(IN1, OUTPUT);
  pinMode(IN2, OUTPUT);
  pinMode(ENA, OUTPUT);
}

void loop() {

  long sum = 0;

  // Filtered EMG reading
  for (int i = 0; i < samples; i++) {
    sum += analogRead(emgPin);
    delay(2);
  }

  int emgValue = sum / samples;

  Serial.println(emgValue);

  if (emgValue > threshold) {

    // Map EMG strength to motor speed (0–255)
    int speedValue = map(emgValue, threshold, 150, 120, 255);
    speedValue = constrain(speedValue, 120, 255);

    digitalWrite(IN1, HIGH);
    digitalWrite(IN2, LOW);
    analogWrite(ENA, speedValue);

  } else {

    digitalWrite(IN1, LOW);
    digitalWrite(IN2, LOW);
    analogWrite(ENA, 0);
  }

  delay(30);
}
