all:
	mkdir -p obj build
	for file in src/*.cpp; do \
		g++ -std=c++11 -I./src -c $$file -o obj/$$(basename $$file .cpp).o `sdl2-config --cflags`; \
	done
	ar rvs build/Cppgame.lib obj/*.o `sdl2-config --libs`

clean:
	rm -rf obj build
