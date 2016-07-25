#include "OLEDDisplay.h"

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
};
