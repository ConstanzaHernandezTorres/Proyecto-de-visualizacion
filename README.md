# ¿Dónde se encuentran las mayores amenazas volcánicas en Sudamérica?
### Visualización Física, Interactiva y Sonora de Riesgo Geológico y Demográfico en la Cordillera de los Andes

**IIC2026 Visualización de Información · Pontificia Universidad Católica de Chile**  
**Proyecto de Visualización de Información — Entrega 2 · Grupo 19**

| Información | Detalle |
| :--- | :--- |
| **Grupo:** | Grupo 19 |
| **Integrantes:** | Javiera Bascur (`javiera.bascur@uc.cl`), Constanza Hernández (`constanza.h.torres@uc.cl`) |
| **GitHub Pages:** | [https://constanzahernandeztorres.github.io/Proyecto-de-visualizacion/](https://constanzahernandeztorres.github.io/Proyecto-de-visualizacion/) |
| **Repositorio GitHub:** | [https://github.com/ConstanzaHernandezTorres/Proyecto-de-visualizacion.git](https://github.com/ConstanzaHernandezTorres/Proyecto-de-visualizacion.git) |
| **Video demostrativo:** | [https://youtu.be/lgD8wK_w_tY](https://youtu.be/lgD8wK_w_tY?si=kFQdfTKG8JCcTB9F) |

---

## Contenido

1. [Qué queremos comunicar](#qué-queremos-comunicar)
2. [La paradoja territorial andina](#la-paradoja-territorial-andina)
3. [Fisicalización e interacción tangible con Arduino](#fisicalización-e-interacción-tangible-con-arduino)
4. [Funcionalidades de la visualización](#funcionalidades-de-la-visualización)
5. [Cómo usar la visualización (Digital y Física)](#cómo-usar-la-visualización-digital-y-física)
6. [Codificación visual, física y sonificación](#codificación-visual-física-y-sonificación)
7. [Origen y procesamiento de los datos](#origen-y-procesamiento-de-los-datos)
8. [Arquitectura y tecnologías](#arquitectura-y-tecnologías)
9. [Estructura del repositorio](#estructura-del-repositorio)
10. [Instalación y ejecución local](#instalación-y-ejecución-local)
11. [Proceso de diseño e iteraciones](#proceso-de-diseño-e-iteraciones)
12. [Feedback entre pares y evaluación con usuarios](#feedback-entre-pares-y-evaluación-con-usuarios)
13. [Créditos y equipo](#créditos-y-equipo)

---

## Qué queremos comunicar

La visualización responde a una pregunta concreta y urgente: **¿Dónde se encuentran las mayores amenazas volcánicas en Sudamérica?**

A lo largo de la Cordillera de los Andes convergen procesos geológicos de escala planetaria con asentamientos humanos históricos. Sin embargo, el concepto de "amenaza volcánica" suele comunicarse de forma homogénea o simplista, limitándose a reportar la magnitud de las erupciones o la mera presencia de volcanes activos.

Al cruzar el registro geológico histórico con la demografía satelital global de alta resolución, nuestro proyecto demuestra que el riesgo **no se distribuye de manera uniforme**: existe una marcada **asimetría territorial** entre el norte y el sur de la cordillera.

En su estado actual (**Entrega 2**), el proyecto traslada esta paradoja desde la pantalla hacia el **plano tangible** mediante **cuatro modelos físicos de volcanes modelados en arcilla** conectados a una base sensora con **Arduino Leonardo**. Manipular físicamente el volumen, peso y color de cada volcán mientras se observa la respuesta cartográfica y se escucha la sonificación multicanal permite contrastar de forma inmediata la diferencia entre la **violencia geológica extrema en zonas despobladas** y la **vulnerabilidad humana masiva**.

---

## La paradoja territorial andina

La visualización digital y física evidencia directamente una paradoja geográfica y de protección civil:

```text
                  ┌─────────────────────────────────────────────────────────┐
                  │      ¿DÓNDE RADICA LA AMENAZA EN LOS ANDES?             │
                  └────────────────────────────┬────────────────────────────┘
                                               │
               ┌───────────────────────────────┴───────────────────────────────┐
               ▼                                                               ▼
   NORTE (Ecuador y Colombia)                                      SUR (Chile y Argentina)
   • Riesgo humano masivo e inmediato                              • Violencia geológica extrema
   • Cientos de miles en radio letal (10 km)                       • Super-erupciones VEI 5 y 6
   • Pululahua: 534k hab. | Licto: 250k hab.                       • Hudson (VEI 6), Villarrica (VEI 5)
   • Vulnerabilidad humanitaria crítica                            • Baja población a 10 km (<1.500 hab.)
   • Círculos y piezas de color rojo oscuro                        • Círculos y piezas de gran tamaño y tono claro
```

1. **Foco Norte (Ecuador y Colombia) — Vulnerabilidad Humana Extrema:**
   * El peligro crítico reside en la exposición demográfica directa en la zona de evacuación inmediata (radio de 10 km).
   * Cientos de miles de habitantes residen en el radio letal de flujos piroclásticos y lahares.
   * **Casos emblemáticos:**
     * **Pululahua (Ecuador):** 534.403 habitantes viviendo a menos de 10 km del complejo volcánico (VEI 5).
     * **Licto (Ecuador):** 250.144 habitantes en el radio de 10 km pese a un índice explosivo histórico bajo (VEI 0).
     * **Galeras (Colombia):** 121.282 habitantes expuestos en radio inmediato (VEI 4).
   * En este sector, la alta densidad demográfica convierte la actividad volcánica en una emergencia humanitaria crítica.

2. **Foco Sur (Chile y Argentina) — Violencia Geológica Extrema:**
   * La amenaza radica en la violencia telúrica de super-erupciones históricas registradas con Índices de Explosividad Volcánica de **VEI 5 y VEI 6**.
   * La población directa dentro de los primeros 10 km es baja (< 1.500 habitantes), pero la magnitud explosiva produce columnas eruptivas de más de 20 km de altura, lluvia de cenizas transcontinental y lahares destructivos a escala regional (30 a 100 km).
   * **Casos emblemáticos:**
     * **Cerro Hudson (Chile):** VEI 6 histórico; población a 10 km casi nula (12 hab.), pero impacto destructivo severo en la Patagonia.
     * **Villarrica (Chile):** Eventos históricos VEI 5 con 1.067 habitantes en el radio inmediato de 10 km y alta exposición turística y regional.

---

## Fisicalización e interacción tangible con Arduino

Para hacer tangible la asimetría del riesgo andino sin abrumar la memoria de trabajo del espectador con 39 piezas sueltas, se seleccionaron **4 volcanes arquetípicos** que representan los contrastes extremos del conjunto de datos.

Cada volcán fue modelado tridimensionalmente en **arcilla** —cuyo peso asegura por gravedad un contacto eléctrico estable— respetando la misma codificación visual del mapa digital (**color térmico según población a 10 km** y **tamaño según explosividad VEI**), e incorpora una resistencia eléctrica distinta en su base:

| Volcán Físico | País | Población (10 km) | Explosividad | Resistencia | Lectura Analógica (`A0`) | Perfil de Amenaza y Apariencia Física |
| :--- | :--- | :--- | :--- | :--- | :--- | :--- |
| **Pululahua** | Ecuador | 534.403 hab. | VEI 5 | `220 Ω` | `~1001` (rango `966–1023`) | **Riesgo Crítico Total:** Pieza grande y de color rojo más oscuro/intenso. |
| **Villarrica** | Chile | 1.067 hab. | VEI 5 | `1 kΩ` | `~931` (rango `721–965`) | **Alta Explosividad / Población Moderada:** Pieza grande de tono anaranjado intermedio. |
| **Licto** | Ecuador | 250.144 hab. | VEI 0 | `10 kΩ` | `~512` (rango `370–720`) | **Alta Densidad Urbana / Baja Explosividad:** Pieza pequeña de color rojo intenso. |
| **Cerro Hudson** | Chile | 12 hab. | VEI 6 | `33 kΩ` | `~235` (rango `40–369`) | **Violencia Geológica Extrema Despoblada:** Pieza de gran tamaño y color claro/blanco. |

### Circuito divisor de voltaje y comunicación Web Serial

* **Base sensora con estructura de encaje:** La base física cuenta con una estructura guía que delimita dónde posicionar cada volcán. En su interior dispone de dos contactos de aluminio: uno conectado a `5V` y otro conectado al pin analógico `A0` del **Arduino Leonardo** (con una resistencia fija pull-down de `10 kΩ` entre `A0` y `GND`).
* **Procesamiento en Arduino ([`sensor_volcanes.ino`](arduino/sensor_volcanes/sensor_volcanes.ino)):** El microcontrolador promedia 16 muestras rápidas por lectura para filtrar ruido eléctrico, enciende el LED integrado (`LED_BUILTIN`, pin 13) al detectar un volcán (`A0 ≥ 40`) y transmite el valor analógico (`0–1023`) por USB a `9600 baudios`.
* **Acoplamiento físico-digital (`Web Serial API`):** El navegador recibe el flujo serial en tiempo real, aplica un filtro de mediana sobre las últimas 5 lecturas y un temporizador de asentamiento (`200 ms`). Al identificar el volcán apoyado, realiza automáticamente el zoom hacia su cráter en el mapa, emite ondas expansivas, actualiza la ficha técnica y reproduce la sonificación correspondiente. Al levantar el volcán de la base (`A0 < 40` durante `300 ms`), el audio se detiene y el mapa regresa suavemente a la vista general de Sudamérica.

---

## Funcionalidades de la visualización

* **Cartografía continental focalizada:**  
  Mapa interactivo vectorial en SVG (D3.js y TopoJSON) delimitado exclusivamente a Sudamérica, con proyección Mercator ajustada al contenedor, paleta oscura sobria por país, fronteras nítidas y rótulos cartográficos integrados.
* **Algoritmo anti-solapamiento (*Zero-Overlap*):**  
  En zonas de alta concentración de cráteres (Ecuador, Colombia y centro-sur de Chile), un algoritmo de separación bilateral y optimización *2-opt* proyecta los círculos hacia el exterior sin cruces de líneas, conectándolos con líneas de guía punteadas (*leader lines*) y micro-anclas en la coordenada exacta del cráter (**Cápsulas 07 y 16**).
* **Codificación visual bivariada alineada con la fisicalización:**  
  * **Color (Población a 10 km):** Escala secuencial térmica logarítmica accesible para daltonismo (`YlOrRd`, de amarillo claro a rojo oscuro profundo, **Cápsula 10**) que representa la cantidad de habitantes dentro del radio de evacuación inmediata de 10 km (`0` a `500k+ hab.`).
  * **Tamaño (Explosividad VEI):** El tamaño de cada círculo codifica el Índice de Explosividad Volcánica histórico (`VEI 0` a `VEI 7`), permitiendo distinguir la magnitud geológica en coherencia con el volumen de las piezas físicas.
* **Sonificación multicanal ortogonal con Tone.js:**  
  El sonido codifica dos dimensiones independientes sin depender del volumen (**Cápsula 23**):
  1. *Canal Telúrico (Sintetizador subgrave `MonoSynth`):* Emite una nota grave profunda (de `D2` a `C1`) cuya frecuencia fundamental desciende y cuya duración aumenta (`0.7 s` a `2.25 s`) según el VEI histórico.
  2. *Canal Humanitario (Sintetizador percusivo `MembraneSynth`):* Emite una secuencia de latidos cuyo tempo en BPM (`48` a `165 BPM`, escala logarítmica) es proporcional a la población expuesta en el radio de 10 km.
* **Ondas sísmicas concéntricas y zoom cinemático:**  
  Al seleccionar un volcán (por clic o al apoyarlo en la base Arduino), la cámara realiza una transición suave (`scale(3)`) hacia el cráter e irradia tres ondas concéntricas animadas sincronizadas con el impacto sonoro.
* **Panel guía de interpretación ciudadana y ficha de inspección (*Inspector Card*):**  
  Recuadro superior que destaca la regla de protección civil (*«En VEI ≥ 4 el radio de 10 km es indefendible: exige alerta roja y evacuación total inmediata»*) y tarjeta lateral con insignia dinámica (`🚨 RIESGO CRÍTICO`, `💥 ALTA EXPLOSIVIDAD` o `🟡 DENSIDAD URBANA`), nombre, país, VEI y población a 10 km.

---

## Cómo usar la visualización (Digital y Física)

1. **Exploración general (*Overview*):**  
   Al abrir la aplicación se presentan los 39 volcanes de mayor amenaza en Sudamérica. Observe cómo los tonos rojos más oscuros (mayor población en riesgo a 10 km) se concentran en el norte andino, mientras que en el sur predominan círculos grandes de tonos claros (alta explosividad VEI con baja densidad poblacional inmediata).
2. **Interacción física con Arduino Leonardo:**  
   * Conecte la placa Arduino Leonardo por USB al computador.
   * En la barra superior derecha (en Google Chrome o Microsoft Edge), haga clic en el botón **"Conectar Arduino"** y seleccione el puerto COM correspondiente.
   * Apoye cualquiera de los **4 volcanes de arcilla** (*Pululahua*, *Villarrica*, *Licto* o *Cerro Hudson*) sobre la estructura de encaje de la base sensora para activar el acercamiento en el mapa, la ficha técnica y la sonificación.
   * Retire el volcán de la base para detener el sonido y regresar automáticamente al mapa general de Sudamérica.
3. **Modo de simulación por teclado (sin hardware conectado):**  
   Puede simular la colocación y retiro de los 4 volcanes físicos directamente con el teclado:
   * Tecla `1`: Simula colocar **Pululahua** (`220 Ω`, `A0 = 1001`).
   * Tecla `2`: Simula colocar **Villarrica** (`1 kΩ`, `A0 = 931`).
   * Tecla `3`: Simula colocar **Licto** (`10 kΩ`, `A0 = 512`).
   * Tecla `4`: Simula colocar **Cerro Hudson** (`33 kΩ`, `A0 = 235`).
   * Tecla `0` o `Escape`: Simula retirar el volcán de la base (`A0 = 0`).
4. **Interacción digital con ratón / trackpad:**  
   * **Inicializar audio:** Haga clic en cualquier parte del escenario para habilitar el contexto de Web Audio API.
   * **Hover y clic:** Pase el cursor sobre cualquier volcán para ver su tooltip o haga clic sobre él para centrar la cámara y escuchar su sonificación.
   * **Zoom y paneo:** Utilice la rueda del ratón, arrastre el mapa o use los botones `+`, `−` y `⟲` en la esquina superior izquierda.

---

## Codificación visual, física y sonificación

| Variable de Datos | Tipo de Variable | Canal Digital / Físico / Sonoro | Justificación de Diseño y Principio |
| :--- | :--- | :--- | :--- |
| **Población en 10 km** | Cuantitativa continua | **Color secuencial térmico (`YlOrRd`) en mapa y arcilla** | Los tonos cálidos más oscuros y saturados se asocian preatentivamente con mayor peligro humanitario; escala logarítmica accesible para daltonismo (**Cápsula 10**). |
| **Población en 10 km** | Cuantitativa continua | **Tempo del pulso cardíaco (`48–165 BPM`)** | Metáfora intuitiva de urgencia vital; mayor población expuesta acelera el ritmo cardíaco (**Cápsula 23**). |
| **Explosividad (VEI)** | Cuantitativa discreta / ordinal | **Tamaño del círculo (SVG) y volumen del volcán físico** | A mayor VEI (`0` a `7`), mayor tamaño de la marca digital y del edificio volcánico modelado en arcilla. |
| **Explosividad (VEI)** | Cuantitativa discreta / ordinal | **Tono fundamental subgrave (`D2` a `C1`) y duración** | Frecuencias más bajas y prolongadas transmiten la magnitud física y sísmica de la erupción (**Cápsula 23**). |
| **Identidad del volcán físico** | Categórica nominal | **Resistencia eléctrica en divisor de voltaje (`220 Ω` a `33 kΩ`)** | Acoplamiento físico-digital inmediato mediante lectura analógica en `A0` y transmisión por `Web Serial API`. |
| **Ubicación geográfica** | Espacial (Lat / Lon) | **Posición 2D + Línea guía y Micro-ancla** | Preserva la coordenada exacta del cráter eliminando la oclusión de marcas en la cordillera (**Cápsulas 07 y 16**). |

---

## Origen y procesamiento de los datos

Los datos integrados en la visualización provienen de tres fuentes científicas de referencia:

1. **Smithsonian Institution — Global Volcanism Program (GVP):**  
   Catálogo histórico global de volcanes holocénicos y registro de erupciones documentadas con su Índice de Explosividad Volcánica (VEI).
2. **Oak Ridge National Laboratory — LandScan Global Population:**  
   Modelos demográficos satelitales que contabilizan la población residente en radios concéntricos de 5, 10, 30 y 100 km alrededor de cada volcán.
3. **Natural Earth / TopoJSON:**  
   Geometrías vectoriales a escala 1:110m de los países de Sudamérica.

### Pipeline de preparación ([`prepare_data.py`](prepare_data.py))

* **Consolidación histórica:** Procesa `eruptions_sample.csv` calculando para cada volcán su VEI máximo histórico (`max_vei`), total de erupciones y evento más notable.
* **Cruce demográfico:** Vincula los registros geológicos con `volcano_sample.csv`, integrando los anillos de población a 5, 10, 30 y 100 km.
* **Filtro analítico de severidad en Sudamérica:** Selecciona las **39 amenazas mayores de Sudamérica** que cumplen la condición:
  $$\text{VEI} \ge 4 \quad \lor \quad \text{Población a 10 km} \ge 10.000\text{ habitantes}$$
* **Exportación:** Genera el archivo estructurado [`data/volcanoes.json`](data/volcanoes.json).

---

## Arquitectura y tecnologías

| Capa | Tecnología | Propósito |
| :--- | :--- | :--- |
| **Fisicalización y Hardware** | **Arduino Leonardo + Divisor de Voltaje + Arcilla** | Detección física de los 4 volcanes arquetípicos mediante resistencias calibradas (`220 Ω`, `1 kΩ`, `10 kΩ`, `33 kΩ`) sobre contactos de aluminio. |
| **Comunicación Hardware-Web** | **Web Serial API** | Lectura asíncrona en tiempo real del puerto serial USB (`9600 baudios`) directamente desde el navegador sin servidores intermedios. |
| **Visualización e Interactividad** | **D3.js (v7)** | Renderizado SVG, proyección Mercator, escalas cromáticas y de tamaño, algoritmo anti-solapamiento (*Zero-Overlap*) y zoom delimitado. |
| **Cartografía Vectorial** | **TopoJSON Client (v3)** | Decodificación de geometrías y fronteras internacionales de Sudamérica. |
| **Motor de Sonificación** | **Tone.js (v14.8)** | Síntesis en Web Audio API (`MonoSynth` para subgraves sísmicos y `MembraneSynth` para pulso cardíaco). |
| **Tipografía y Estilos** | **CSS3 + Google Fonts** | Interfaz inmersiva en modo oscuro con tipografías *Archivo*, *Fraunces* y *JetBrains Mono*. |
| **Procesamiento y Servidor Local** | **Python 3 (`prepare_data.py`) / Node.js (`server.js`)** | Pipeline ETL de datos y servidor HTTP estático local. |

---

## Estructura del repositorio

```text
Proyecto-de-visualizacion/
├── arduino/
│   └── sensor_volcanes/
│       └── sensor_volcanes.ino          # Firmware Arduino Leonardo para lectura del divisor de voltaje en A0
├── css/
│   └── style.css                        # Hoja de estilos principal, diseño responsivo y tema visual oscuro
├── data/
│   ├── volcanoes.json                   # Dataset procesado de volcanes y métricas demográficas/explosivas
│   └── world-110m.json                  # Geometrías TopoJSON de países
├── js/
│   ├── audio.js                         # Motor de sonificación multicanal implementado con Tone.js
│   └── viz.js                           # Renderizado D3, algoritmo Zero-Overlap y conexión Web Serial con Arduino
├── eruptions_sample.csv                 # Registro histórico de erupciones (Global Volcanism Program)
├── volcano_sample.csv                   # Catálogo de volcanes con demografía satelital LandScan
├── prepare_data.py                      # Script Python para limpiar, cruzar y exportar los datos a JSON
├── server.js                            # Servidor HTTP local en Node.js
├── index.html                           # Estructura principal HTML5 de la visualización
├── Informe_Entrega_1_Grupo_19.docx      # Informe técnico de la Entrega 1
├── Informe_Entrega_2_Grupo_19.docx      # Informe del proceso de diseño de la Entrega 2 (Fisicalización)
└── README.md                            # Documentación general del proyecto
```

---

## Instalación y ejecución local

Debido a las políticas de seguridad CORS de los navegadores modernos para `fetch` / `d3.json` y los requisitos de contexto seguro (`localhost` o `HTTPS`) de la **Web Serial API**, la aplicación debe ejecutarse desde un servidor HTTP local.

### 1. Iniciar el servidor web local

#### Opción A: Con Node.js (Recomendada)
```bash
node server.js
```

#### Opción B: Con Python 3
```bash
python -m http.server 8080
```

Luego abre en **Google Chrome** o **Microsoft Edge** (compatibles con Web Serial API):
```text
http://localhost:8080
```

### 2. Configurar la placa Arduino Leonardo (Opcional para interacción física)

1. Abre el archivo [`arduino/sensor_volcanes/sensor_volcanes.ino`](arduino/sensor_volcanes/sensor_volcanes.ino) en **Arduino IDE**.
2. Selecciona la placa **Arduino Leonardo** y el puerto COM correspondiente, y sube el programa (*Upload*).
3. **Cierra el Monitor Serial** de Arduino IDE (para liberar el puerto COM).
4. En el navegador (`http://localhost:8080`), haz clic en **"Conectar Arduino"**, elige la placa en la ventana emergente y apoya los volcanes físicos sobre la base sensora.

---

## Proceso de diseño e iteraciones

### Etapa 1 — Visualización Digital y Sonora (Entrega 1)
```text
[V1/V2: Árbol de Tenis] ──(Pivote temático)──► [V3: Volcanes del Cinturón de Fuego] ──(R2/R3)──► [V4: Sudamérica Zero-Overlap]
```
* **De un catálogo global exploratorio a una tesis explicativa sudamericana:** Tras descartar la temática inicial de tenis (V1–V2) y explorar 958 volcanes del Cinturón de Fuego (V3), en V4 se focalizó el encuadre exclusivamente en las **39 amenazas mayores de Sudamérica**, implementando el algoritmo **Zero-Overlap** con líneas de guía para erradicar la oclusión de marcas en los Andes y aplicando la sonificación ortogonal en Tone.js.

### Etapa 2 — Fisicalización Interactiva (Entrega 2)
```text
[V1: Concepto Físico] ──(R1)──► [V2: 4 Fichas de Cartón + Arduino] ──(R2: Inversión Cromática)──► [V3: Color por Población] ──(R3 + Usuarios)──► [V4: Volcanes en Arcilla y Base de Encaje]
```
* **V2 — Muestra estratégica de 4 volcanes y acoplamiento con Arduino (`12/11/2026`, commit `5777bd1`):** Se acotó la representación física a 4 volcanes arquetípicos (*Pululahua*, *Villarrica*, *Licto* y *Cerro Hudson*) mediante fichas de cartón con resistencias integradas y una base sensora conectada a un Arduino Leonardo. Se descartó construir 39 piezas físicas para evitar sobrecarga cognitiva.
* **V3 — Inversión de la codificación visual y física (`16/11/2026`, commit `2272f2a`):** A partir del feedback de pares (R2), se invirtieron los canales visuales tanto en las piezas físicas como en el mapa digital: el **color (`YlOrRd`) pasó a codificar la población expuesta a 10 km** y el **tamaño pasó a codificar la explosividad (VEI)**. Esto alineó la intuición preatentiva del usuario (rojo oscuro = máximo peligro humano) con la urgencia del pulso cardíaco sonoro.
* **V4 — Volcanes tridimensionales en arcilla y estructura de soporte (`24/11/2026`):** A partir de la revisión docente (R3) y la evaluación con usuarios, se reemplazaron las fichas livianas de cartón por **volcanes modelados en arcilla** cuyo peso propio garantiza por gravedad un contacto eléctrico continuo sobre las láminas de aluminio, y se construyó una **estructura física de encaje** en la base sensora que guía de forma inequívoca dónde apoyar cada volcán.

---

## Feedback entre pares y evaluación con usuarios

* **Revisión entre pares (R2):**  
  * *Feedback recibido:* El grupo par advirtió que pintar los volcanes según su VEI llevaba a pensar que los volcanes rojos eran los de mayor riesgo humano, contradiciendo nuestra tesis demográfica. Esto motivó la inversión definitiva de canales en V3 (color para población a 10 km y tamaño para VEI).
  * *Feedback entregado:* Evaluamos un prototipo físico-digital con un muñeco articulado sobre horas de sueño y productividad, recomendándoles integrar un selector físico contador de horas de sueño que modulara directamente la velocidad del muñeco para hacer explícita la relación causal.
* **Evaluación con usuarios (Protocolo *Think-Aloud* y heurísticas de Zuk-Carpendale):**  
  * Al evaluar la V3 con un usuario externo sin conocimientos previos de vulcanología, se comprobó que la nueva codificación cromática y las dos capas sonoras (estruendo subgrave para VEI y latidos cardíacos para población) se comprendieron de inmediato sin explicación previa.
  * Sin embargo, se detectaron dos fricciones físicas: falta de descubribilidad sobre el punto exacto de contacto en la base y pérdida de contacto eléctrico por la ligereza del cartón al soltar la ficha. Ambos hallazgos condujeron al diseño final en **arcilla pesada** con **estructura guía de encaje** en la V4.

---

## Créditos y equipo

Proyecto desarrollado para el curso **IIC2026 — Visualización de Información**, Escuela de Ingeniería, Pontificia Universidad Católica de Chile.

| Nombre | Rol / Contribución | Correo institucional |
| :--- | :--- | :--- |
| **Javiera Bascur** | Procesamiento de datos satelitales, diseño cartográfico, fisicalización y documentación | `javiera.bascur@uc.cl` |
| **Constanza Hernández** | Motor de sonificación Tone.js, integración Arduino / Web Serial API, diseño visual CSS y visualización D3.js | `constanza.h.torres@uc.cl` |

*Datos geológicos cortesía de Smithsonian Institution (Global Volcanism Program) y datos demográficos cortesía de Oak Ridge National Laboratory (LandScan).*
