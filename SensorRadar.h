const int frontTriggerPin = A0; //7;
const int frontEchoPin = A1; //6;

const int leftTriggerPin = A2; //10;
const int leftEchoPin = A3; //11;

const int rightTriggerPin = A4; //7;
const int rightEchoPin = A5; //6;

volatile float maxFrontDistance = 25.00;
volatile float frontDuration, frontDistanceCm, leftDuration, leftDistanceCm, rightDuration, rightDistanceCm;
volatile float maxLeftDistance, maxRightDistance = 20.00;

void radar_Setup() {
  // ultrasonic
  pinMode(frontTriggerPin, OUTPUT);
  pinMode(frontEchoPin   , INPUT);

  pinMode(leftTriggerPin , OUTPUT);
  pinMode(leftEchoPin    , INPUT);

  pinMode(rightTriggerPin, OUTPUT);
  pinMode(rightEchoPin   , INPUT);
}

void radarCheckDistFrente() {
    digitalWrite(frontTriggerPin, LOW);  //para generar un pulso limpio ponemos a LOW 4us
    delayMicroseconds(4);
    digitalWrite(frontTriggerPin, HIGH);  //generamos Trigger (disparo) de 10us
    delayMicroseconds(10);
    digitalWrite(frontTriggerPin, LOW);
    frontDuration = pulseIn(frontEchoPin, HIGH);  //medimos el tiempo entre pulsos, en microsegundos
    frontDistanceCm = frontDuration * 10 / 292 / 2;  //convertimos a distancia, en cm
  
    if (frontDistanceCm < maxFrontDistance) {
        #if _DEBUG
        Serial.print("Distancia Frente: ");
        Serial.print(frontDistanceCm);
        Serial.println(" cm");
        #endif
    }
}

void radarCheckDistEsquerda() {
    digitalWrite(leftTriggerPin, LOW);  //para generar un pulso limpio ponemos a LOW 4us
    delayMicroseconds(4);
    digitalWrite(leftTriggerPin, HIGH);  //generamos Trigger (disparo) de 10us
    delayMicroseconds(10);
    digitalWrite(leftTriggerPin, LOW);
    leftDuration = pulseIn(leftEchoPin, HIGH);  //medimos el tiempo entre pulsos, en microsegundos
    leftDistanceCm = leftDuration * 10 / 292 / 2;  //convertimos a distancia, en cm
    #if _DEBUG
    Serial.print("Distancia esquerda: ");
    Serial.print(leftDistanceCm);
    Serial.println(" cm");
    #endif
}

void radarCheckDistDireita() {
    digitalWrite(rightTriggerPin, LOW);  //para generar un pulso limpio ponemos a LOW 4us
    delayMicroseconds(4);
    digitalWrite(rightTriggerPin, HIGH);  //generamos Trigger (disparo) de 10us
    delayMicroseconds(10);
    digitalWrite(rightTriggerPin, LOW);
    rightDuration = pulseIn(rightEchoPin, HIGH);  //medimos el tiempo entre pulsos, en microsegundos
    rightDistanceCm = rightDuration * 10 / 292 / 2;  //convertimos a distancia, en cm
    #if _DEBUG
    Serial.print("Distancia direita: ");
    Serial.print(rightDistanceCm);
    Serial.println(" cm");
    #endif
}
