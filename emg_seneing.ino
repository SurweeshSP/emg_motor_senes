// ---------- EMG ANALOG READ (FILTERED) ----------

const int emgPin = A0;
const int samples = 10;   // Number of samples for averaging

void setup() {
  Serial.begin(9600);
}

void loop() {

  long sum = 0;

  // Take multiple samples for stability
  for (int i = 0; i < samples; i++) {
    sum += analogRead(emgPin);
    delay(2);
  }

  int emgValue = sum / samples;   // Average value

  Serial.println(emgValue);

  delay(20);
}
