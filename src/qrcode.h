#include "OLEDDisplay.h"
enum QRCODE_ALIGN {
  ALIGN_CENTER = 0,
  ALIGN_LEFT = 1,
  ALIGN_RIGHT = 2
};
class QRcode
{
	private:
		OLEDDisplay *display;
		void render(int x, int y, int color);

	public:
		QRcode(OLEDDisplay *display);

		void init();
		void debug();
		void screenwhite();
		void create(String message);
		void align(QRCODE_ALIGN mode);
};
