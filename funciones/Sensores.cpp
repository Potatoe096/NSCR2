#include <Wire.h>
#include<Adafruit_VL53L0X.h>

//Dirección I2C por defecto del TCA9548A
#define TCA_ADDR 0x70

//Crear la instancia del sensor
Adafruit_VL53L0X lox = Adafruit_VL53L0X();

//Función para seleccionar el canal del multiplexor [0 a 7]
void tcaSelect(unit8_t canal)
{
    if (canal > 7) return;
    Wire.beginTransmission(TCA_ADDR);
    Wire.write(1 << canal);// Desplaza el bit al cana deceado
    Wire.endTRansmission();
}

void inicializarVL53L0X(unit8_t canal )
{
  tcaSelect(canal);
  lox1.begin;
}
// VL53L0X
VL53L0X_RangingMeasurementData_t measure; // Esto viene de la libreria vl53l0x
 lox.rangingTest(&measure, false); // checa si se realizo la lectura 
 measure.RangeStatus; // arroja valores de 0 a 4, 0 es lectura perfecta, y 4 fuera de rango
 measure.RangeMiliLeteter; //Da la distancia en mm