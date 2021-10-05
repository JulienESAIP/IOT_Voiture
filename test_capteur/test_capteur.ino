/* 
Mesure de distance à l'aide d'un capteur HC-SR04 et d'un Arduino 
Domotique  et Objets Connectés  • Projets DIY<iframe class="wp-embedded-content" sandbox="allow-scripts" security="restricted" style="position: absolute; clip: rect(1px, 1px, 1px, 1px);" title="« Domotique  et Objets Connectés  • Projets DIY » &#8212; Domotique et objets connectés à faire soi-même" src="https://projetsdiy.fr/embed/#?secret=6jLnL3n3zj" data-secret="6jLnL3n3zj" width="600" height="338" frameborder="0" marginwidth="0" marginheight="0" scrolling="no"></iframe> 
Librairie: HCSR04 by Martin Sosic 
*/ 
#include <HCSR04.h> 
const int trigPin = 2; //Trig -> port 2
const int echoPin = 3; //Echo -> port 3
// Initialize sensor that uses digital pins trigPin and echoPin / initialisation du capteur avec les broches utilisees. 

UltraSonicDistanceSensor distanceSensor(trigPin, echoPin); 

void setup() { 
  // We initialize serial connection so that we could print values from sensor./ initialisation du port serie a 9600 band pour afficher les valeurs mesurees par le capteur. 

  Serial.begin(9600);
} 

void loop() { 
  // Every 500 miliseconds, do a measurement using the sensor and print the distance in centimeters./ toutes les 500 millisecondes nous faisons une mesure et nous affichons la distance en centimetre sur le port serie. 
  if (distanceSensor.measureDistanceCm() < 5) {
    Serial.println("Avancer"); 
  } else {
    Serial.println("Reculer");
  }
  delay(500); 
} 
