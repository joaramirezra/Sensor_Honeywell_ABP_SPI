#include <SPI.h>

// using two incompatible SPI devices, A and B. Incompatible means that they need different SPI_MODE
const int slaveAPin = 53;
double tranferFuntion(int data);

// set up the speed, data order and data mode
SPISettings settingsA(1500000, MSBFIRST, SPI_MODE0);
// SPI_MODE3:flanco de bajado sin retraso
int ajuste =14;
void setup() {
  // set the Slave Select Pins as outputs:
  pinMode (slaveAPin, OUTPUT);
  // initialize SPI:
  SPI.begin();
  // Inicializacion Serial
  Serial.begin(9600);
}

int16_t stat, mask,data,fin;
uint8_t stat2,stat1;

void loop() {
  SPI.beginTransaction(settingsA);
  digitalWrite (slaveAPin, LOW);
  stat = SPI.transfer16(0);
  SPI.endTransaction();
  digitalWrite (slaveAPin, HIGH);
  Serial.println(stat-8192+ajuste,DEC);
  delay(10);
}

double tranferFuntion(int data){
  return (data)/(1)*0.8+0.1;  
  }
