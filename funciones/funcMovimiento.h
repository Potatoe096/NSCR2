// Archivo de cabecera de funciones de movimiento

#include "funcMovimiento.cpp"

void Avanzar(int velocidad) 
{
  mover(driverIzq, velocidad);
  mover(driverDer, velocidad);
}

void Retroceder(int velocidad) 
{
  mover(driverIzq, -velocidad);
  mover(driverDer, -velocidad);
}

void Detenerse() 
{
  mover(driverIzq, 0);
  mover(driverDer, 0);
}

// Giro normal(un lado parado y el otro avanza)
void Giro_derecha(int velocidad) {
  mover(driverIzq, velocidad);
  mover(driverDer, 0);
}

void Giro_izquierda(int velocidad) {
  mover(driverIzq, 0);
  mover(driverDer, velocidad);
}

// Giro sobre su propio eje (Lados giran en sentidos opuestos-Falta probar)
void Giro_Eje_Derecha(int velocidad) {
  mover(driverIzq, velocidad);
  mover(driverDer, -velocidad);
}

void Giro_Eje_Izquierda(int velocidad) {
  mover(driverIzq, -velocidad);
  mover(driverDer, velocidad);
}


