#include "perlin_noise.hpp"
#include <PerlinNoise.hpp>

void get_noise_sum(long seed[3], double sum_array[20], int offset) {
    for (int i = 0; i < 3; i++) {
        siv::PerlinNoise::seed_type p_seed = seed[i];

        siv::PerlinNoise perlin { p_seed };

        for (int x = 0; x < 20; x++) {
            sum_array[x] = perlin.octave1D((x + offset) * 0.1, 4);
        }
    }
}
