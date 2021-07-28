//Example configuration all four SERCOM as Serial port 
// RX example
//////////////////////////////////////////////////////////

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

  if (Serial0.available()) {
    Serial.print("[0]: ");
    Serial.write(Serial0.read());
  }

  if (Serial1.available()) {
    Serial.print("[1]: ");
    Serial.write(Serial1.read());
  }


  if (Serial2.available()) {
    Serial.print("[2]: ");
    Serial.write(Serial2.read());
  }

  if (Serial3.available()) {
    Serial.print("[3]: ");
    Serial.write(Serial3.read());
  }
}
