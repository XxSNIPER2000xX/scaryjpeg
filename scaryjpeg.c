#include "scaryjpeg.h"

#define PADDING_LENGTH 20

void saveScaryjpeg(const char *fileName, uint8_t *rgba, uint32_t w, uint32_t h) {
    const char *scary = "this jpeg is haunted";
    char padding[PADDING_LENGTH] = {0};
    FILE *f = fopen(fileName, "wb");
    if(!f) {
        fprintf(stderr, "failed to open file: %s\n", fileName);
        exit(EXIT_FAILURE);
    }
    
    strncpy(padding, scary, sizeof(padding) - 1);

    fwrite("SJPG", 1, 4, f);                    // magic
    fwrite(&w, sizeof(w), 1, f);                // width
    fwrite(&h, sizeof(h), 1, f);                // height
    fwrite(padding, 1, PADDING_LENGTH, f);      // comment
    fwrite(rgba, 4, w * h, f);                  // rgba data
    
    fclose(f);
}

uint8_t *readScaryjpeg(const char *fileName, uint32_t *outW, uint32_t *outH) {
    char comment[PADDING_LENGTH + 1] = {0};
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
    fread(comment, 1, PADDING_LENGTH, f);

    size = (*outW) * (*outH) * 4;
    data = malloc(size);
    fread(data, 1, size, f);
    fclose(f);
    return data;
}
