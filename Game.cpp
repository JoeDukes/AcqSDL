#include "Game.h"

Game::Game(const Graphics& graphics, const KeyboardServer& kServer):
	gfx(graphics),
	kbd(kServer),
	move(10)
{}

void Game::Update()
{
	if (kbd.DownIsPressed())
	{
		gfx.loadMedia();
	}
}