#include "../include/main.hpp"

int main(int argc, char *argv[])
{
	Window window;

	Game game(&window);

	TTF_Init();

	SDL_Texture *texture = loadTexture("resources/images/cat2.jpg", window.getRenderer());

	TTF_Font *font = TTF_OpenFont("resouces/fonts/Roboto-Black.ttf",20);

	entt::registry registry;

	auto playerEntity = registry.create();

	registry.emplace<Position>(playerEntity,0,0);
	registry.emplace<Velocity>(playerEntity,0.0f,0.0f);
	registry.emplace<Texture>(playerEntity,texture);

	std::vector<System*> systems;

	MoveSystem moveSystem;
	DrawSystem drawSystem(&window);

	systems.push_back(&moveSystem);
	systems.push_back(&drawSystem);

	InputManager inputManager;

	std::unordered_map<std::string, bool> events;

	events["up"] = false;
	events["down"] = false;
	events["left"] = false;
	events["right"] = false;

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
				bool yChanged = false;
				bool xChanged = false;

				//Handle events on queue
				while(SDL_PollEvent(&e) != 0)
				{
					std::string event = inputManager.checkEvents(&e);
				
					if(event == "up")
					{
						if(!yChanged)
						{
							events.insert_or_assign(event,true);
							yChanged = true;
						}
					}
					else if(event == "down")
					{
						if(!yChanged)
						{
							events.insert_or_assign(event,true);
							yChanged = true;
						}
					}
					else
					{
						if(!yChanged)
						{
							events.insert_or_assign("up",true);
							events.insert_or_assign("down",true);
						}
					}

					//User requests quit
					if(e.type == SDL_QUIT)
					{
						quit = true;
					}
				}

				//Top left corner viewport
                SDL_Rect viewport = {0, 0, SCREEN_WIDTH, SCREEN_HEIGHT};
                SDL_RenderSetViewport(window.getRenderer(), &viewport);

				Velocity vel = registry.get<Velocity>(playerEntity);
				
				registry.replace<Velocity>(playerEntity,vel);

				window.clear();

				for(System *s : systems)
				{
					s->update(&registry);
				}

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