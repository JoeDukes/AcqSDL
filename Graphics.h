
#include "SDL.h"

class Graphics
{
public:

	Graphics();
	void Run();
	bool loadMedia();
private:

	
	void buildBoard();

private:

	SDL_Window* window;

	//The surface contained by the window
	SDL_Surface* gScreenSurface;

	//The image we will load and show on the screen
	SDL_Surface* gHelloWorld;

};
