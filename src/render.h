#pragma once

#include <raylib.h>
#include "chunk_manager.h"
#include "texture.h"

void render_chunks();
void render_chunk(Chunk* chunk_ptr);
void render_tile(unsigned short id, int x, int y);
