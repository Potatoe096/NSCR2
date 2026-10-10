//Archivo de cabecera de las funciones de los sensores

#include "Sensores.cpp"

void tcaSelect(unit8_t canal);

//funciones de inicialización
void inicializarVL53L0X(unit8_t canal );

VL53L0X_RangingMeasurementData_t measure;