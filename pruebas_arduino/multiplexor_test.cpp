/* =========================================================================
   TEST MULTIPLEXOR TCA9548A CON SENSOR(ES) VL53L0X
   ========================================================================= */

#include <Wire.h>
#include <Adafruit_VL53L0X.h>

// Dirección I2C por defecto del multiplexor TCA9548A
#define TCA_ADDR 0x70

// Crear la instancia del sensor
Adafruit_VL53L0X lox0 = Adafruit_VL53L0X();
Adafruit_VL53L0X lox1 = Adafruit_VL53L0X();
Adafruit_VL53L0X lox2 = Adafruit_VL53L0X();
Adafruit_VL53L0X lox3 = Adafruit_VL53L0X();

// Función auxiliar para seleccionar el canal del multiplexor (0 a 7)
void tcaSelect(unit8_t i) {
  if (i > 7) return;
  Wire.beginTransmission(TCA_ADDR);
  Wire.write(1 << i); // Envía la máscara de bits para activar el canal 'i'
  Wire.endTransmission();
}

void inicializarSensorDistancia(unit8_t )
{
  tcaSelect()
}

void setup() {
  Serial.begin(9600);
  Wire.begin();
  tcaSelect(0);



  Serial.println("--- Inicio de prueba TCA9548A + VL53L0X ---");

  // --- PROBAR Y CONFIGURAR CANAL 0 ---
  tcaSelect(0); // Abrimos el canal 0 del multiplexor
  Serial.print("Inicializando VL53L0X en Canal 0... ");
  
  if (lox.begin()) {
    Serial.println("¡Detectado con éxito!");
  } else {
    Serial.println("Error: No se detectó ningún sensor en el Canal 0.");
  }

  // --- OPCIONAL: PROBAR Y CONFIGURAR CANAL 1 ---
  /*
  tcaSelect(1); // Abrimos el canal 1
  Serial.print("Inicializando VL53L0X en Canal 1... ");
  if (lox.begin()) {
    Serial.println("¡Detectado con éxito!");
  } else {
    Serial.println("Error: No se detectó ningún sensor en el Canal 1.");
  }
  */
}

void loop() {
  VL53L0X_RangingMeasurementData_t measure;

  // 1. Leer sensor en Canal 0
  tcaSelect(0); // Seleccionar Canal 0 antes de pedir lectura
  lox.rangingTest(&measure, false);

  Serial.print("Canal 0 -> ");
  switch(measure.RangeStatus)
  {
    case 0: //Ningun problema
    Serial.print("Distancia: ");
    Serial.print(measure.RangeMilliMeter);
    Serial.println(" mm");
    break;

    case 1:
    Serial.print("Distancia: ");
    Serial.print(measure.RangeMilliMeter);
    Serial.println(" mm");
    serial.print("Señal con mucho ruido") //Mucho ruido
    break;

    case 2:
    Serial.print("Distancia: ");
    Serial.print(measure.RangeMilliMeter);
    Serial.println(" mm");
    serial.print("Señal muy debíl"); //Baja intensidad (colores oscuros)
    break;

   case 3:
    Serial.print("Distancia: ");
    Serial.print(measure.RangeMilliMeter);
    Serial.println(" mm");
    serial.print("Distancia muy corta"); //Objeto muy pegado al sensor
    break;
    
    case 4:
      serial.print("Fuera de rango"); //No hay objeto enfrente
      break;

    case 5:
    serial.print("Fallo interno "); // Fallo de hardware
    break;

    default:
    Serial.println("Error de lectura o comunicación.");
    break;
  }

  // 2. Si conectaste otro VL53L0X en el Canal 1, descomenta esta sección:
  /*
  tcaSelect(1); // Seleccionar Canal 1
  lox.rangingTest(&measure, false);

  Serial.print("Canal 1 -> ");
  if (measure.RangeStatus != 4) {
    Serial.print("Distancia: ");
    Serial.print(measure.RangeMilliMeter);
    Serial.println(" mm");
  } else {
    Serial.println("Fuera de rango");
  }
  */

  Serial.println("------------------------------------");
  delay(1000);
}