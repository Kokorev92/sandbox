CXX		  := g++
CXX_FLAGS := -Wall -Wextra -std=c++17 -ggdb -O0

BIN		:= bin
SRC		:= src
INCLUDE	:= include
LIB		:= lib

LIBRARIES	:= -lncurses
EXECUTABLE	:= main

ifndef TYPE
TYPE := 
endif

ifeq ($(TYPE), static)
CXX_FLAGS += -static
LIBRARIES += -ltinfo
endif

all: $(BIN)/$(EXECUTABLE)

run: clean all
	clear
	./$(BIN)/$(EXECUTABLE)

$(BIN)/$(EXECUTABLE): $(SRC)/*.cpp
	$(CXX) $(CXX_FLAGS) -I$(INCLUDE) -L$(LIB) $^ -o $@ $(LIBRARIES)

clean:
	-rm $(BIN)/*
