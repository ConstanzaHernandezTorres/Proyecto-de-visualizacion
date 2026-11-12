/**
 * ============================================================================
 * SENSOR FÍSICO DE VOLCANES (OPCIÓN A - DIVISOR DE VOLTAJE CON 2 CABLES)
 * InfoVis IIC2026 PUC - Entrega 2
 * ============================================================================
 *
 * CONEXIÓN FÍSICA ("EL TRUCO"):
 * 1. Cable 1: Pin 5V del Arduino  ---> Cuadrado de aluminio 1 en la base.
 * 2. Cable 2: Pin A0 del Arduino  ---> Cuadrado de aluminio 2 en la base.
 * 3. Resistencia 10k Ω en "U":    ---> Una pata en A0 (junto al Cable 2) y
 *                                      la otra pata en GND.
 * 4. Volcán de cartón:            ---> Tiene una resistencia (o aluminio)
 *                                      pegada en su base que une ambos
 *                                      cuadrados al apoyarlo.
 * 5. Feedback visual (0 cables):  ---> Usa LED_BUILTIN (pin 13 integrado).
 */

const int PIN_SENSOR = A0;
const int PIN_LED = LED_BUILTIN; // LED interno del Arduino (junto al pin 13)

// Umbral para distinguir entre "base vacía" (~0) y el volcán de 220kΩ (~45)
const int UMBRAL_VOLCAN = 25;

void setup() {
  Serial.begin(9600);
  pinMode(PIN_LED, OUTPUT);
  digitalWrite(PIN_LED, LOW);
}

void loop() {
  // Promediar 16 lecturas rápidas para filtrar ruido eléctrico del aluminio
  long suma = 0;
  for (int i = 0; i < 16; i++) {
    suma += analogRead(PIN_SENSOR);
    delay(2);
  }
  int lectura = suma / 16;

  // Feedback visual inmediato en la placa Arduino (LED pin 13)
  if (lectura >= UMBRAL_VOLCAN) {
    digitalWrite(PIN_LED, HIGH); // Enciende LED cuando detecta el volcán
  } else {
    digitalWrite(PIN_LED, LOW);  // Apaga LED cuando se retira el volcán
  }

  // Enviar el valor (0 a 1023) por USB al navegador web
  Serial.println(lectura);

  delay(80); // ~10 lecturas por segundo
}
