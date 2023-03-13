all: compile link

FILES := src/*

LIBS := -l SDL2main -l SDL2 -l SDL2_image -l SDL2_mixer

compile:
	g++ -g ${FILES} -c
	mv *.o obj/

link:
	g++ obj/* -o main.exe ${LIBS}

clean:
	rm obj/* main.exe