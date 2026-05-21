#include <Servo.h>

// --- DEFINIÇÃO DOS PINOS ---
// Sensor da Mão (Abre a tampa)
#define TRIG_MAO 7
#define ECHO_MAO 6

// Sensor do Lixo (Nível interno)
#define TRIG_LIXO 2
#define ECHO_LIXO 3

// LEDs Indicadores
#define LED_VERDE 13
#define LED_AMARELO 12
#define LED_VERMELHO 11

// Servo Motor
#define PINO_SERVO 9

// --- VARIÁVEIS GERAIS ---
Servo servoTampa;
int distanciaMao = 0;
int distanciaLixo = 0;

// Função padrão para ler o sensor ultrassônico
long readUltrasonicDistance(int triggerPin, int echoPin) {
  pinMode(triggerPin, OUTPUT);
  digitalWrite(triggerPin, LOW);
  delayMicroseconds(2);
  
  digitalWrite(triggerPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(triggerPin, LOW);
  
  pinMode(echoPin, INPUT);
  return pulseIn(echoPin, HIGH);
}

void setup() {
  // Configurando os pinos dos LEDs como SAÍDA de energia
  pinMode(LED_VERDE, OUTPUT);
  pinMode(LED_AMARELO, OUTPUT);
  pinMode(LED_VERMELHO, OUTPUT);
  
  // Conectando o servo e garantindo que comece fechado (0 graus)
  servoTampa.attach(PINO_SERVO, 500, 2500);
  servoTampa.write(0);
  
  // Inicia o monitor serial (bom para testarmos no Tinkercad)
  Serial.begin(9600);
}

void loop() {
  // 1. LÊ AS DUAS DISTÂNCIAS
  distanciaMao = 0.01723 * readUltrasonicDistance(TRIG_MAO, ECHO_MAO);
  distanciaLixo = 0.01723 * readUltrasonicDistance(TRIG_LIXO, ECHO_LIXO);

  // Print no console para você debugar/acompanhar os valores
  Serial.print("Mao: ");
  Serial.print(distanciaMao);
  Serial.print(" cm | Lixo: ");
  Serial.print(distanciaLixo);
  Serial.println(" cm");


  // 2. LÓGICA DA TAMPA (SEU CÓDIGO)
  if (distanciaMao <= 50) {
    servoTampa.write(90); // Abre a tampa
    delay(5000);          // Espera 5 segundos
    servoTampa.write(0);  // Fecha a tampa
  }


  // 3. LÓGICA DO NÍVEL DE LIXO (LEDS)
  // Atenção: Ajuste esses valores (25 e 10) dependendo da profundidade da sua lixeira virtual!
  
  if (distanciaLixo > 25) {
    // Lixeira Vazia (Lixo está longe do sensor)
    digitalWrite(LED_VERDE, HIGH);
    digitalWrite(LED_AMARELO, LOW);
    digitalWrite(LED_VERMELHO, LOW);
    
  } else if (distanciaLixo > 10 && distanciaLixo <= 25) {
    // Lixeira pela Metade
    digitalWrite(LED_VERDE, LOW);
    digitalWrite(LED_AMARELO, HIGH);
    digitalWrite(LED_VERMELHO, LOW);
    
  } else {
    // Lixeira Cheia (Lixo está muito perto do sensor, menor ou igual a 10cm)
    digitalWrite(LED_VERDE, LOW);
    digitalWrite(LED_AMARELO, LOW);
    digitalWrite(LED_VERMELHO, HIGH);
  }

  delay(100); // Pequena pausa para não travar o simulador
}