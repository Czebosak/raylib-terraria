CC=gcc
CCflags=-Iexternal/raylib/src/
LinkerFlags=-Lexternal/raylib/src/ -Wall
libs=-lraylib -lm

all: clean link

build/bin:
	mkdir -p build/bin

build/obj:
	mkdir -p build/obj

link: compile build/bin
	$(CC) build/obj/main.o build/obj/perlin_noise.o build/obj/texture.o build/obj/chunk_manager.o build/obj/render.o -o build/bin/main $(LinkerFlags) $(libs)

compile: build/obj/main.o build/obj/perlin_noise.o build/obj/texture.o build/obj/chunk_manager.o build/obj/render.o

build/obj/main.o: build/obj external/raylib/src/libraylib.a
	$(CC) src/main.c -o build/obj/main.o -c $(CCflags)

build/obj/texture.o: build/obj external/raylib/src/libraylib.a
	$(CC) src/texture.c -o build/obj/texture.o -c $(CCflags)

build/obj/chunk_manager.o: build/obj
	$(CC) src/chunk_manager.c -o build/obj/chunk_manager.o -c $(CCflags)

build/obj/render.o: build/obj external/raylib/src/libraylib.a
	$(CC) src/render.c -o build/obj/render.o -c $(CCflags)

build/obj/perlin_noise.o: build/obj external/PerlinNoise/PerlinNoise.hpp
	$(CC) src/perlin_noise.cpp -o build/obj/perlin_noise.o -c $(CCflags) -idirafter external/PerlinNoise

external/raylib:
	git clone --depth 1 https://github.com/raysan5/raylib.git external/raylib

external/raylib/src/libraylib.a: external/raylib
	cd external/raylib/src && make PLATFORM=PLATFORM_DESKTOP

external/PerlinNoise/PerlinNoise.hpp:
	git clone --depth 1 https://github.com/Reputeless/PerlinNoise.git external/PerlinNoise

# build/obj/PerlinNoise.o: external/PerlinNoise

clean:
	rm -rf build/*
