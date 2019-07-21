/*
#define light_FR  14    //LED Front Right   pin A0 for Arduino Uno
#define light_FL  15    //LED Front Left    pin A1 for Arduino Uno
#define horn_Buzz 18    //Horn Buzzer       pin A4 for Arduino Uno
*/

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
boolean lightFront = false;
boolean horn = false;

void setup() {  
/*
    pinMode(light_FR, OUTPUT);
    pinMode(light_FL, OUTPUT);
    pinMode(horn_Buzz, OUTPUT);
*/
    
    pinMode(EN_A, OUTPUT);
    pinMode(EN_B, OUTPUT);
  
    pinMode(IN_1, OUTPUT);
    pinMode(IN_2, OUTPUT);
    pinMode(IN_3, OUTPUT);
    pinMode(IN_4, OUTPUT);

    Serial.begin(115200); 
} 

void goAhead(){ 
      digitalWrite(IN_1, HIGH);
      digitalWrite(IN_2, LOW);
      analogWrite(EN_A, speedCar);

      digitalWrite(IN_4, HIGH); //LOW
      digitalWrite(IN_3, LOW);  //HIGH
      analogWrite(EN_B, speedCar);
}

void goBack(){ 
      digitalWrite(IN_1, LOW);
      digitalWrite(IN_2, HIGH);
      analogWrite(EN_A, speedCar);

      digitalWrite(IN_4, LOW);  //HIGH
      digitalWrite(IN_3, HIGH); //LOW
      analogWrite(EN_B, speedCar);
}

void goRight(){ 
      digitalWrite(IN_1, LOW);
      digitalWrite(IN_2, HIGH);
      analogWrite(EN_A, speedCar);

      digitalWrite(IN_4, HIGH); //LOW
      digitalWrite(IN_3, LOW);  //HIGH
      analogWrite(EN_B, speedCar);
}

void goLeft(){
      digitalWrite(IN_1, HIGH);
      digitalWrite(IN_2, LOW);
      analogWrite(EN_A, speedCar);


      digitalWrite(IN_4, LOW);  //HIGH
      digitalWrite(IN_3, HIGH); //LOW
      analogWrite(EN_B, speedCar);
}

void goAheadRight(){
      digitalWrite(IN_1, HIGH);
      digitalWrite(IN_2, LOW);
      analogWrite(EN_A, speedCar/speed_Coeff);

      digitalWrite(IN_4, HIGH); //LOW
      digitalWrite(IN_3, LOW);  //HIGH
      analogWrite(EN_B, speedCar);
}

void goAheadLeft(){
      digitalWrite(IN_1, HIGH);
      digitalWrite(IN_2, LOW);
      analogWrite(EN_A, speedCar);

      digitalWrite(IN_4, HIGH); //LOW
      digitalWrite(IN_3, LOW);  //HIGH
      analogWrite(EN_B, speedCar/speed_Coeff);
 
}

void goBackRight(){ 
      digitalWrite(IN_1, LOW);
      digitalWrite(IN_2, HIGH);
      analogWrite(EN_A, speedCar/speed_Coeff);


      digitalWrite(IN_4, LOW);  //HIGH
      digitalWrite(IN_3, HIGH); //LOW
      analogWrite(EN_B, speedCar);
}

void goBackLeft(){ 
      digitalWrite(IN_1, LOW);
      digitalWrite(IN_2, HIGH);
      analogWrite(EN_A, speedCar);

      digitalWrite(IN_4, LOW);  //HIGH
      digitalWrite(IN_3, HIGH); //LOW
      analogWrite(EN_B, speedCar/speed_Coeff);
}

void stopRobot(){  
      digitalWrite(IN_1, LOW);
      digitalWrite(IN_2, LOW);
      analogWrite(EN_A, speedCar);

      digitalWrite(IN_4, LOW);
      digitalWrite(IN_3, LOW);
      analogWrite(EN_B, speedCar);
}

void trataCmd(char cmd) {
/*
    if (lightFront) {digitalWrite(light_FR, HIGH); digitalWrite(light_FL, HIGH);}
    if (!lightFront) {digitalWrite(light_FR, LOW); digitalWrite(light_FL, LOW);}
    if (horn) {digitalWrite(horn_Buzz, HIGH);}
    if (!horn) {digitalWrite(horn_Buzz, LOW);}
*/
        
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

void loop(){
    //if (speedCar == 255) {
    //  speedCar = 100;
    //} else {
    //  speedCar = 255;
    //}
    speedCar = 255;
  
    goAhead();
    delay(5000);
    
    goBack();
    delay(5000);

    //goAheadRight();
    //delay(1000);
    
    //goAheadLeft();
    //delay(1000);

    goRight();
    delay(1000);

    goLeft();
    delay(1000);

    goBackRight();
    delay(1000);

    goBackLeft();
    delay(1000);

    stopRobot();
    delay(1000);



    //if (Serial.available() > 0) {
        //comando = Serial.read();
        //comando = Serial.readString();

        //Serial.println( comando );

        //char copy[1];
        //comando.toCharArray(copy, 1);
        
        //Serial.println( copy );
        //trataCmd(copy);
    //}
}
