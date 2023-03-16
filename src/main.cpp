#include "../include/main.hpp"

int main(int argc, char *argv[])
{
    SDL_Window *window = NULL;

    window = initWindow();

	if(window == NULL)
	{
		printf( "Failed to initialize!\n" );
	}
	else
	{
		//Load media
		if(!loadMedia(window))
		{
			printf( "Failed to load media!\n" );
		}
		else
		{	
			//Main loop flag
			bool quit = false;

			//Event handler
			SDL_Event e;

			//While application is running
			while(!quit)
			{
				//Handle events on queue
				while(SDL_PollEvent(&e) != 0)
				{
					//User requests quit
					if(e.type == SDL_QUIT)
					{
						quit = true;
					}
				}

                SDL_Renderer *renderer = SDL_GetRenderer(window);

				int w;
				int h;
				SDL_QueryTexture(texture, NULL, NULL, &w, &h);

				SDL_Rect rect;
				rect.x = 0;
				rect.y = 0;
				rect.w = w;
				rect.h = h;
				

				//Clear screen
				SDL_RenderClear(renderer);

				//Render texture to screen
				SDL_RenderCopy(renderer, texture, NULL, &rect);

				//Update screen
				SDL_RenderPresent(renderer);
			}
		}
	}

	//Free resources and close SDL
	close(window);

	return 0;
}

void close(SDL_Window *window)
{
	//Free loaded image
	SDL_DestroyTexture(texture);
	texture = NULL;

	//Destroy window	
	SDL_DestroyRenderer(SDL_GetRenderer(window));
	SDL_DestroyWindow(window);

	//Quit SDL subsystems
	IMG_Quit();
	SDL_Quit();
}

SDL_Window *initWindow()
{
    SDL_Window *window = NULL;

    // init SDL
    if(SDL_Init(SDL_INIT_VIDEO))
    {
        std::cout << "SDL could not initialize! SDL Error: " << SDL_GetError() << "\n";
    }
    else
    {
        // create window
        window = SDL_CreateWindow("Tempest", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, SCREEN_WIDTH, SCREEN_HEIGHT, SDL_WINDOW_FULLSCREEN_DESKTOP);
        if(window == NULL)
        {
            std::cout << "Window could not be created! SDL Error: " << SDL_GetError() << "\n";
        }
        else
        {
            //Create renderer for window
            SDL_Renderer *renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);
            if(renderer == NULL)
            {
                std::cout << "Renderer could not be created! SDL Error: " << SDL_GetError() << "\n";
            }
            else
            {
                int imgFlags = IMG_INIT_JPG;
                if(!(IMG_Init(imgFlags) & imgFlags))
                {
                    std::cout << "SDL_image could not initialize! SDL_image Error: " << IMG_GetError() << "\n";
                }
            }
        }
    }
    
    return window;
}