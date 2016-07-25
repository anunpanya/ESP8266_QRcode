#include <Arduino.h>
#include "qrcode.h"
#include "qrencode.h"

int offsetsX = 42;
int offsetsY = 10;
int screenwidth = 128;
int screenheight = 64;
bool QRDEBUG = false;

QRcode::QRcode(OLEDDisplay *display){
	this->display = display;
}

void QRcode::init(){
	if(QRDEBUG)
		Serial.println("QRcode init");

	display->init();
  display->flipScreenVertically();
	display->setColor(WHITE);
}

void QRcode::debug(){
	QRDEBUG = true;
}

void QRcode::render(int x, int y, int color){
  x=x+offsetsX;
  y=y+offsetsY;
  if(color==1) {
	display->setColor(BLACK);
    display->setPixel(x, y);
  }
  else {
	display->setColor(WHITE);
    display->setPixel(x, y);
  }
}

void QRcode::screenwhite(){
	display->clear();
	display->setColor(WHITE);
	display->fillRect(0, 0, screenwidth, screenheight);
	display->display();
}

void QRcode::create(String message) {

  // create QR code
  message.toCharArray((char *)strinbuf,260);
  qrencode();
  screenwhite();

  if(QRDEBUG){
	Serial.println("QRcode render");
	Serial.println();
  }
  // print QR Code
  for (byte x = 0; x < WD; x+=2) {
    for (byte y = 0; y < WD; y++) {
      if ( QRBIT(x,y) &&  QRBIT((x+1),y)) {
        // black square on top of black square
        if(QRDEBUG)
			Serial.print("@");
        render(x, y, 1);
        render((x+1), y, 1);
      }
      if (!QRBIT(x,y) &&  QRBIT((x+1),y)) {
        // white square on top of black square
        if(QRDEBUG)
			Serial.print(" ");
        render(x, y, 0);
        render((x+1), y, 1);
      }
      if ( QRBIT(x,y) && !QRBIT((x+1),y)) {
        // black square on top of white square
        if(QRDEBUG)
			Serial.print("@");
        render(x, y, 1);
        render((x+1), y, 0);
      }
      if (!QRBIT(x,y) && !QRBIT((x+1),y)) {
        // white square on top of white square
        if(QRDEBUG)
			Serial.print(" ");
        render(x, y, 0);
        render((x+1), y, 0);
      }
    }
    Serial.println();
  }
  Serial.println();
  display->display();
}
