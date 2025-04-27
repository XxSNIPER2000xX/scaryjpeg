#ifndef SCARYJPEG_H
#define SCARYJEPG_H

#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

uint8_t *readScaryjpeg(const char *fileName, uint32_t *outW, uint32_t *outH);
void saveScaryjpeg(const char *fileName, uint8_t *rgba, uint32_t w, uint32_t h);

#endif
