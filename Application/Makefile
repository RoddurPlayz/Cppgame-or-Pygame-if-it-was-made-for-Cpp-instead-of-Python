all:
	mkdir -p obj build
	for file in src/*.cpp; do \
		g++ -std=c++11 -I./src -I../Cppgame/src -c $$file -o obj/$$(basename $$file .cpp).o `sdl2-config --cflags`; \
	done
	g++ -o build/MyApplication obj/*.o ../Cppgame/build/Cppgame.lib `sdl2-config --libs` -lSDL2_image -lSDL2_mixer

