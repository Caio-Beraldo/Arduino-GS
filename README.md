# Arduino-GS

Sistema de Monitoramento com Arduino, Painel Solar e Sensores

Descrição do Projeto
Este projeto utiliza um Arduino Uno para monitorar o ambiente com o uso de um sensor PIR para detecção de movimentos. O sistema é alimentado por um painel solar, tornando-o uma solução sustentável e eficiente em termos de energia.
O objetivo deste projeto é criar um sistema de monitoramento autossustentável que pode ser utilizado em diversas aplicações, como segurança de ambientes externos. 

Funcionalidades
- Detecção de movimento utilizando o sensor PIR.
- Alimentação através de painel solar, garantindo operação contínua e sustentável.
- LDRs para intensidade de luminosidade


Esquema do Circuito
Componentes Necessários
- 1 x Arduino Uno
- 1 x Sensor PIR (infravermelho passivo)
- 1 x Painel Solar
- 1 x LED
- 3 x Resistors (220 ohms e 10k ohms)
- 1 x Protoboard
- Jumpers
- 1 x Servo
- 2 x LDR

Pré-requisitos
Software: Arduino IDE (versão mais recente)
Bibliotecas necessárias: Nenhuma biblioteca externa necessária para este projeto.

Montagem do Circuito
-Painel Solar: Conecte os terminais do painel solar ao pino VIN e GND do Arduino para alimentação.

-Sensor PIR:
VCC: 5V (Arduino)
GND: GND (Arduino)
Pino digital 2 (Arduino)

-Servo:
VCC: 5V (Arduino)
GND: GND (Arduino)
Pino digital 6 (Arduino)

-LDRs:
GND: GND(Arduino)
Pino analogico A0 e A1

-LEDs (opcional):
Conecte os LEDs com resistores em série aos pinos digitais conforme necessário para a sinalização visual.

Instruções para Execução
-Baixe e instale o Arduino IDE.

-Conecte o Arduino ao seu computador via cabo USB.

-Abra o Arduino IDE e cole o código abaixo em um novo arquivo.

-Selecione a placa Arduino Uno e a porta correta em "Ferramentas".

-Clique em Upload para enviar o código para o Arduino.

-Abra o Monitor Serial para visualizar as leituras dos sensores.

Testando o Projeto

-Aproxime-se do sensor PIR para verificar a detecção de movimento e para acender e apagar o LED.
Varie a luminosidade dos LDRs e o Servo irá mudar de direção para que a placa solar possa reter o máximo de energia solar.

Código

#include <Servo.h>

Servo myServo;
int LDR1 = A0;          
int LDR2 = A1;         
int painel = A2;       
int leituraPainel = 0; 
int leituraD = 0;      
int leituraE = 0;       
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
  leituraPainel = analogRead(painel);
  leituraD = analogRead(LDR2);
  leituraE = analogRead(LDR1);
 
  
  if (leituraD > (leituraE + margem)) {
    posicao = posicao +1;
    if (posicao > 180) 
    posicao = 180; 
    myServo.write(posicao);
    delay(150);
  } else if (leituraE > (leituraD + margem)) {
    posicao = posicao -1; 
    if (posicao < 0) 
    posicao = 0;
    myServo.write(posicao);
    delay(150);
  }
  
  
  if (leituraPainel < 400) {
    bool valorlido = digitalRead(pinPIR);
    if (valorlido == HIGH) {
      if (ledligado) {
        digitalWrite(led, LOW); 
      } else {
        digitalWrite(led, HIGH); 
      }
      ledligado = !ledligado; 
      delay(2000); 
    }
  
  
  
  } else {
    if (ledligado) {
      digitalWrite(led, LOW);
      ledligado = false; 
    }
  }
}


