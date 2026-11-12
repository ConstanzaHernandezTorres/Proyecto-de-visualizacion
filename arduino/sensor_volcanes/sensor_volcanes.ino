/**
 * ============================================================================
 * SENSOR FÍSICO DE VOLCANES (DIVISOR DE VOLTAJE CON ARDUINO LEONARDO)
 * InfoVis IIC2026 PUC - Entrega 2
 * ============================================================================
 *
 * CONEXIÓN FÍSICA:
 * 1. Cable 1: Pin 5V del Arduino  ---> Aluminio 1 en la base.
 * 2. Cable 2: Pin A0 del Arduino  ---> Aluminio 2 en la base.
 * 3. Resistencia 10kΩ en "U":     ---> Entre A0 y GND en el Arduino.
 * 4. Pirámides de volcanes:       ---> Tienen su resistencia en la base que une
 *                                      ambos aluminios al apoyarlas:
 *                                      - Cerro Hudson (220Ω) -> A0 ≈ 1001
 *                                      - Pululahua (1kΩ)     -> A0 ≈ 931
 *                                      - Villarrica (10kΩ)   -> A0 ≈ 512
 *                                      - Licto (33kΩ)        -> A0 ≈ 235
 * 5. Feedback visual:             ---> Usa LED_BUILTIN (pin 13 integrado).
 */

const int PIN_SENSOR = A0;
const int PIN_LED = LED_BUILTIN; // LED interno del Arduino (junto al pin 13)

// Umbral para distinguir entre "base vacía" (~0) y cualquier volcán (>= 40)
const int UMBRAL_VOLCAN = 40;

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
