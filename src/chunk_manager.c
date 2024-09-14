#include "chunk_manager.h"

unsigned int tile_size_x = 16;
unsigned int tile_size_y = 16;
unsigned char chunk_amount = 12;
unsigned char chunks_per_column = 10;
Chunk* chunk_array_ptr = NULL;

void chunk_init() {
    if (chunk_array_ptr != NULL)
        free(chunk_array_ptr);

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

void chunk_generate(int id, unsigned int seed[]) {
    double noise[CHUNK_SIZE_X][3];
    get_noise(seed[0], &noise[0][0]);
    get_noise(seed[1], &noise[1][0]);
    get_noise(seed[2], &noise[2][0]);
    int tile_y[CHUNK_SIZE_X];
    for (int tile_i = 0; tile_i < CHUNK_SIZE_X; tile_i++) {
        double noise_sum = 0.0;
        for (int noise_i = 0; noise_i < 3; noise_i++) {
            noise_sum += noise[tile_i][noise_i];
        }

        tile_y[tile_i] = round(noise_sum * 2.0);
    }
}
