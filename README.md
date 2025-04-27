# scaryjpeg
simple image file format

essentially ppm but worse

# dependencies
scaryViewer: opengl glfw
png2scaryjpeg: stb_image.h

# build 
use the make file

or

gcc test.c scaryjpeg.c -o test

gcc viewer.c scaryjpeg.c -lglfw -lGLEW -lGL -lm -o scary_viewer

gcc png2scaryjpeg.c scaryjpeg.c -lm -o png2scaryjpeg

# change log
27/04/25 - added support for rgba and made a makefile
