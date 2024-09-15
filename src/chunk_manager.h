#pragma once

#include <stdbool.h>
#include <stdlib.h>
#include <stdio.h>
#include <math.h>

#include "perlin_noise.hpp"

#define CHUNK_SIZE_X 20
#define CHUNK_SIZE_Y 20
#define CHUNKS_PER_COLUMN 20

typedef struct {
    bool used;
    int id;
    int x;
    int y;
    unsigned char tiles[CHUNK_SIZE_X][CHUNK_SIZE_Y];
} Chunk;


extern unsigned int tile_size_x;
extern unsigned int tile_size_y;
extern unsigned char chunk_amount;
extern Chunk* chunk_array_ptr;

void chunk_init();
Chunk* chunk_register(int id);
void chunk_array_print();
Chunk* chunk_get_by_id(int id);
void chunk_generate(Chunk* chunk_ptr, long seed[]);
