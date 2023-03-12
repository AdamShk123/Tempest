all: compile link

FILES := src/*

compile:
	g++ -g ${FILES} -c
	mv *.o obj/

link:
	g++ obj/* -o main.exe

clean:
	rm obj/* main.exe