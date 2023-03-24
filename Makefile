all: clean compile link

FILES := src/main.cpp src/media.cpp src/window.cpp src/game.cpp src/interface.cpp src/system.cpp src/input.cpp

LIBS := -l SDL2main -l SDL2 -l SDL2_image -l SDL2_mixer -l SDL2_ttf

compile:
	g++ -g ${FILES} -c
	mv *.o obj/

link:
	g++ obj/* -o main.exe ${LIBS}

clean:
	rm obj/* main.exe