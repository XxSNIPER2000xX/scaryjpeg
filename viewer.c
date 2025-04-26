#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "GL/glew.h"
#include "GLFW/glfw3.h"

#include "scaryjpeg.h"

GLuint makeTex(uint8_t *pixels, int w, int h) {
    GLuint tex;
    glGenTextures(1, &tex);
    glBindTexture(GL_TEXTURE_2D, tex);
    glPixelStorei(GL_UNPACK_ALIGNMENT, 1);
    glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, w, h, 0, GL_RGB, GL_UNSIGNED_BYTE, pixels);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
    return tex;
}

void quad() {
    glBegin(GL_QUADS);
        glTexCoord2f(0, 1); glVertex2f(-1, -1);
        glTexCoord2f(1, 1); glVertex2f( 1, -1);
        glTexCoord2f(1, 0); glVertex2f( 1,  1);
        glTexCoord2f(0, 0); glVertex2f(-1,  1);
    glEnd();
}

int main(int argc, char **argv) {
    uint8_t *pixels;
    const char *input;
    uint32_t h, w;
    
    GLuint texID;
    
    if (argc < 2) {
        fprintf(stderr, "Usage: %s input.scaryjpeg\n", argv[0]);
        exit(EXIT_FAILURE);
    }
    
    input = argv[1];

    // Load scaryjpeg file
    pixels = readScaryjpeg(input, &w, &h);
    if (!pixels) {
        fprintf(stderr, "Failed to load file\n");
        return 1;
    }
    
    if (!glfwInit()) exit(EXIT_FAILURE);

    GLFWwindow* window = glfwCreateWindow(w, h, "scary viewer", NULL, NULL);
    if (!window) exit(EXIT_FAILURE);
    glfwMakeContextCurrent(window);

    glewInit();

    texID = makeTex(pixels, w, h);
    free(pixels);

    glEnable(GL_TEXTURE_2D);

    while (!glfwWindowShouldClose(window)) {
        glClear(GL_COLOR_BUFFER_BIT);
        glBindTexture(GL_TEXTURE_2D, texID);
        quad();
        glfwSwapBuffers(window);
        glfwPollEvents();
    }

    glfwDestroyWindow(window);
    glfwTerminate();
    return 0;
}
