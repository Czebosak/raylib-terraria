#include "chunk_manager.h"
#include <raylib.h>

unsigned int tile_size_x = 16;
unsigned int tile_size_y = 16;
unsigned char chunk_amount = 12;
Chunk* chunk_array_ptr = NULL;

void chunk_init() {
    if (chunk_array_ptr != NULL) {
        free(chunk_array_ptr);
    }

    chunk_array_ptr = calloc(chunk_amount, sizeof(Chunk));
    if (chunk_array_ptr == NULL) {}
}

Chunk* chunk_register(int id) {
    Chunk* chunk_ptr = NULL;

    for (int i = 0; i < chunk_amount; i++) {
        if (!chunk_array_ptr[i].used) {
            chunk_ptr = &chunk_array_ptr[i];
            chunk_ptr->used = true;
            chunk_ptr->id = id;
            break;
        }
    }

    return chunk_ptr;
}

void chunk_array_print() {
    for (int i = 0; i < chunk_amount; i++) {
        printf(
            "Chunk %d:\n"
            "  Used: %d\n"
            "\n",
            chunk_array_ptr[i].id,
            chunk_array_ptr[i].used
        );
    }
}

Chunk* chunk_get_by_id(int id) {
    Chunk* chunk_ptr = NULL;

    for (int i = 0; i < chunk_amount; i++) {
        if (chunk_array_ptr[i].id == id) {
            chunk_ptr = &chunk_array_ptr[i];
        }
    }

    return chunk_ptr;
}

void chunk_generate(Chunk* chunk_ptr, long seed[3]) {
    // Get chunk index in current column
    int chunk_column_i = chunk_ptr->id % CHUNKS_PER_COLUMN;

    // Check if chunk is underground
    if (chunk_column_i > (int)(CHUNKS_PER_COLUMN * 0.25)) {
        TraceLog(LOG_INFO, "yessir     %d", chunk_ptr->id);
        // Generate dirt
        for (int tile_y = 0; tile_y < CHUNK_SIZE_Y; tile_y++) {
            for (int tile_x = 0; tile_x < CHUNK_SIZE_X; tile_x++) {
                chunk_ptr->tiles[tile_y][tile_x] = 2; // 2 - dirt id
            }
        }
    } else if (chunk_column_i == (int)(CHUNKS_PER_COLUMN * 0.25)) {
        TraceLog(LOG_INFO, "yessir2");
        // Generate grass
        double noise_sum[CHUNK_SIZE_X] = { 0.0 };
        get_noise_sum(seed, noise_sum, chunk_ptr->x);
        for (int tile_i = 0; tile_i < CHUNK_SIZE_X; tile_i++) {
            int grass_y = round(15.0 - (noise_sum[tile_i] * 2.0));

            chunk_ptr->tiles[grass_y][tile_i] = 1;
            for (int tile_y = grass_y + 1; tile_y < CHUNK_SIZE_Y; tile_y++) {
                chunk_ptr->tiles[tile_y][tile_i] = 2;
            }
        }
    }
}
