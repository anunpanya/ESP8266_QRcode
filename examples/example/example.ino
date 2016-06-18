/* *********************************************************************************
 * ESP8266 QRcode
 * dependency library :
 *   ESP8266 Oled Driver for SSD1306 display by Daniel Eichborn, Fabrice Weinberg
 * 
 * SDA --> GPIO4 
 * SCL --> GPIO5
***********************************************************************************/

#include <qrcode.h>

QRcode qrcode;

void setup() {

    Serial.begin(115200);
    Serial.println("");
    Serial.println("Starting...");

    // enable debug qrcode
    // qrcode.debug();

    // Initialize QRcode display using library
    qrcode.init();

    // create qrcode
    qrcode.create("Hello world.");

}

void loop() { }