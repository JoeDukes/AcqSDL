
#include "Keyboard.h"
#include "Graphics.h"

class Game
{
public:
	Game(Graphics& Graphics, const KeyboardServer& kServer);
	void Update();

private:

private:
	Graphics gfx;
	KeyboardClient kbd;

	int move;


};