TARGET = app
SOURCE = main.c
COORDINATE_HEADER = ./include/coordinate.h
COORDINATE_SOURCE = ./src/coordinate.c
SQUARE_HEADER = ./include/square.h
SQUARE_SOURCE = ./src/square.c
FLAGS = -Wall -o

app: $(SOURCE) $(COORDINATE_HEADER) $(COORDINATE_SOURCE) $(SQUARE_HEADER) $(SQUARE_SOURCE)
	gcc $(FLAGS) $(TARGET) $(SOURCE) $(COORDINATE_SOURCE) $(SQUARE_SOURCE)

clean:
	rm -f $(TARGET)

.PHONY: clean
