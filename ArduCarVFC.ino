#include "Config.h";
#include "Motores.h";
#include "SensorRadar.h";

void setup() {
    #if _DEBUG
    Serial.begin(115200);
    #endif
    motores_Setup();
    radar_Setup();

    speedCar = 255;
    roboParaFrente();
}

void loop(){
// /*
    // check distância frontal
    radarCheckDistFrente();
    if (frontDistanceCm < maxFrontDistance) {
        #if _DEBUG
        Serial.println("muito perto");
        #endif
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
        #if _DEBUG
        Serial.println("OK");
        #endif
        roboParaFrente();
    }

    // check distância esquerda
    radarCheckDistEsquerda();
    if (leftDistanceCm < maxLeftDistance) {
        #if _DEBUG
        Serial.println("esquerda muito perto");
        #endif
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
        #if _DEBUG
        Serial.println("direita muito perto");
        #endif
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
// */

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
// */
}
