/* *********************************************************************************
 * ESP8266 QRcode
 * dependency library :
 *   ESP8266 Oled Driver for SSD1306 display by Daniel Eichborn, Fabrice Weinberg
 *
 * SDA --> D6
 * SCL --> D7
***********************************************************************************/

#include <qrcode.h>
#include <SSD1306.h>

SSD1306  display(0x3c, D6, D7);
QRcode qrcode (&display);

void setup() {

    Serial.begin(115200);
    Serial.println("");
    Serial.println("Starting...");

    display.init();
    display.clear();
    display.display();


    // enable debug qrcode
    // qrcode.debug();

    // Initialize QRcode display using library
    qrcode.init();
    // create qrcode
    qrcode.create("Hello world.");

}

void loop() { }
