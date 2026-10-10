#include "funciones/funcMovimiento.h"
#include "funciones/Sensores.h"

// Dirección I2C por defecto del multiplexor TCA9548A
#define TCA_ADDR 0x70

// Crear la instancia del sensor
Adafruit_VL53L0X lox0 = Adafruit_VL53L0X();
Adafruit_VL53L0X lox1 = Adafruit_VL53L0X();
Adafruit_VL53L0X lox2 = Adafruit_VL53L0X();
Adafruit_VL53L0X lox3 = Adafruit_VL53L0X();

// Valores de las velocidades a usar para el motor (no son velocidades, sino la modulación de la onda,  pero asi me es más facil llamarla)
int vGiroa90 = 40;
int vGiro = 80;
int vGiro180 = 200
int v = 100;



void setup()
{
//Inicializamos Drivers
void InicializarDriver(DriverBTS driver);

Wire.begin();

// Inicializamos los VL53L0X
    tcaSelect(0);
    lox0.begin();

    tcaSelect(1);
    lox1.begin();

    tcaSelect(2);
    lox2.begin();

    tcaSelect(3);
    lox3.begin();
}
void loop() 
{

    // Checamos si llegamos
    if (char* leercolor() == el color de la meta)
        break;

    // Navegacion del laberinto
    // Distancias

    tcaSelect(0);
    unit16_t distancia0 = measure.RangeMiliMeter;

    tcaSelect(1);
    unit16_t distancia1 = measure.RangeMiliMeter;

    tcaSelect(2);
    unit16_t distancia2 = measure.RangeMiliMeter;

    tcaSelect(3);
    unit16_t distancia3 = measure.RangeMiliMeter;

    if (distancia0 <= 20)
    {
        if (distancia1 <= 20)
        {
            if(distancia2 <= 20)
            {
                if(distancia3 <= 20)
                {
                Giro_Eje_Derecha(vGiro180);
                delay(3500)
                }
            }
            else
            {
                Giro_Eje_Izquierda(vGiroa90)
                delay(2500)
            }
        }
        else
        {
            Avanzar(v/4)
            delay(3500)
        }
        
        else if (distancia2 <= 20)
        {
            for (int i = 1; i < 100; i += 2)
            {
                Giro_Eje_Derecha(i);
                delay(10)
            }
            delay(200)
        }
    }
    else
    {
        Avanzar(v)
        delay(2000)
    }
}