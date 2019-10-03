#include <HM_10_BLE.h>

class HM_10_BLE_Custom : public HM_10_BLE {
public:
  HM_10_BLE_Custom::HM_10_BLE_Custom(int8_t TXD, int8_t RXD) : HM_10_BLE(TXD, RXD) {
  }
  virtual void processMessage(char* msg) {
    Serial.print("process: ");
    Serial.println(msg);
  }
};

// HM-10
#define BLE_TXD 2
#define BLE_RXD 3

HM_10_BLE_Custom bleSerial(BLE_TXD, BLE_RXD);

const char* ssid = "ESP8266";
// end HM-10
void setup() {
  Serial.begin(9600);
  bleSerial.begin('!');
}

void loop() {
  bleSerial.atHandler();
  bleSerial.messageHandler();
  //
  bleSerial.writeMessage(ssid);
  delay(1000);
}
