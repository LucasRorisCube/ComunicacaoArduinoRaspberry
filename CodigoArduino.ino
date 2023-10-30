 #include "Wire.h"
 #define adress 0x08 // Endereco do dispositivo para comunicacao I2C

const int analogInPin = A0; // Pino do Potenciometro

int sensorValue = 0;        // Valor lido do potenciometro

void setup() {
  Serial.begin(9600);
  Wire.begin(adress);
  pinMode(13, OUTPUT); // Seta o LED Blink como Output
  Wire.onRequest(requestEvent); // Quando receber uma solicitacao, executa a funcao requestEvent
  Wire.onReceive(receiveEvents);// Quando receber dados, executa a funcao receiveEvents
  
}

void receiveEvents(int howMany) {
  while (Wire.available()) { // Le todos os dados do buffer
    int c = Wire.read();
    if(c == 0){ // Caso for 1, liga o LED, caso foi 0, desliga
      digitalWrite(13, LOW);
    } else if(c == 1){
      digitalWrite(13, HIGH);
    }
  }
}

void requestEvent(){
  sensorValue = analogRead(analogInPin); // Le o valor do potenciometro
  short outputValue = map(sensorValue, 0, 1023, 0, 255); // Mapeia para um short
  Wire.write(outputValue); // Envia para a Raspberry
}

void loop() {
	
}