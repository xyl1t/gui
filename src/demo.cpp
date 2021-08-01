#include <iostream>
#include <map>

#if __has_include("SDL2/SDL.h")
#include <SDL2/SDL.h>
#else
#include <SDL.h>
#endif
#define CIDR_IMPLEMENTATION
#include "cidr.hpp"
using namespace cdr;

#include "display.hpp"
#include "eventHandler.hpp"
#include "timer.hpp"

int main(int argc, char** argv) {
	SDL_Init(SDL_INIT_EVERYTHING);
	
	float zoom{1};
	if(argc != 1 && std::atoi(argv[1]) >= 1 ) zoom = std::atof(argv[1]);
	
	Display display(1280, 720, "GUI using SDL and Cidr", true, true, zoom, zoom);
	Renderer renderer{display.GetPixels(), display.GetCanvasWidth(), display.GetCanvasHeight()};
	
	
	while (!display.IsClosed()) {
		renderer.Clear(0x112233ff);
		renderer.DrawRectangle(RGB::White, 16, 16, 128, 128);
		
		
		
		display.Update();
		if (display.HasResized()) {
			renderer = Renderer(display.GetPixels(), display.GetCanvasWidth(), display.GetCanvasHeight());
		}
	}
	
	SDL_Quit();
	return 0;
}
