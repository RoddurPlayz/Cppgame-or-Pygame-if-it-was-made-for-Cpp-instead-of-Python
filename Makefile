all:
	g++ -I Cppgame/SDL2-src/include -L Cppgame/SDL2-src/lib Cppgame/src/*.cpp -o output/main main.cpp -lmingw32 -lSDL2main -lSDL2 -lSDL2_image -lSDL2_mixer -lSDL2_net -lSDL2_ttf
	output/main