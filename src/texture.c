#include "texture.h"
#include <raylib.h>

#define ATLAS_SIZE 255
TextureLookup texture_loaded[ATLAS_SIZE] = { {}, false };

const char TEXTURE_PATHS[][32] = {
    "assets/textures/grass.png",
    "assets/textures/dirt.png"
};

Texture texture_tile_get(unsigned short id) {
    id = id-1;
    if (texture_loaded[id].initialized) {
        return texture_loaded[id].texture;
    } else {
        texture_loaded[id].texture = LoadTexture(TEXTURE_PATHS[id]);
        texture_loaded[id].initialized = true;
        return texture_loaded[id].texture;
    }
}

void texture_tile_unload_all() {
    for (int i = 0; i < ATLAS_SIZE; i++) {
        UnloadTexture(texture_loaded[i].texture);
        texture_loaded[i].initialized = false;
    }
}
