// Estructura para agrupar los pines de un driver BTS7960
struct DriverBTS {
  int rPwmPin; // Giro Derecha / Avanzar (PWM)
  int lPwmPin; // Giro Izquierda / Retroceder (PWM)
  int rEnPin;  // Enable Derecha (Digital)
  int lEnPin;  // Enable Izquierda (Digital)
};

// Confi de pines para 2 drivers

// Hemisferio izquierdo
DriverBTS driverIzq = {2, 3, 22, 23};

//Hemisferio derecho
DriverBTS driverDer = {4, 5, 24, 25};

// ------------Función de control del Motor ------------


void mover(DriverBTS driver, int velocidad) {
  if (velocidad > 0) {
    // Avanzar
    analogWrite(driver.rPwmPin, velocidad);
    analogWrite(driver.lPwmPin, 0);
  } 
  else if (velocidad < 0) {
    // Retroceder
    analogWrite(driver.rPwmPin, 0);
    analogWrite(driver.lPwmPin, abs(velocidad));
  } 
  else {
    // Frenar / Detener
    analogWrite(driver.rPwmPin, 0);
    analogWrite(driver.lPwmPin, 0);
  }

    // Esta función dandole una velocidad, identificará mediante condicionales a que Pwm mandar la señal, esta será usada en las funciones de movimiento
}
// ------------Función de inicializacion------------
void InicializarDriver (DriverBTS driver){
    pinMode(driver.rPwmPin, OUTPUT);
    pinMode(driver.lPwmPin, OUTPUT);
    pinMode(driver.rEnPin, OUTPUT);
    pinMode(driver.lEnPin, OUTPUT);

    //Dejar habilitado el driver perm
    digitalWrite(driver.rEnPin, High);
    digitalWrite(driver.lEnPin, High);
}
    // Se encarga de inicializar los pines de un driver, para no tener que hacerlo dos veces


//------------Funciones de Movimiento del motor------------

// Estás funciones se apoyan de la función moverse, ingresando las velocidades a estas

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

