#pragma once

#include "chunk_manager.h"
#ifdef __cplusplus
extern "C" {
#endif

void get_noise_sum(long seed[3], double sum_array[20], int offset);

#ifdef __cplusplus
}
#endif
