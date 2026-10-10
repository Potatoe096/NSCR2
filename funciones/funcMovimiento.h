// Archivo de cabecera de funciones de movimiento

#include "funcMovimiento.cpp"

void InicializarDriver (DriverBTS driver);

void Avanzar(int velocidad);

void Retroceder(int velocidad);

void Detenerse();

// Giro normal(un lado parado y el otro avanza)
void Giro_derecha(int velocidad);

void Giro_izquierda(int velocidad);

// Giro sobre su propio eje (Lados giran en sentidos opuestos-Falta probar)
void Giro_Eje_Derecha(int velocidad);

void Giro_Eje_Izquierda(int velocidad);


