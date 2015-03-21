
#include <stdio.h>
#include "View.h"
#include "Keyboard.h"

//********************************************************************************************************************************

static KeyboardServer kServ;

View::View():
	window(NULL)
{}
//********************************************************************************************************************************
void View::Run()
{
	SDL_Event e;
	bool game = true;
	
	// Create an application window with the following settings:
	window = SDL_CreateWindow(
		"Acquisition",                     // window title
		SDL_WINDOWPOS_UNDEFINED,           // initial x position
		SDL_WINDOWPOS_UNDEFINED,           // initial y position
		640,                               // width, in pixels
		480,                               // height, in pixels
		SDL_WINDOW_OPENGL                  // flags - see below
		);

	while (game == true)
	{
		while (SDL_PollEvent(&e) != 0)
		{
			// Check that the window was successfully made
			if (e.type == SDL_QUIT)
			{
				game = false;
			}
			else if (e.type == SDL_KEYDOWN)
			{
				//Select surfaces based on key press
				switch (e.key.keysym.sym)
				{
				case SDLK_UP:
					kServ.OnUpPressed();
					break;

				case SDLK_DOWN:
					kServ.OnDownPressed();
					break;

				case SDLK_LEFT:
					kServ.OnLeftPressed();
					break;

				case SDLK_RIGHT:
					kServ.OnRightPressed();
					break;

				default:
					break;
				}
			}
			else if (e.type == SDL_KEYUP)
			{
				switch (e.key.keysym.sym)
				{
				case SDLK_UP:
					kServ.OnUpReleased();
					break;

				case SDLK_DOWN:
					kServ.OnDownReleased();
					break;

				case SDLK_LEFT:
					kServ.OnLeftReleased();
					break;

				case SDLK_RIGHT:
					kServ.OnRightReleased();
					break;

				default:
					break;
				}
			}
			
			SDL_UpdateWindowSurface(window);

		}
	}
	// Close and destroy the window
	SDL_DestroyWindow(window);
	// Clean up
	SDL_Quit();
}
//********************************************************************************************************************************
