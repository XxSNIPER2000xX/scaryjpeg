#include "scaryjpeg.h"

#define H 256
#define W 256

int main(int argc, char **argv) {
    uint8_t *pixels = malloc(W * H * 4);

    for(uint32_t y = 0; y < H; y++) {
        for(uint32_t x = 0; x < W; x++) {
            int i = (y * W + x) * 4;
            pixels[i + 0] = (uint8_t)x; // r
            pixels[i + 1] = (uint8_t)y; // g
            pixels[i + 2] = 0;          // b
            pixels[i + 3] = 255;        // a
        }
    }
    saveScaryjpeg("test.scaryjpeg", pixels, W, H);
    free(pixels);
    return 0;
}
