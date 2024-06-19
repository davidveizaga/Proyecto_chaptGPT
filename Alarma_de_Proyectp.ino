// Definición de pines
const int trigPin = 8;
const int echoPin = 9;
const int buzzerPin = 7;

// Variables para medición de distancia
int distancia;
int tiempo;
void setup()
{

  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
  pinMode(buzzerPin, OUTPUT);
  Serial.begin(9600);
}

void loop() 
{
  // Generar un pulso corto en el pin Trig para iniciar la medición
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(1);
  digitalWrite(trigPin, LOW);

  // Medir la duración del pulso Echo
  tiempo = pulseIn(echoPin, HIGH);
  // Calcular la distancia en centímetros
  distancia = tiempo /52.8;
  // Mostrar la distancia medida en el Monitor Serie (opcional)
  Serial.print("Distancia: ");
  Serial.println(distance);
  // Activar el buzzer si la distancia medida es menor que el umbral
  if (distancia <= 60) {
    digitalWrite(buzzerPin, HIGH);
    digitalWrite(buzzerPin, LOW);
  
  }
}
