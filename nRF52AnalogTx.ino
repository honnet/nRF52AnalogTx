// Import libraries (BLEPeripheral depends on SPI)
#include <SPI.h>
#include <BLEPeripheral.h>
#include "BLESerial.h"

// define pins (varies per shield/board)
#define BLE_REQ   PIN_LED1
#define BLE_RDY   PIN_LED2
#define BLE_RST   PIN_LED2

// create ble serial instance, see pinouts above
BLESerial BLESerial(BLE_REQ, BLE_RDY, BLE_RST);

void setup() {
    // custom services and characteristics can be added as well
    BLESerial.setLocalName("AnalogTx");

    Serial.begin(115200);
    BLESerial.begin();
}

void loop() {
    BLESerial.poll();

    forward();
    //loopback();
    analogTx();
}


// forward received from Serial to BLESerial and vice versa
void forward() {
    if (BLESerial && Serial) {
        int byte;
        while ((byte = BLESerial.read()) > 0) Serial.write((char)byte);
        while ((byte = Serial.read()) > 0) BLESerial.write((char)byte);
    }
}

// echo all received data back
void loopback() {
    if (BLESerial) {
        int byte;
        while ((byte = BLESerial.read()) > 0) BLESerial.write(byte);
    }
}

// Send the value of all the analog ports:
void analogTx() {

    // non blocking delay
    const int delayMS = 100;
    static long timeStampMS = millis(); // only affected at initialization
    if (millis() - timeStampMS < delayMS)
        return;
    timeStampMS = millis();

    char buffer[8*5]; // 8 numbers of maximum 4 digits + 1 separator
    char index = 0;

    if (BLESerial) {
        // extra pins (not normally in arduino): A6 = P0.02 and A7 = P0.05
        for (int pin = A0; pin < A0+NUM_ANALOG_INPUTS; pin++) {
            int val = analogRead(pin);
            index += sprintf(buffer + index, "%d ", val);
        }
        BLESerial.println(buffer);
    }
}

