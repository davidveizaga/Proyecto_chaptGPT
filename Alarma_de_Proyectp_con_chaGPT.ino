// Definición de pines
const int trigPin = 9;
const int echoPin = 10;
const int buzzerPin = 8;

// Variables para medición de distancia
long duration;
int distance;

// Umbral de distancia para activar la alarma (en centímetros)
int thresholdDistance = 20;

void setup() {
  Serial.begin(9600);
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
  pinMode(buzzerPin, OUTPUT);
}

void loop() {
  // Generar un pulso corto en el pin Trig para iniciar la medición
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);

  // Medir la duración del pulso Echo
  duration = pulseIn(echoPin, HIGH);

  // Calcular la distancia en centímetros
  distance = duration * 0.034 / 2;

  // Mostrar la distancia medida en el Monitor Serie (opcional)
  Serial.print("Distance: ");
  Serial.println(distance);

  // Activar el buzzer si la distancia medida es menor que el umbral
  if (distance < thresholdDistance) {
    digitalWrite(buzzerPin, HIGH);
    delay(200); // Duración del sonido de la alarma
    digitalWrite(buzzerPin, LOW);
    delay(200); // Tiempo de espera antes de la siguiente medición
  }
}
