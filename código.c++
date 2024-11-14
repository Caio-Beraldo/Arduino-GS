#include <Servo.h>

Servo myServo;
int LDR1 = A0;          
int LDR2 = A1;         
int solar = A2;       
int leituraSolar = 0; 
int Direita = 0;      
int Esquerda = 0;       
int posicao = 90;       
int margem = 10;        
#define led 12          
bool ledligado = false; 
#define pinPIR 2         



void setup() {
Serial.begin(9600);    
myServo.attach(6);    
myServo.write(posicao); 
pinMode(led, OUTPUT);  
pinMode(pinPIR, INPUT); 
}

void loop() {
leituraSolar = analogRead(solar);
Direita = analogRead(LDR2);
Esquerda = analogRead(LDR1);

  
if (Direita > (Esquerda + margem)) {
  posicao = posicao +1;
  if (posicao > 180) 
  posicao = 180; 
  myServo.write(posicao);
  delay(150);
 }else if (Esquerda > (Direita + margem)) {
  posicao = posicao -1; 
  if (posicao < 0) 
  posicao = 0;
  myServo.write(posicao);
  delay(150);
  }
if(leituraSolar < 400) {
  bool valorlido = digitalRead(pinPIR);
  if (valorlido == HIGH) {
    if (ledligado) {
      digitalWrite(led, LOW); 
    }else {
      digitalWrite(led, HIGH); 
    }
    ledligado = !ledligado; 
    delay(2000); 
  }
 }else {
if (ledligado) {
    digitalWrite(led, LOW);
    ledligado = false; 
    }
  }
}
