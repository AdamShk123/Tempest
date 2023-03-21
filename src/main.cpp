#include "../include/main.hpp"

int main(int argc, char *argv[])
{
	//
	Window window;

	Game game(&window);

	SDL_Texture *texture = loadTexture("resources/images/cat2.jpg", window.getRenderer());

	
	if(&window == NULL)
	{
		printf( "Failed to initialize!\n" );
	}
	else
	{
		//Load media
		if(false)
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

				//Top left corner viewport
                SDL_Rect viewport = {0, 0, SCREEN_WIDTH, SCREEN_HEIGHT};
                SDL_RenderSetViewport(window.getRenderer(), &viewport);

				int w;
				int h;
				SDL_QueryTexture(texture, NULL, NULL, &w, &h);

				SDL_Rect rect;
				rect.x = 0;
				rect.y = 0;
				rect.w = w;
				rect.h = h;

				window.clear();
				game.update();
				window.draw(texture,&rect);
				window.render();
			}
		}
    }
}

// void loadLevel(std::string path)
// {
// 	std::fstream file;

// 	std::string line;

// 	file.open(path, std::ios_base::in);

// 	SDL_Rect fillRect;

// 	if(file.is_open())
// 	{
// 		int y = 0;
// 		while(std::getline(file, line))
// 		{
// 			int x = 0;
// 			int lineX = 0;
// 			char c = ' ';
// 			fillRect.y = y * 16;
// 			while(lineX != line.size())
// 			{
// 				c = line[lineX];
// 				//std::cout << "x: " << x << "y: " << y << "\n";
// 				if(c == '1')
// 				{
// 					fillRect.x = x * 16;
// 					Block b = {x,y};
// 					blocks.push_back(b);
// 					x++;
// 					lineX++;
// 				}
// 				else if(c == '0')
// 				{
// 					x++;
// 					lineX++;
// 				}
// 				else
// 				{
// 					lineX++;
// 				}
// 			}
// 			y++;
// 		}
// 	}	
// }