# Detect the OS and set variables accordingly
ifeq ($(OS),Windows_NT)
	EXE_EXT = .exe
else
	EXE_EXT = .out
endif

CC = g++
LIBS = -lm
SRC = src
OBJ = obj
INC = include
BIN = bin
OBJS = $(OBJ)/pa3.o $(OBJ)/graph.o $(OBJ)/lista.o
HEADERS = $(INC)/graph.hpp $(INC)/lista.hpp $(INC)/auxiliar.hpp
CFLAGS = -Wall -c -g -I $(INC)

EXE = $(BIN)/pa3$(EXE_EXT)

$(BIN)/pa3$(EXE_EXT): $(OBJS)
	$(CC) -o $(BIN)/pa3$(EXE_EXT) $(OBJS) $(LIBS)

$(OBJ)/pa3.o: $(HEADERS) $(SRC)/pa3.cpp
	$(CC) $(CFLAGS) -o $(OBJ)/pa3.o $(SRC)/pa3.cpp

$(OBJ)/graph.o: $(HEADERS) $(SRC)/graph.cpp
	$(CC) $(CFLAGS) -o $(OBJ)/graph.o $(SRC)/graph.cpp

$(OBJ)/lista.o: $(HEADERS) $(SRC)/lista.cpp
	$(CC) $(CFLAGS) -o $(OBJ)/lista.o $(SRC)/lista.cpp

all: $(EXE)
 	
clean:
	rm -f $(EXE) $(OBJS)
