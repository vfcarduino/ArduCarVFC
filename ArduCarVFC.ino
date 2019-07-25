#include "Motores.h";
#include "SensorRadar.h";

void setup() {
    Serial.begin(115200); 
    motores_Setup();
    radar_Setup();

    speedCar = 255;
    roboParaFrente();
}

void loop(){
    // check distância frontal
    radarCheckDistFrente();
    if (frontDistanceCm < maxFrontDistance) {
        Serial.println("muito perto");
        radarCheckDistEsquerda();
        delay(20);
        radarCheckDistDireita();
        delay(20);
        if (leftDistanceCm < rightDistanceCm)
            roboParaDireita();
        else if (leftDistanceCm > rightDistanceCm) {
            roboParaEsquerda();
        }
    } else {
        Serial.println("OK");
        roboParaFrente();
    }
  
    // check distância esquerda
    radarCheckDistEsquerda();
    if (leftDistanceCm < maxLeftDistance) {
        Serial.println("esquerda muito perto");
        delay(20);
        radarCheckDistEsquerda();
        delay(20);
        radarCheckDistDireita();
        delay(20);
        if (leftDistanceCm > rightDistanceCm)
          roboParaFrente();
        else if (leftDistanceCm < rightDistanceCm) {
            roboParaDireita();
        }
    }
  
    // check distância direita
    radarCheckDistDireita();
    if (rightDistanceCm < maxRightDistance) {
        Serial.println("direita muito perto");
        delay(20);
        radarCheckDistDireita();
        delay(20);
        radarCheckDistEsquerda();
        delay(20);
        if (rightDistanceCm > leftDistanceCm)
            roboParaFrente();
        else if (rightDistanceCm < leftDistanceCm) {
            roboParaEsquerda();
        }
    }


/*
    radarCheckDistFrente();
    if (frontDistanceCm < maxFrontDistance) {
        Serial.print("Distance: ");
        Serial.print(frontDistanceCm);
        Serial.println(" cm");
        Serial.println("Muito perto");
        roboParaEsquerda();
    } else {
        roboParaFrente();
    }
*/
}
