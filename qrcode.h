class QRcode
{
	public:
		QRcode();
		
		void init();
		void screenwhite();
		void create(String message);
		void render(int x, int y, int color);
};