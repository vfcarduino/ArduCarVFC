#define EN_A 13         // ativa motor direita
#define EN_B 12         // ativa motor esquerda

// motor A
#define IN_1  11
#define IN_2  10

// motor B
#define IN_3  8
#define IN_4  9

//int comando;            //Int to store app command state.
String comando;
//char comando;
int speedCar = 100;     // 50 - 255.
int speed_Coeff = 4;
//boolean lightFront = false;
//boolean horn = false;

// definição dos sinais usados para os motores (a direita pode ser diferente da esquerda)
// motores direita
#define M_DIREITA_ON   HIGH
#define M_DIREITA_OFF  LOW
// motores esquerda
#define M_ESQUERDA_ON  LOW
#define M_ESQUERDA_OFF HIGH

void motores_Setup() {
    pinMode(EN_A, OUTPUT);
    pinMode(EN_B, OUTPUT);
  
    pinMode(IN_1, OUTPUT);
    pinMode(IN_2, OUTPUT);
    pinMode(IN_3, OUTPUT);
    pinMode(IN_4, OUTPUT);
}

void roboParaFrente(){ 
      digitalWrite(IN_1, M_DIREITA_ON);
      digitalWrite(IN_2, M_DIREITA_OFF);
      analogWrite(EN_A, speedCar);

      digitalWrite(IN_3, M_ESQUERDA_ON);
      digitalWrite(IN_4, M_ESQUERDA_OFF);
      analogWrite(EN_B, speedCar);
}

void roboParaTras(){ 
      digitalWrite(IN_1, M_DIREITA_OFF);
      digitalWrite(IN_2, M_DIREITA_ON);
      analogWrite(EN_A, speedCar);

      digitalWrite(IN_3, M_ESQUERDA_OFF);
      digitalWrite(IN_4, M_ESQUERDA_ON);
      analogWrite(EN_B, speedCar);
}

void roboParaDireita(){ 
      digitalWrite(IN_1, M_DIREITA_OFF);
      digitalWrite(IN_2, M_DIREITA_ON);
      analogWrite(EN_A, speedCar);

      digitalWrite(IN_3, M_ESQUERDA_ON);
      digitalWrite(IN_4, M_ESQUERDA_OFF);
      analogWrite(EN_B, speedCar);
}

void roboParaEsquerda(){
      digitalWrite(IN_1, M_DIREITA_ON);
      digitalWrite(IN_2, M_DIREITA_OFF);
      analogWrite(EN_A, speedCar);


      digitalWrite(IN_3, M_ESQUERDA_OFF);
      digitalWrite(IN_4, M_ESQUERDA_ON);
      analogWrite(EN_B, speedCar);
}

void roboParaFrenteDireita(){
      digitalWrite(IN_1, M_DIREITA_ON);
      digitalWrite(IN_2, M_DIREITA_OFF);
      analogWrite(EN_A, speedCar/speed_Coeff);

      digitalWrite(IN_3, M_ESQUERDA_ON);
      digitalWrite(IN_4, M_ESQUERDA_OFF);
      analogWrite(EN_B, speedCar);
}

void roboParaFrenteEsquerda(){
      digitalWrite(IN_1, M_DIREITA_ON);
      digitalWrite(IN_2, M_DIREITA_OFF);
      analogWrite(EN_A, speedCar);

      digitalWrite(IN_3, M_ESQUERDA_ON);
      digitalWrite(IN_4, M_ESQUERDA_OFF);
      analogWrite(EN_B, speedCar/speed_Coeff);
 
}

void roboParaTrasDireita(){ 
      digitalWrite(IN_1, M_DIREITA_OFF);
      digitalWrite(IN_2, M_DIREITA_ON);
      analogWrite(EN_A, speedCar/speed_Coeff);


      digitalWrite(IN_3, M_ESQUERDA_OFF);
      digitalWrite(IN_4, M_ESQUERDA_ON);
      analogWrite(EN_B, speedCar);
}

void roboParaTrasEsquerda(){ 
      digitalWrite(IN_1, M_DIREITA_OFF);
      digitalWrite(IN_2, M_DIREITA_ON);
      analogWrite(EN_A, speedCar);

      digitalWrite(IN_3, M_ESQUERDA_OFF);
      digitalWrite(IN_4, M_ESQUERDA_ON);
      analogWrite(EN_B, speedCar/speed_Coeff);
}

void roboParar(){  
      digitalWrite(IN_1, LOW);
      digitalWrite(IN_2, LOW);
      analogWrite(EN_A, speedCar);

      digitalWrite(IN_4, LOW);
      digitalWrite(IN_3, LOW);
      analogWrite(EN_B, speedCar);
}


/*
    //if (Serial.available() > 0) {
        //comando = Serial.read();
        //comando = Serial.readString();

        //Serial.println( comando );

        //char copy[1];
        //comando.toCharArray(copy, 1);
        
        //Serial.println( copy );
        //trataCmd(copy);
    //}

void trataCmd(char cmd) {
    if (lightFront) {digitalWrite(light_FR, HIGH); digitalWrite(light_FL, HIGH);}
    if (!lightFront) {digitalWrite(light_FR, LOW); digitalWrite(light_FL, LOW);}
    if (horn) {digitalWrite(horn_Buzz, HIGH);}
    if (!horn) {digitalWrite(horn_Buzz, LOW);}
    switch (cmd) {
        case 'F':goAhead();break;
        case 'B':goBack();break;
        case 'L':goLeft();break;
        case 'R':goRight();break;
        case 'I':goAheadRight();break;
        case 'G':goAheadLeft();break;
        case 'J':goBackRight();break;
        case 'H':goBackLeft();break;
        case '0':speedCar = 100;break;
        case '1':speedCar = 120;break;
        case '2':speedCar = 135;break;
        case '3':speedCar = 155;break;
        case '4':speedCar = 170;break;
        case '5':speedCar = 185;break;
        case '6':speedCar = 195;break;
        case '7':speedCar = 215;break;
        case '8':speedCar = 235;break;
        case '9':speedCar = 255;break;
        case 'S':stopRobot();break;
        case 'W':lightFront = true;break;
        case 'w':lightFront = false;break;
        case 'V':horn = true;break;
        case 'v':horn = false;break;
    }
}
*/
