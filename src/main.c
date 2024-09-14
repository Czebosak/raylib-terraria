#include <stdio.h>
#include <math.h>
#include <raylib.h>
#include <stdint.h>
#include <stdlib.h>
#include <time.h>

#include "perlin_noise.hpp"

#include "chunk_manager.h"
#include "texture.h"
#include "render.h"

static const int TILE_AMOUNT = 20;
int screen_width = 640;
int screen_height = 480;

int main() {
    /*chunk_init();*/
    /*chunk_register(13);*/
    /*chunk_register(14);*/
    /*chunk_register(33);*/
    /*chunk_register(34);*/
    /*chunk_array_print();*/

    /*SetTraceLogLevel(LOG_ERROR); */

    InitWindow(screen_width*2, screen_height*2, "Yessir x3");

    Texture sprite = texture_tile_get(1);

    double noise[3][20];
    get_noise(time(NULL), &noise[0][0]);
    get_noise(time(NULL) * 0.5, &noise[1][0]);
    get_noise(time(NULL) - 1, &noise[2][0]);
    int tile_y[TILE_AMOUNT];
    for (int tile_i = 0; tile_i < TILE_AMOUNT; tile_i++) {
        float noise_sum = 0.0;
        for (int noise_i = 0; noise_i < 3; noise_i++) {
            noise_sum += noise[noise_i][tile_i];
        }

        tile_y[tile_i] = roundf(25.0 - noise_sum * 2.0);
    }

    /*RenderTexture2D screen_texture = LoadRenderTexture(screen_width, screen_height);*/
    while(!WindowShouldClose()) {
        /*BeginTextureMode(screen_texture);*/
        /*EndTextureMode();*/

        BeginDrawing();
            /*DrawTextureEx(screen_texture.texture, (Vector2){screen_width*2.0f, screen_height*2.0f}, 180.0, 2.0, WHITE);*/
            ClearBackground(WHITE);
            for (int i = 0; i < TILE_AMOUNT; i++) {
                render_tile(1, i, tile_y[i]);
            }
        EndDrawing();
    }

    texture_tile_unload_all();
    /*UnloadRenderTexture(screen_texture);*/
    CloseWindow();
    return 0;
}
