#include <Servo.h>

//DECLARO O MEU SERVO
Servo base;
Servo angulo;
Servo altura;
Servo garra;

//MINHAS VARIAVEIS
//-->> VARIAVEIS DA BASE
int PinPotBase = A0;
int AngBase;
int PotBase;
int StartBase = 90;

//-->> VARIAVEIS DA ALTURA
int PinPotAltura = A1;
int AngAltura;
int PotAltura;
int StartAltura = 120;

//-->> VARIAVEIS DO ANGULO
int PinPotAngulo = A2;
int AngAngulo;
int PotAngulo;
int StartAngulo = 90;

//-->> VARIAVEIS DO GARRA
int PinPotGarra = A3;
int AngGarra;
int PotGarra;
int StartGarra = 110;

void setup() {
//INICIO O SERIAL
  Serial.begin(9600);
//DECLARO A PORTA DO MEU SERVO MOTOR 
  base.attach(8);
  altura.attach(9);
  angulo.attach(10);
  garra.attach(11);
}

void loop() {
//APRESENTO O ANGULO DO MOTOR NO MONITOR SERIAL
  Serial.print("| Base: ");
  Serial.print(StartBase);
  Serial.print(" | Altura: ");
  Serial.print(StartAltura);
  Serial.print(" | Angulo: ");
  Serial.print(StartAngulo);
  Serial.print(" | Garra: ");
  Serial.println(StartGarra);
//TRANSFORMAÇAO DOS DADOS DE 0, 1023 -> 0, 180
  PotBase = analogRead(PinPotBase);
  AngBase = map(PotBase, 0, 1023, 0, 180);

  PotAltura = analogRead(PinPotAltura);
  AngAltura = map(PotAltura, 0, 1023, 0, 180);

  PotAngulo = analogRead(PinPotAngulo);
  AngAngulo = map(PotAngulo, 0, 1023, 0, 180);

  PotGarra = analogRead(PinPotGarra);
  AngGarra = map(PotGarra, 0, 1023, 0, 180);
//------------//------------------

  while (AngBase == 0 || StartBase <= 0) {
    base.write(StartBase);
    delay(10);
    StartBase = StartBase + 1;
    AngBase = analogRead(PinPotBase);
  }

  while (AngBase == 176 || AngBase == 177 || AngBase == 178 || AngBase == 179 || AngBase == 180 || StartBase >=180 ) {
    base.write(StartBase);
    delay(10);
    StartBase = StartBase - 1;
    AngBase = analogRead(PinPotBase);
  }

//-----------//------------------

  while (AngAltura == 0 || StartAltura == 99) {
    altura.write(StartAltura);
    delay(10);
    StartAltura = StartAltura + 1;
    AngAltura = analogRead(PinPotAltura);
  }

  while (AngAltura == 176 || AngAltura == 177 || AngAltura == 178 || AngAltura == 179 || AngAltura == 180 && StartAltura >= 99 || StartAltura >= 155) {
    altura.write(StartAltura);
    delay(10);
    StartAltura = StartAltura - 1;
    AngAltura = analogRead(PinPotAltura);
  }

//-------------------//----------------------

  while (AngAngulo == 0 || StartAngulo == 85) {
    angulo.write(StartAngulo);
    delay(10);
    StartAngulo = StartAngulo + 1;
    AngAngulo = analogRead(PinPotAngulo);
  }

  while (AngAngulo == 176 || AngAngulo == 177 || AngAngulo == 178 || AngAngulo == 179 || AngAngulo == 180 && StartAngulo >= 85 || StartAngulo >= 180) {
    angulo.write(StartAngulo);
    delay(10);
    StartAngulo = StartAngulo - 1;
    AngAngulo = analogRead(PinPotAngulo);
  }

//--------------------//-------------------------

  while (AngGarra == 177 || AngGarra == 178 || AngGarra == 179 || AngGarra == 180 || StartGarra <= 109) {
    garra.write(StartGarra);
    delay(10);
    StartGarra = StartGarra + 2;
    AngGarra = analogRead(PinPotGarra);
  }

  while (AngGarra == 0 || AngGarra == 1 || AngGarra == 2 || AngGarra == 3 || StartGarra >= 141) {
    garra.write(StartGarra);
    delay(10);
    StartGarra = StartGarra - 2;
    AngGarra = analogRead(PinPotGarra);
  }
}
