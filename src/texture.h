#pragma once

#include <raylib.h>

typedef struct {
    Texture texture;
    bool initialized;
} TextureLookup;

Texture texture_tile_get(unsigned short id);
void texture_tile_unload_all();
