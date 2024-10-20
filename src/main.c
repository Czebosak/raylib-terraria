#include <stdio.h>
#include <raylib.h>
#include <stdint.h>
#include <stdlib.h>
#include <time.h>

#include "chunk_manager.h"
#include "texture.h"
#include "render.h"

static const int TILE_AMOUNT = 20;
int screen_width = 640;
int screen_height = 480;

int main() {
    InitWindow(screen_width*2, screen_height*2, "Yessir x3");

    chunk_init();
    Chunk* chunk_1_ptr = chunk_register(5);
    Chunk* chunk_2_ptr = chunk_register(6);
    Chunk* chunk_3_ptr = chunk_register(25);
    Chunk* chunk_4_ptr = chunk_register(26);
    Chunk* chunk_5_ptr = chunk_register(45);
    Chunk* chunk_6_ptr = chunk_register(46);

    chunk_3_ptr->x = 20;
    chunk_4_ptr->x = 20;
    chunk_5_ptr->x = 40;
    chunk_6_ptr->x = 40;
    chunk_2_ptr->y = 20;
    chunk_4_ptr->y = 20;
    chunk_6_ptr->y = 20;

    long cur_time = time(NULL);
    long seed[3] = { cur_time, cur_time * 0.5, cur_time - 1 };
    chunk_generate(chunk_1_ptr, seed);
    chunk_generate(chunk_2_ptr, seed);
    chunk_generate(chunk_3_ptr, seed);
    chunk_generate(chunk_4_ptr, seed);

    while(!WindowShouldClose()) {
        BeginDrawing();
            ClearBackground(WHITE);
            render_chunks();
        EndDrawing();
    }

    TraceLog(LOG_INFO, "%d", chunk_3_ptr->x);

    texture_tile_unload_all();
    /*UnloadRenderTexture(screen_texture);*/
    CloseWindow();
    return 0;
}
