#include "perlin_noise.hpp"
#include <PerlinNoise.hpp>

void get_noise(unsigned int seed, double* array_ptr) {
    siv::PerlinNoise::seed_type p_seed = seed;

    siv::PerlinNoise perlin { seed };

    for (int x = 0; x < 20; x++) {
        array_ptr[x] = perlin.octave1D(x * 0.1, 4);
    }
}
