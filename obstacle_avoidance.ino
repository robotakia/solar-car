#define trigPin 9
#define echoPin 10
#define ena 6
#define in1 2
#define in2 3
#define enb 7
#define in3 4
#define in4 5

void setup() {
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
  pinMode(ena, OUTPUT);
  pinMode(in1, OUTPUT);
  pinMode(in2, OUTPUT);
  pinMode(enb, OUTPUT);
  pinMode(in3, OUTPUT);
  pinMode(in4, OUTPUT);
  Serial.begin(9600);
}

void loop() {
  long duration, distance;
  
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);
  
  duration = pulseIn(echoPin, HIGH);
  distance = duration * 0.034 / 2;
  
  Serial.print("Distance: ");
  Serial.print(distance);
  Serial.println(" cm");

  if (distance < 20) {
    // Turn left to avoid obstacle
    digitalWrite(in1, LOW);
    digitalWrite(in2, HIGH);
    analogWrite(ena, 150);
    digitalWrite(in3, HIGH);
    digitalWrite(in4, LOW);
    analogWrite(enb, 150);
    delay(500);
  }
  else {
    // Move forward
    digitalWrite(in1, LOW);
    digitalWrite(in2, HIGH);
    analogWrite(ena, 255);
    digitalWrite(in3, LOW);
    digitalWrite(in4, HIGH);
    analogWrite(enb, 255);
  }
}
