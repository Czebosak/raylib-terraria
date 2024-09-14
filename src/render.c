#include "render.h"

void render_chunks();

void render_chunk();

void render_tile(unsigned short id, int x, int y) {
    Texture sprite = texture_tile_get(id);
    DrawTexture(sprite, x * sprite.width, y * sprite.height, WHITE);
}
