// This Code is for Accident avoidance rover

const int en1 = 9;
const int en2 = 3;
const int inp1 = 2;
const int inp2 = 4;
const int inp3 = 7;
const int inp4 = 8;
char charRead;
String inputString = "";

//For ultrasonic sensor
int trigPin = 10;
int echoPin = 11;
  
void setup() {
  Serial.begin(9600);

  pinMode(led, OUTPUT);
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);

  pinMode(en1, OUTPUT);
  pinMode(en2, OUTPUT);
  pinMode(inp1, OUTPUT);
  pinMode(inp2, OUTPUT);
  pinMode(inp3, OUTPUT);
  pinMode(inp4, OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:

  // Calculating distance of obstacle from rover
  long duration, distance;
  digitalWrite(trigPin, HIGH);
  delay(1);
  digitalWrite(trigPin, LOW);
  duration = pulseIn(echoPin, HIGH);
  distance = (duration / 2) / 29.1;
  Serial.print(distance);
  Serial.println("CM");
  delay(10);

  if ((distance <= 17))
  {
    // To Stop
    digitalWrite(inp1, LOW);
    digitalWrite(inp2, LOW);
    digitalWrite(inp3, LOW);
    digitalWrite(inp4, LOW);
    if (Serial.available()) {
      charRead = Serial.read();
      if (charRead != 'T') {
        inputString += charRead;
      } else {
        if (inputString == "backward") {
          // To move backward
          digitalWrite(inp1, LOW);
          digitalWrite(inp2, HIGH);
          digitalWrite(inp3, LOW);
          digitalWrite(inp4, HIGH);
          delay(1500);
        }
        inputString = "";
      }
    }
  }
  else {
    if (Serial.available()) {
      charRead = Serial.read();
      if (charRead != 'T') {
        inputString += charRead;
      } else {
        if (inputString == "forward") {
          // To move Forward
          digitalWrite(inp1, HIGH);
          digitalWrite(inp2, LOW);
          digitalWrite(inp3, HIGH);
          digitalWrite(inp4, LOW);
        } 
        else if (inputString == "backward") {
          // To move backward
          digitalWrite(inp1, LOW);
          digitalWrite(inp2, HIGH);
          digitalWrite(inp3, LOW);
          digitalWrite(inp4, HIGH);
        }
        else if (inputString == "fleft") {
          // To move left
          digitalWrite(inp1, HIGH);
          digitalWrite(inp2, LOW);
          digitalWrite(inp3, LOW);
          digitalWrite(inp4, LOW);
        } else if (inputString == "fright") {
          // To move right
          digitalWrite(inp1, LOW);
          digitalWrite(inp2, LOW);
          digitalWrite(inp3, HIGH);
          digitalWrite(inp4, LOW);
        }
        else if (inputString == "bleft") {
          // To move back left
          digitalWrite(inp1, LOW);
          digitalWrite(inp2, LOW);
          digitalWrite(inp3, LOW);
          digitalWrite(inp4, HIGH);
        }
        else if (inputString == "bright") {
          // To move back right
          digitalWrite(inp1, LOW);
          digitalWrite(inp2, HIGH);
          digitalWrite(inp3, LOW);
          digitalWrite(inp4, LOW);
        }
        else if (inputString == "break") {
          // To Stop
          analogWrite(en1, 50);
          analogWrite(en2, 50);
          delay(550);
          digitalWrite(inp1, LOW);
          digitalWrite(inp2, LOW);
          digitalWrite(inp3, LOW);
          digitalWrite(inp4, LOW);
          analogWrite(en1, 150);
          analogWrite(en2, 150);
        }
        else if (inputString == "maxspeed") {
          // Max speed
          analogWrite(en1, 250);
          analogWrite(en2, 250);
        }
        else if (inputString == "medspeed") {
          // Medium Speed
          analogWrite(en1, 180);
          analogWrite(en2, 180);
        }
        else if (inputString == "lowspeed") {
          // Low speed
          analogWrite(en1, 90);
          analogWrite(en2, 90);
        }
        else {
          // Stop
          digitalWrite(inp1, LOW);
          digitalWrite(inp2, LOW);
          digitalWrite(inp3, LOW);
          digitalWrite(inp4, LOW);
        }
        inputString = "";
      }
    }
  }
}