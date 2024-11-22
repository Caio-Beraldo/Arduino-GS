# Arduino-GS
Caio Costa Beraldo - RM560775
Victor Kenzo Mikado- RM560057


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

Pré-requisitos:

Software: Arduino IDE (versão mais recente)

Bibliotecas necessárias: Nenhuma biblioteca externa necessária para este projeto.

Montagem do Circuito:

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


Testando o Projeto

-Aproxime-se do sensor PIR para verificar a detecção de movimento e para acender e apagar o LED(Esse sistema só funcionará a noite).
Varie a luminosidade dos LDRs e o Servo irá mudar de direção para que a placa solar possa reter o máximo de energia solar.



