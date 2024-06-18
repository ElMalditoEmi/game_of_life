CC=g++
SRC=*.cpp
LIBS=-lSDL2
TARGET=main

all: $(TARGET)

$(TARGET): $(SRC)
	$(CC) $(SRC) -o $(TARGET) $(LIBS)

clean:
	rm $(TARGET)

