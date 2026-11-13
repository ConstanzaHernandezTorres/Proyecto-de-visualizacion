# ¿Dónde se encuentran las mayores amenazas volcánicas en Sudamérica?
### Visualización Interactiva y Sonora de Riesgo Geológico y Demográfico en la Cordillera de los Andes

**IIC2026 Visualización de Información · Pontificia Universidad Católica de Chile**  
**Proyecto de Visualización de Información — Entrega 1 · Grupo 19**

| Información | Detalle |
| :--- | :--- |
| **Grupo:** | Grupo 19 |
| **Integrantes:** | Javiera Bascur, Florencia Carvallo, Constanza Hernández |
| **GitHub Pages:** | [https://constanzahernandeztorres.github.io/Proyecto-de-visualizaci-n/](https://constanzahernandeztorres.github.io/Proyecto-de-visualizaci-n/) |
| **Repositorio GitHub:** | [https://github.com/ConstanzaHernandezTorres/Proyecto-de-visualizaci-n.git](https://github.com/ConstanzaHernandezTorres/Proyecto-de-visualizaci-n.git) |
| **Video demostrativo:** | [Insertar enlace a YouTube u otra plataforma pública] |

---

## Contenido

1. [Qué queremos comunicar](#qué-queremos-comunicar)
2. [La paradoja territorial andina](#la-paradoja-territorial-andina)
3. [Funcionalidades de la visualización](#funcionalidades-de-la-visualización)
4. [Cómo usar la visualización](#cómo-usar-la-visualización)
5. [Codificación visual y sonificación](#codificación-visual-y-sonificación)
6. [Origen y procesamiento de los datos](#origen-y-procesamiento-de-los-datos)
7. [Arquitectura y tecnologías](#arquitectura-y-tecnologías)
8. [Estructura del repositorio](#estructura-del-repositorio)
9. [Instalación y ejecución local](#instalación-y-ejecución-local)
10. [Proceso de diseño e iteraciones (V1 a V4)](#proceso-de-diseño-e-iteraciones-v1-a-v4)
11. [Evaluación con usuarios y feedback entre pares](#evaluación-con-usuarios-y-feedback-entre-pares)
12. [Créditos y equipo](#créditos-y-equipo)

---

## Qué queremos comunicar

La visualización responde a una pregunta concreta y urgente: **¿Dónde se encuentran las mayores amenazas volcánicas en Sudamérica?**

A lo largo de la Cordillera de los Andes convergen procesos geológicos de escala planetaria con asentamientos humanos históricos. Sin embargo, el concepto de "amenaza volcánica" suele comunicarse de forma homogénea o simplista, limitándose a reportar la magnitud de las erupciones o la mera presencia de volcanes activos.

Al cruzar el registro geológico histórico con la demografía satelital global de alta resolución, la visualización demuestra que el riesgo **no se distribuye de manera uniforme**: existe una marcada **asimetría territorial** entre el norte y el sur de la cordillera. 

Aplicando los principios de diseño explicativo directo (**Cápsulas 17 y 18**), la interfaz revela esta historia analítica desde el primer segundo de observación (*Overview First*), sin intermediación de filtros obligatorios ni menús complejos que dificulten la comprensión ciudadana.

---

## La paradoja territorial andina

La visualización evidencia directamente una paradoja geográfica y de protección civil:

```
                  ┌─────────────────────────────────────────────────────────┐
                  │      ¿DÓNDE RADICA LA AMENAZA EN LOS ANDES?             │
                  └────────────────────────────┬────────────────────────────┘
                                               │
               ┌───────────────────────────────┴───────────────────────────────┐
               ▼                                                               ▼
   NORTE (Ecuador y Colombia)                                      SUR (Chile y Argentina)
   • Riesgo humano masivo e inmediato                              • Violencia geológica extrema
   • Cientos de miles en radio letal (10 km)                       • Super-erupciones VEI 5 y 6
   • Pululahua: 534k hab. | Galeras: 121k hab.                     • Hudson, Villarrica, Calbuco, Llaima
   • Vulnerabilidad humanitaria crítica                            • Baja población a 10 km (<1.500 hab.)
                                                                   • Severo impacto regional (30 a 100 km)
```

1. **Foco Norte (Ecuador y Colombia) — Vulnerabilidad Humana Extrema:**
   * El peligro crítico reside en la exposición demográfica directa en la zona de evacuación inmediata (radio de 10 km).
   * Cientos de miles de habitantes residen en el radio letal de flujo piroclástico y lahares.
   * **Casos emblemáticos:**
     * **Pululahua (Ecuador):** 534.805 habitantes viviendo a menos de 10 km del complejo volcánico (VEI 4).
     * **Galeras (Colombia):** 121.282 habitantes expuestos en radio inmediato (VEI 4).
     * **Guagua Pichincha (Ecuador):** Población contigua a la zona metropolitana de Quito.
   * En este sector, erupciones de magnitud moderada implican un riesgo humanitario devastador.

2. **Foco Sur (Chile y Argentina) — Violencia Geológica Extrema:**
   * La amenaza radica en la violencia telúrica de super-erupciones históricas registradas con Índices de Explosividad Volcánica de **VEI 5 y VEI 6**.
   * La población directa dentro de los primeros 10 km es relativamente baja (< 1.500 habitantes), pero la magnitud explosiva produce columnas eruptivas de más de 20 km de altura, lluvia de cenizas que cruza el continente hacia el Atlántico y lahares que destruyen valles y cuencas a escala regional (30 a 100 km).
   * **Casos emblemáticos:**
     * **Cerro Hudson (Chile):** VEI 6 histórico; población a 10 km casi nula (<15 hab.), pero impacto destructivo severo en la Patagonia chilena y argentina.
     * **Villarrica, Calbuco y Llaima (Chile):** Eventos históricos VEI 5 con baja densidad inmediata pero severa afectación a centros turísticos y poblados agrícolas en radios de 30 a 100 km.

---

## Funcionalidades de la visualización

* **Cartografía continental focalizada:**  
  Mapa interactivo vectorial en SVG (construido con D3.js y TopoJSON) delimitado exclusivamente a Sudamérica. Emplea una proyección Mercator ajustada y maximizada para la pantalla, con paleta tonal oscura sobria, trazo de fronteras internacionales nítido y rótulos cartográficos discretos.
* **Algoritmo anti-solapamiento (*Zero-Overlap*):**  
  En zonas densas como la franja andina chilena y ecuatoriana, las coordenadas de los cráteres se encuentran geográficamente muy próximas. Para evitar que las marcas visuales se ocluyan entre sí (Cleveland & McGill, **Cápsula 16**), un algoritmo calcula la distancia entre nodos y proyecta líneas de guía (*leader lines*) de largo calibrado hacia el exterior. Micro-anclas circulares mantienen visible la coordenada exacta del cráter, garantizando la veracidad posicional y evitando el *Lie Factor* cartográfico (**Cápsula 07**).
* **Codificación visual bivariada:**  
  * **Color:** Escala secuencial térmica continua accesible para daltonismo (`YlOrRd`, de amarillo a rojo oscuro profundo, **Cápsula 10**) que mapea el Índice de Explosividad Volcánica histórico (VEI de 0 a 7).
  * **Tamaño / Área:** Círculos escalados por **área logarítmica** de la población en la zona de evacuación inmediata de 10 km (**Cápsula 09**: *Escalar el área, no el radio*), evitando la distorsión perceptiva exponencial.
* **Sonificación multicanal ortogonal con Tone.js:**  
  El sonido no es cosmético ni redundante con el volumen (**Cápsula 23**). Se orquestan dos canales acústicos independientes e informativos:
  1. *Canal Telúrico (Sintetizador subgrave FM):* Emite una nota grave profunda (de `D2` a `C1`) cuya frecuencia fundamental disminuye y cuya duración se alarga mientras mayor sea el VEI histórico.
  2. *Canal Humanitario (Sintetizador de membrana cardíaco):* Emite un pulso percusivo cuyo tempo en BPM (de 48 a 165 BPM) es proporcional a la población amenazada en el radio de 10 km, emulando la aceleración de un latido cardíaco ante la urgencia de evacuación.
  3. *Analizador de audio en tiempo real:* Analizador `Tone.Analyser` que alimenta la oscilación y respuesta sonora del sistema.
* **Panel guía de interpretación ciudadana:**  
  Bloque informativo fijado en pantalla que declara la medida de protección civil fundamental: *«En VEI ≥ 4 el radio de 10 km es indefendible: exige alerta roja y evacuación total inmediata»*, vinculando de forma directa las claves de lectura (color = explosividad, tamaño = habitantes en riesgo).
* **Ficha de inspección técnica esencial (*Inspector Card*):**  
  Tarjeta lateral con diseño sobrio que se actualiza al interactuar con cualquier volcán, exhibiendo el distintivo de riesgo (`🚨 RIESGO CRÍTICO`), nombre oficial, país, nivel de explosividad VEI y cifra exacta de personas en evacuación a 10 km.
* **Controles de navegación y zoom delimitado:**  
  Botones dedicados para acercar (`+`), alejar (`−`) y restablecer la vista (`⟲`). El comportamiento de zoom (`d3.zoom()`) está restringido mediante límites de escala (`k=1` a `k=8`) y caja de contención territorial (*translate extent*), garantizando que el usuario explore cómodamente sin salirse del continente ni perder el encuadre.
* **Tooltips contextuales en hover:**  
  Etiquetas flotantes con transición fluida que muestran nombre, país, VEI y población al posar el cursor sobre los volcanes.

---

## Cómo usar la visualización

1. **Exploración general (*Overview*):**  
   Al cargar la página, la vista continental exhibe los 39 volcanes de mayor amenaza en Sudamérica. Observe la distribución global: los círculos grandes se concentran en el norte (Ecuador y Colombia), mientras que los círculos de color rojo intenso y bordes oscuros predominan en el sur (Chile y Argentina).
2. **Activar la experiencia sonora:**  
   Debido a las políticas de reproducción de audio de los navegadores modernos, el motor de sonido se inicializa con el primer clic del usuario sobre el escenario interactivo.
3. **Navegación espacial:**  
   * **Zoom:** Utilice la rueda del ratón, el gesto de pellizco en trackpads o los botones `+` y `−` de la esquina superior izquierda.
   * **Paneo:** Arrastre el mapa con el botón principal del ratón para recorrer el arco andino.
   * **Restablecer vista:** Presione el botón `⟲` para volver al encuadre continental predeterminado.
4. **Inspección de un volcán:**  
   Haga clic sobre cualquier círculo o sobre su línea de proyección. Esto provocará:
   * El centrado visual y destacado del volcán seleccionado.
   * La actualización instantánea de la **Ficha de inspección técnica**.
   * La emisión de la sonificación multicanal: escuche la profundidad de la nota subgrave (magnitud geológica) seguida del ritmo de latidos cardíacos (urgencia demográfica).
5. **Lectura de la leyenda y panel guía:**  
   * Revise el recuadro superior izquierdo para conocer la norma técnica de evacuación inmediata ante eventos VEI ≥ 4.
   * Compare el círculo seleccionado con la escala de cuatro niveles demográficos (0, 10k, 100k, 500k+ hab.) y la barra térmica continua de VEI (0 a 7).

---

## Codificación visual y sonificación

| Variable de Datos | Tipo de Variable | Canal Visual / Sonoro | Justificación de Diseño y Principio |
| :--- | :--- | :--- | :--- |
| **Población en 10 km** | Cuantitativa continua | **Área del círculo (SVG)** | Escalamiento por área logarítmica para evitar subestimación visual (**Cápsula 09**: *Escalar el área, no el radio*). |
| **Población en 10 km** | Cuantitativa continua | **Tempo del pulso cardíaco (BPM)** | Metáfora intuitiva de urgencia vital; mayor población acelera el ritmo cardíaco (**Cápsula 23**). |
| **Explosividad (VEI)** | Cuantitativa discreta / ordinal | **Color secuencial térmico (`YlOrRd`)** | Escala perceptualmente ordenada y accesible para daltonismo; asocia calor/peligro con tonos oscuros (**Cápsula 10**). |
| **Explosividad (VEI)** | Cuantitativa discreta / ordinal | **Tono fundamental subgrave (Hz / Nota)** | Frecuencias más graves (`D2` a `C1`) y mayor duración representan la escala sísmica telúrica (**Cápsula 23**). |
| **Ubicación geográfica** | Espacial (Lat / Lon) | **Posición 2D + Micro-ancla** | Preserva la ubicación exacta del cráter con líneas de guía exteriores contra el solapamiento (**Cápsula 07** y **16**). |
| **País / Región** | Categórica nominal | **Fronteras y paleta tonal** | Tonos neutros diferenciados que proporcionan contexto geopolítico sin competir con los datos temáticos (**Cápsula 19**). |

---

## Origen y procesamiento de los datos

Los datos integrados en la visualización provienen de dos fuentes científicas de referencia mundial:

1. **Smithsonian Institution — Global Volcanism Program (GVP):**  
   Catálogo histórico global de volcanes holocénicos y registro de todas las erupciones documentadas con sus respectivos Índices de Explosividad Volcánica (VEI).
2. **Oak Ridge National Laboratory — LandScan Global Population:**  
   Modelos de cuadrículas demográficas satelitales globales que contabilizan la población flotante y residente en radios concéntricos de 5, 10, 30 y 100 km alrededor de cada edificio volcánico.
3. **Natural Earth / TopoJSON:**  
   Geometrías vectoriales simplificadas a escala 1:110m de los países del mundo y de Sudamérica.

### Pipeline de preparación (`prepare_data.py`)

Mediante el script automatizado en Python [`prepare_data.py`](prepare_data.py) se ejecutaron los siguientes pasos:
* **Consolidación por volcán:** Se procesó el archivo de erupciones históricas (`eruptions_sample.csv`), calculando el VEI máximo registrado (`max_vei`), el número total de eventos y la erupción notable más destructiva.
* **Cruce demográfico:** Se vincularon los datos geológicos con el catálogo de volcanes (`volcano_sample.csv`), unificando los anillos concéntricos de población (5, 10, 30 y 100 km).
* **Filtro analítico de severidad:** Para responder con nitidez y fluidez a la pregunta central sin dispersión cognitiva, se seleccionaron las **39 amenazas mayores de Sudamérica**, definidas bajo el criterio:
  $$\text{VEI} \ge 4 \quad \lor \quad \text{Población a 10 km} \ge 10.000\text{ habitantes}$$
* **Exportación estructurada:** Los datos limpios se exportaron al archivo JSON optimizado [`data/volcanoes.json`](data/volcanoes.json).

---

## Arquitectura y tecnologías

| Capa | Tecnología | Propósito |
| :--- | :--- | :--- |
| **Visualización e Interactividad** | **D3.js (v7)** | Manipulación del DOM SVG, proyección geográfica Mercator, escalas de color y tamaño, algoritmo anti-solapamiento y zoom. |
| **Cartografía Vectorial** | **TopoJSON Client (v3)** | Decodificación y renderizado eficiente de los límites continentales y fronteras de Sudamérica. |
| **Motor de Sonificación** | **Tone.js (v14.8)** | Síntesis acústica mediante Web Audio API (`MonoSynth` para subgraves sísmicos y `MembraneSynth` para pulso cardíaco). |
| **Tipografía y Estilos** | **CSS3 Moderno + Google Fonts** | Estructura responsiva, paleta oscura temática y fuentes (*Archivo*, *Fraunces* y *JetBrains Mono*). |
| **Procesamiento de Datos** | **Python 3** | Script ETL [`prepare_data.py`](prepare_data.py) para limpieza y consolidación de CSVs en formato JSON. |
| **Servidor de Pruebas** | **Node.js (`server.js`) / Python HTTP** | Servidor local HTTP para servir archivos estáticos evitando bloqueos de seguridad por CORS. |
| **Despliegue Continuo** | **GitHub Pages** | Publicación web accesible directamente desde el navegador. |

---

## Estructura del repositorio

```text
Proyecto-de-visualizacion/
├── css/
│   └── style.css            # Hoja de estilos principal, diseño responsivo y tema visual
├── data/
│   ├── volcanoes.json       # Dataset final procesado con las 39 amenazas de Sudamérica
│   └── world-110m.json      # Geometrías TopoJSON continentales y de países
├── js/
│   ├── audio.js             # Motor de sonificación multicanal implementado con Tone.js
│   └── viz.js               # Lógica de renderizado D3, algoritmo Zero-Overlap y eventos UI
├── eruptions_sample.csv     # Registro histórico de erupciones del Global Volcanism Program
├── volcano_sample.csv       # Catálogo de volcanes con demografía LandScan por anillos
├── prepare_data.py          # Script en Python para procesar, filtrar y consolidar los datos
├── server.js                # Servidor HTTP ligero en Node.js para ejecución local
├── index.html               # Estructura HTML5 de la visualización interactiva
└── README.md                # Memoria explicativa, guía de uso y documentación técnica
```

---

## Instalación y ejecución local

Debido a que D3.js carga archivos de datos locales (`data/volcanoes.json` y `data/world-110m.json`) mediante solicitudes asíncronas (`fetch` / `d3.json`), los navegadores bloquean la lectura directa desde el protocolo `file://` por políticas de seguridad (CORS). Es necesario servir la aplicación a través de un servidor HTTP local.

### Opción 1: Con Node.js (Recomendada)

Si tienes instalado Node.js:

```bash
# Iniciar el servidor local
node server.js
```

Abre en tu navegador la URL:
```text
http://localhost:8080
```

### Opción 2: Con Python 3

Si dispones de Python 3:

```bash
# Iniciar servidor HTTP en el puerto 8080
python -m http.server 8080
```

Luego ingresa en tu navegador a:
```text
http://localhost:8080
```

---

## Proceso de diseño e iteraciones (V1 a V4)

El diseño actual es el resultado de un proceso iterativo de cuatro versiones, alimentado por revisiones con el equipo docente, evaluaciones entre pares y pruebas con usuarios reales:

```
[V1: Árbol de Tenis] ──(R1: Docente)──► [V2: Tenis Completo] ──(Pivote)──► [V3: Volcanes Globales] ──(R2/R3/Usuarios)──► [V4: Sudamérica Zero-Overlap]
```

### V1 — La idea completa (Tenis)
* **Versión:** 1 | **Fecha:** 28/09/2026 | **Commit:** `81cb4d6`
* **Implementación:** Árbol de decisión interactivo sobre jugar al tenis con diagrama de Sankey monocromático, fondo temático simulando césped de cancha y sonido cosmético de raquetazo.
* **Feedback recibido (R1):** El equipo docente señaló que la cancha constituía ruido visual excesivo (*chartjunk*, **Cápsula 19** de Tufte) y que la sonificación era puramente decorativa sin codificar variables reales (**Cápsula 23**).

### V2 — Primera iteración (Dataset Completo de Tenis)
* **Versión:** 2 | **Fecha:** 28/09/2026 | **Commit:** `8eb1864`
* **Implementación:** Incorporación del dataset completo (6.667 registros), flujos diferenciados por color de clima y modulación tonal (agudo/grave) en el desenlace.
* **Aprendizaje y descarte:** Al cruzarse flujos de colores sobre la textura de la cancha, la visualización colapsó en sobrecarga visual y confusión perceptiva. Se concluyó que ningún arreglo cosmético podía otorgar relevancia analítica o impacto a un árbol de juguete. Se descartó definitivamente la temática de tenis.

### V3 — Segunda iteración (Giro radical a Volcanes Globales)
* **Versión:** 3 | **Fecha:** 12/10/2026 | **Commit:** `6ff25d8`
* **Implementación:** Giro temático hacia la amenaza volcánica del Cinturón de Fuego del Pacífico (958 volcanes). Proyección Natural Earth rotada a -150° (**Cápsula 15**), codificación bivariada (área por población a 10 km y color por VEI) y sonificación multicanal en Tone.js (subgrave FM + tempo cardíaco).
* **Feedback recibido (R2 y R3):** Evaluadores pares y docentes destacaron la trascendencia del tema y el audio, pero identificaron dos problemas graves: (1) severo solapamiento de marcas en la Cordillera de los Andes; y (2) desorientación del usuario ante un catálogo sobrecargado de datos sin una pregunta analítica conductora (*«muchas ostras y pocas perlas»*, **Cápsula 18**).

### V4 — La versión final (Sudamérica y Zero-Overlap)
* **Versión:** 4 | **Fecha:** 18/10/2026 | **Commit:** `da2e263`
* **Implementación:**
  * Reencuadre exclusivo en Sudamérica enfocado en los 39 volcanes de mayor amenaza.
  * Implementación del **Algoritmo Zero-Overlap** con líneas de guía exteriores y micro-anclas que garantizan la verdad posicional del cráter.
  * Enfoque explicativo directo: se eliminaron botoneras y filtros superfluos para maximizar el *Data-Ink Ratio* (**Cápsula 19**).
  * Incorporación de la guía ciudadana con la regla de evacuación inmediata ante VEI ≥ 4.

---

## Evaluación con usuarios y feedback entre pares

### Evaluación con usuarios (Thinking Aloud)
* **Participante:** Estudiante universitaria de tercer año (externa al curso y al grupo), sin conocimientos previos de vulcanología. Sesión presencial de 12 minutos realizada el 17 de octubre de 2026.
* **Hallazgos clave:**
  * **Comprensión sonora inmediata:** La participante comprendió sin instrucción previa la metáfora del pulso cardíaco: identificó espontáneamente que a mayor frecuencia de latidos había más vidas en peligro.
  * **Detección de puntos de bloqueo en V3:** Al intentar interactuar con la zona central de Chile expresó: *«¿Por qué algunos volcanes en Chile están uno encima del otro? No puedo pinchar el que está abajo»*. Asimismo, al activar filtros manuales manifestó confusión por saturación de pantalla.
  * **Impacto en el diseño final:** Estos resultados detonaron la transición a la V4, motivando la eliminación de la botonera de filtros a favor de una narrativa explicativa fija y la creación del algoritmo de desplazamiento anti-solapamiento con líneas de guía.

### Feedback formativo entregado a otros grupos (R2)
El Grupo 19 evaluó el proyecto del **Grupo 14** (visualización de sismicidad histórica en Chile):
* **Eje de profundidad invertido:** Se observó que el eje de profundidad crecía hacia arriba, contradiciendo la convención espacial intuitiva del plano subterráneo (**Cápsula 08**).
* **Escala cromática accesible:** Utilizaban una escala arcoíris (*rainbow colormap*); se les recomendó transicionar a una paleta secuencial perceptual continua como *Viridis* (**Cápsula 10**).
* **Sonificación multidimensional:** Variaban únicamente el volumen según la magnitud; se les aconsejó desacoplar canales asignando la magnitud al tono fundamental y la profundidad al timbre, evitando la fatiga auditiva (**Cápsula 23**).

---

## Créditos y equipo

Visualización desarrollada para el curso **IIC2026 — Visualización de Información**, Escuela de Ingeniería, Pontificia Universidad Católica de Chile.

| Nombre | Rol / Contribución | Correo institucional |
| :--- | :--- | :--- |
| **Javiera Bascur** | Procesamiento de datos satelitales, diseño cartográfico y documentación | `jbascur@uc.cl` |
| **Florencia Carvallo** | Codificación D3.js, algoritmo anti-solapamiento e interacción | `fcarvallo@uc.cl` |
| **Constanza Hernández** | Motor de sonificación Tone.js, diseño visual CSS y evaluación de usuarios | `chernandez@uc.cl` |

*Datos geológicos cortesía de Smithsonian Institution (GVP) y datos demográficos cortesía de Oak Ridge National Laboratory (LandScan).*
