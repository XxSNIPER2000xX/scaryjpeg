#include "scaryjpeg.h"

void saveScaryjpeg(const char *fileName, uint8_t *rgb, uint32_t w, uint32_t h) {
    const char *scary = "this jpeg is haunted";
    char padding[32] = {0};
    FILE *f = fopen(fileName, "wb");
    if(!f) {
        fprintf(stderr, "failed to open file: %s\n", fileName);
        exit(EXIT_FAILURE);
    }
    
    strncpy(padding, scary, sizeof(padding) - 1);

    fwrite("SJPG", 1, 4, f);        // magic
    fwrite(&w, sizeof(w), 1, f);    // width
    fwrite(&h, sizeof(h), 1, f);    // height
    fwrite(padding, 1, 32, f);      // comment
    fwrite(rgb, 3, w * h, f);       // rgb data
    
    fclose(f);
}

uint8_t *readScaryjpeg(const char *fileName, uint32_t *outW, uint32_t *outH) {
    char comment[33] = {0};
    uint8_t *data; 
    char magic[4];
    int size;

    FILE *f = fopen(fileName, "rb");
    if(!f) return NULL;
    
    fread(magic, 1, 4, f);
    if(memcmp(magic, "SJPG", 4) != 0) {
        fclose(f);
        return NULL;
    }

    fread(outW, 4, 1, f);
    fread(outH, 4, 1, f);
    fread(comment, 1, 32, f);

    size = (*outW) * (*outH) * 3;
    data = malloc(size);
    fread(data, 1, size, f);
    fclose(f);
    return data;
}
