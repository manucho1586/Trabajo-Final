**Definición de Requisitos y Casos de Uso del Trabajo Final de Sistemas Embebidos**

**Selección del proyecto**

Para llevar adelante el desarrollo del proyecto final del presente curso, como primera instancia se determina el sistema a implementar entre varias opciones, las cuales son las siguientes:

- **Proyecto 1: Estación meteorológica**

Desarrollar una estación meteorológica que recolecte datos del clima como temperatura, humedad, presión atmosférica, y los muestre en un LCD. Los datos también se pueden enviar a un servidor web utilizando el ESP32 para monitoreo remoto.

- **Proyecto 2: Sistema de control para invernaderos**

Desarrollar un sistema de control inteligente para un invernadero que regule automáticamente la temperatura. El sistema recolectará datos ambientales y los mostrará en un LCD, además de enviar estos datos a un servidor web para monitoreo utilizando el ESP32. El sistema también permitirá el control manual de una alarma (buzzer) y un ventilador mediante botones.

Los aspectos a analizar a la hora de elegir entre los dos proyectos son:

- Tiempo de implementación
- Aporte de nuevos conocimientos
- Utilidad del sistema
- Disponibilidad de módulos de Hardware}

A continuación se presentará una tabla donde se ponderan en puntajes la importancia de factores determinantes a la hora de realizar el proyecto:

| **Proyecto** | **Disponibilidad de Hardware**<br><br>**Preponderancia: 10** | **Utilidad del proyecto**<br><br>**Preponderancia: 5** | **Tiempo de implementación**<br><br>**Preponderancia: 8** | **Suma de preponderancia de puntajes** |
| --- | --- | --- | --- | --- |
| Proyecto 1 | 8   | 4   | 5   | \-  |
| 80  | 20  | 40  | 140 |
| Proyecto 2 | 7   | 5   | 6   | \-  |
| 70  | 25  | 48  | 143 |

_Tabla 1. Ponderación de los proyectos alternativos para el trabajo final._

Vale aclarar que la puntuación por unidad se hizo teniendo como referencia una escala de 1 a 10, considerando como más positivo un valor de 10 y su contraparte un valor de 1.

Se disponen casi en su totalidad los dispositivos necesarios para ambos proyectos, aunque si se tiene en cuenta la utilidad de cada uno de los casos, particularmente para mí suma más construir un primer prototipo de un sistema de control de invernadero que una estación meteorológica, ya que para esta opción se dispone de servicios de meteorología, aunque puede ser un complemento en un futuro del sistema de control de invernadero.

**Breve descripción del sistema seleccionado**

El sistema debe medir la temperatura y humedad a través de un **sensor DHT11 para** mostrarlos en una pantalla LCD y en un servidor web, el cual se ejecutará en un ESP8266. En base a un valor umbral pautado como referencia se enciende un ventilador, el cual es energizado por medio de una etapa de potencia, dicha etapa de potencia sería un **transistor o un relé**, que se activará mediante una señal digital de estado lógico alto.

**Las indicaciones** de los estados según condiciones normales de humedad y temperatura se mostrarán mediante dos **LED**, uno verde para las condiciones normales y otro rojo para condiciones anormales para las plantas, a esta última condición se suma una alarma (**buzzer**), dichas indicaciones y el estado del ventilador y alarma también serán indicados en el servidor web.

Finalmente se pretende tener un control manual sobre el ventilador y el buzzer, usando **botones** para la activación o desactivación de estos.

En la _Figura 1_ se presenta el diagrama en bloques del sistema:

https://github.com/manucho1586/Trabajo-Final/blob/main/Diagrama%20en%20bloques%20del%20sistema.png
_Figura 1. Diagrama de bloques del sistema seleccionado._

**Obtención de requisitos y casos de uso**

Se realizó una breve investigación sobre las tecnologías disponibles en el mercado, a continuación se observa una comparación de estos:

| **Característica** | **Argus Controls** | **Priva Greenhouse Solutions** |
| --- | --- | --- |
| Conectividad | Ethernet, Wi-Fi | Ethernet, Wi-Fi, GPRS |
| Cargador Solar | No  | Opcional |
| API para HTTP Requests | Sí  | Sí  |
| Sensores | Temperatura, Humedad, CO2, Riego | Clima, Iluminación, Riego, CO2 |
| Alimentación | Transformador 220V | Opcional (Batería, Transformador) |
| Precio | Variable según configuración | Variable según configuración |
| Posicionamiento GNSS | No  | Opcional |
| SD Card | Opcional | Sí  |

_Tabla 2. Comparación de diferentes alternativas encontradas en el mercado._

Haciendo una comparación con los sistemas de control investigados, ambos son considerablemente robustos comparado con el proyecto a implementar, pero vale aclarar que esto es un prototipo y es escalable en lo que respecta a su robustez.

**Links de los sistemas investigados**

<https://arguscontrols.com/products-and-solutions/control-systems/titan-system>

<https://www.priva.com/es/horticultura/soluciones/climatizadores/priva-connext>

**Requerimientos**

| **Grupo de requerimiento** | **Descripción** |
| --- | --- |
| Sensado | El sistema medirá Temperatura |
| Sensado | El sistema medirá humedad |
| Actuadores | Ventilador que se enciende en caso de sobre temperatura |
| Actuadores | Alarma en caso de sobre temperatura |
| Conectividad | El sistema ofrecerá un servidor web para ver el estado del sistema |
| Alimentación | El sistema se alimentará de una fuente de corriente continua |
| Interfaz | Se presentará una interfaz usuario-sistema mediante una pantalla LCD |
| Tiempo de ejecución | El proyecto se entregará antes del 17 de septiembre de 2024. |

_Tabla 3. Requerimientos del sistema._

**Casos de uso**

| **Elemento de Caso de Uso** | **Definición** |
| --- | --- |
| **Disparador** | El sistema se enciende y el sensor DHT11 empieza a medir la temperatura y humedad. |
| **Precondición** | El sistema está encendido y el sensor DHT11 está correctamente conectado. La pantalla LCD y el ESP8266 están operativos. |
| **Flujo Básico** | El sistema mide la temperatura y la humedad utilizando el sensor DHT11. Los valores medidos se muestran en la pantalla LCD y se envían al servidor web a través del ESP8266. |
| **Flujo Alternativo** | La conexión con el servidor web falla. Los datos se almacenan temporalmente y se envían cuando la conexión se restablece. |

_Tabla 4. Caso de Uso 1: Medición y Visualización de Temperatura y Humedad._

| **Elemento de Caso de Uso** | **Definición** |
| --- | --- |
| **Disparador** | La temperatura o la humedad supera el umbral pautado. |
| **Precondición** | El sistema está encendido y el sensor DHT11 está midiendo continuamente. La etapa de potencia y el ventilador están conectados y operativos. |
| **Flujo Básico** | Cuando la temperatura o la humedad supera el umbral, el sistema envía una señal digital de estado lógico alto para activar la etapa de potencia, que energiza el ventilador. |
| **Flujo Alternativo** | La etapa de potencia falla. Se muestra un mensaje de error en la pantalla LCD. |

_Tabla 5. Caso de Uso 2: Control Automático del Ventilador._

| **Elemento de Caso de Uso** | **Definición** |
| --- | --- |
| **Disparador** | El usuario presiona los botones para activar o desactivar manualmente el ventilador o el buzzer. |
| **Precondición** | El sistema está encendido y los botones están correctamente conectados. El ventilador y el buzzer están operativos. |
| **Flujo Básico** | El usuario presiona el botón correspondiente y el sistema envía una señal digital de estado lógico alto o bajo para activar o desactivar el ventilador o el buzzer. El estado actual se muestra en la pantalla LCD y se actualiza en el servidor web. |
| **Flujo Alternativo** | El botón no funciona. No se realiza ninguna acción y se muestra un mensaje de error en la pantalla LCD. |

_Tabla 6. Caso de Uso 3: Control Manual del Ventilador y el Buzzer._
