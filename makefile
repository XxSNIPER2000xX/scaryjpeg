CC = gcc

PNG2SCARY_SRC = png2scaryjpeg.c scaryjpeg.c
TEST_SRC = test.c scaryjpeg.c
VIEWER_SRC = viewer.c scaryjpeg.c

PNG2SCARY = png2scaryjpeg
TEST = test
VIEWER = scaryViewer

.PHONY: all clean

all: $(PNG2SCARY) $(VIEWER) $(TEST)

$(PNG2SCARY): $(PNG2SCARY_SRC)
	$(CC) -o $@ $^ -lm

$(TEST): $(TEST_SRC)
	$(CC) -o $@ $^

$(VIEWER): $(VIEWER_SRC)
	$(CC) -o $@ $^ -lGL -lglfw -lGLEW -lm

clean:
	rm -f $(PNG2SCARY) $(TEST) $(VIEWER)
