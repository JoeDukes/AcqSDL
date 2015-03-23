
#include <stdio.h>
#include "Graphics.h"
#include "Keyboard.h"
#include "Game.h"
//********************************************************************************************************************************

static KeyboardServer kServ;

Graphics::Graphics():
	window(NULL),
	gScreenSurface(NULL),
	gHelloWorld(NULL)
{}
//********************************************************************************************************************************
void Graphics::Run()
{
	Game myGame( Graphics, kServ );

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

	if (window == NULL)
	{
		printf("Window could not be created! SDL_Error: %s\n", SDL_GetError());
	}
	else
	{
		//Get window surface
		gScreenSurface = SDL_GetWindowSurface(window);
	}

	while (game == true)
	{
		myGame.Update();
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
bool Graphics::loadMedia()
{
	//Loading success flag
	bool success = true;

	//Load splash image
	gHelloWorld = SDL_LoadBMP("arrow.bmp");
	if (gHelloWorld == NULL)
	{
		printf("Unable to load image %s! SDL Error: %s\n", "02_getting_an_image_on_the_screen/hello_world.bmp", SDL_GetError());
		success = false;
	}

	return success;
}
//********************************************************************************************************************************