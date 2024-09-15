#include "render.h"

void render_chunks() {
    /*TraceLog(LOG_INFO, "WEEEE ARE EHEERE");*/
    /*TraceLog(LOG_INFO, "%d", chunk_amount);*/
    for (int i = 0; i < chunk_amount; i++) {
        /*TraceLog(LOG_INFO, "And maybe here");*/
        if (chunk_array_ptr[i].used == true) {
            /*TraceLog(LOG_INFO, "or here?");*/
            render_chunk(&chunk_array_ptr[i]);
        }
    }
}

void render_chunk(Chunk* chunk_ptr) {
    for (int y = 0; y < CHUNK_SIZE_Y; y++) {
        for (int x = 0; x < CHUNK_SIZE_X; x++) {
            /*TraceLog(LOG_INFO, "%d", chunk_ptr->y + y);*/
            /*TraceLog(LOG_INFO, "%d", chunk_ptr->tiles[y][x]);*/
            render_tile(chunk_ptr->tiles[y][x], chunk_ptr->x + x, chunk_ptr->y + y); // chunk_ptr->tiles[y][x]
        }
    }
}

void render_tile(unsigned short id, int x, int y) {
    if (id == 0) { return; }
    /*TraceLog(LOG_INFO, "id: %d, x: %d, y: %d\n", id, x, y);*/
    Texture sprite = texture_tile_get(id);
    DrawTexture(sprite, x * sprite.width, y * sprite.height, WHITE);
}
