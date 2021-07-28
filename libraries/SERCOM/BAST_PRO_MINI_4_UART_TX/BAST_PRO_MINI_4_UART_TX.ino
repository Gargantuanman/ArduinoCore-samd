#include "wiring_private.h" // pinPeripheral() function
Uart Serial0 (&sercom0, A2, A1, SERCOM_RX_PAD_1, UART_TX_PAD_0);
Uart Serial2 (&sercom2, A5, A4, SERCOM_RX_PAD_1, UART_TX_PAD_0);
Uart Serial3 (&sercom3, 12, 11, SERCOM_RX_PAD_3, UART_TX_PAD_0);

void SERCOM0_Handler()
{
  Serial0.IrqHandler();
}

void SERCOM2_Handler()
{
  Serial2.IrqHandler();
}

void SERCOM3_Handler()
{
  Serial3.IrqHandler();
}

void setup() {
  Serial.begin(38400); //USB Serial
  Serial0.begin(38400); //A1:tx A2:Rx
  Serial1.begin(38400); //0:Tx 1:Rx
  Serial2.begin(38400); //A5:Rx A4:Tx
  Serial3.begin(38400); //11:Tx 12:Rx

  delay(1000); //Solo para dar tiempo a la terminal serial de estar lista

  pinPeripheral(19, PIO_SERCOM); //Sobreescibir la configuracion de pines
  pinPeripheral(20, PIO_SERCOM); //Sobreescibir la configuracion de pines
  pinPeripheral(23, PIO_SERCOM); //Sobreescibir la configuracion de pines
  pinPeripheral(22, PIO_SERCOM); //Sobreescibir la configuracion de pines
  pinPeripheral(11, PIO_SERCOM); //Sobreescibir la configuracion de pines
  pinPeripheral(12, PIO_SERCOM); //Sobreescibir la configuracion de pines
}

void loop() {
  Serial.println("Hola USB");
  Serial0.println("Hola Serial 0");
  Serial1.println("Hola Serial 1");
  Serial2.println("Hola Serial 2");
  Serial3.println("Hola Serial 3");
  delay(1000);
}
