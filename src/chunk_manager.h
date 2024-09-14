#pragma once

#include <stdbool.h>
#include <stdlib.h>
#include <stdio.h>
#include <math.h>

#include "perlin_noise.hpp"

#define CHUNK_SIZE_X 20
#define CHUNK_SIZE_Y 20

typedef struct {
    bool used;
    int id;
    unsigned char tiles[CHUNK_SIZE_X][CHUNK_SIZE_Y];
} Chunk;

void chunk_init();
Chunk* chunk_register(int id);
void chunk_array_print();
Chunk* chunk_get_by_id(int id);
