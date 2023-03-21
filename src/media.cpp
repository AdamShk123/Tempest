#include "../include/media.hpp"

SDL_Texture *texture;

//class Background

bool loadMedia(SDL_Window *window)
{
    // loads success flag
	bool success = true;

    // loads JPG surface
    //loadSurface("resources/images/cat2.jpg",SDL_GetWindowSurface(window));

	// loads JPG texture
	texture = loadTexture("resources/images/cat2.jpg", SDL_GetRenderer(window));

	if(texture == NULL)
	{
		std::cout << "Failed to load JPG image!\n";
		success = false;
	}

	return success;
}

SDL_Surface *loadSurface(std::string path, SDL_Surface *screenSurface)
{
    //The final optimized image
	SDL_Surface* optimizedSurface = NULL;

	//Load image at specified path
	SDL_Surface* loadedSurface = IMG_Load(path.c_str());

	if(loadedSurface == NULL)
	{
		std::cout << "Unable to load image! " <<  path.c_str() << " SDL_image Error: " << IMG_GetError() << "\n";
	}
	else
	{
		//Convert surface to screen format
		optimizedSurface = SDL_ConvertSurface(loadedSurface, screenSurface->format, 0);

		if(optimizedSurface == NULL)
		{
			std::cout << "Unable to optimize image! " <<  path.c_str() << " SDL_image Error: " << IMG_GetError() << "\n";
		}

		//Get rid of old loaded surface
		SDL_FreeSurface(loadedSurface);
	}

	return optimizedSurface;
}

SDL_Texture *loadTexture(std::string path, SDL_Renderer *renderer)
{
    //Load image at specified path
    SDL_Texture *loadedTexture = IMG_LoadTexture(renderer, path.c_str());

    if(loadedTexture == NULL)
    {
        std::cout << "Unable to optimize image! " <<  path.c_str() << " SDL_image Error: " << IMG_GetError() << "\n";
    }

    return loadedTexture;
}
