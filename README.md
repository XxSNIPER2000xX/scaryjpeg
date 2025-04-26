# scaryjpeg
simple image file format

essentially ppm but worse

# build 
gcc test.c scaryjpeg.c -o test

gcc viewer.c scaryjpeg.c -lglfw -lGLEW -lGL -lm -o scary_viewer

gcc png2scaryjpeg.c scaryjpeg.c -o png2scaryjpeg -lm
