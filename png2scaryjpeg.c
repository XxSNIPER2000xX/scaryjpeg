#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>

#define STB_IMAGE_IMPLEMENTATION
#include "stb_image.h"

#include "scaryjpeg.h"

int main(int argc, char **argv) {
    unsigned char *data;
    const char *input, *output;
    int h, w, channels;
    if (argc < 3) {
        fprintf(stderr, "Usage: %s input.png output.scaryjpeg\n", argv[0]);
        exit(EXIT_FAILURE);
    }

    input = argv[1];
    output = argv[2];

    data = stbi_load(input, &w, &h, &channels, 4);  // Force RGBA
    if (!data) {
        fprintf(stderr, "Failed to load image: %s\n", stbi_failure_reason());
        exit(EXIT_FAILURE);
    }

    printf("Loaded %s (%dx%d, %d channels)\n", input, w, h, channels);

    saveScaryjpeg(output, data, (uint32_t)w, (uint32_t)h);
    printf("Saved to %s\n", output);

    stbi_image_free(data);
    return 0;
}
