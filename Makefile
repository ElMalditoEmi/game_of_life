CC=g++
SRC=*.cpp
LIBS=-lSDL2
FLAGS=-O3
TARGET=main

all: $(TARGET)

$(TARGET): $(SRC)
	$(CC) $(SRC) -o $(TARGET) $(LIBS) $(FLAGS)

clean:
	rm $(TARGET)

