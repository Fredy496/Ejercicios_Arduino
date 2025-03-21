#include <BluetoothSerial.h>
#define pin 2
String dispbt = "Kripto";

#if !defined(CONFIG_BT_ENABLED) || !defined(CONFIG_BLUEDROID_ENABLED)
#error Bluetooth is not enabled! Please run `make menuconfig` to and enable it
#endif

#if !defined(CONFIG_BT_SPP_ENABLED)
#error Serial Bluetooth not available or not enabled. It is only available for the ESP32 chip.
#endif

BluetoothSerial SerialBT;


void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  SerialBT.begin(dispbt);
  pinMode(pin,OUTPUT);

  
}


void loop() {
  // put your main code here, to run repeatedly:
    if (SerialBT.available()) {
    Serial.write(SerialBT.read()); //Celphone --> ESP32
  }
  
  if (Serial.available()) {
    SerialBT.write(Serial.read()); //ESP32 --> Celphone
  }


  
}
