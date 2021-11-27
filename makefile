CXXFLAGS = -g -ansi -pedantic -Wall -std=c++11
CC := g++

SRC := src
TESTS := tests
OBJ := obj

SOURCES := $(wildcard $(SRC)/*.cpp $(SRC)/*/*.cpp)
OBJECTS := $(patsubst $(SRC)/%.cpp, $(OBJ)/%.o, $(SOURCES))
EXECUTABLE := sejours

TEST_SOURCES := $(wildcard $(TESTS)/*.cpp $(TESTS)/*/*.cpp)
TEST_OBJECTS := $(patsubst $(TESTS)/%.cpp, $(OBJ)/%.o, $(TEST_SOURCES))
TEST_EXECUTABLE := test

all: executable

debug: CXXFLAGS += -D MAP
debug: executable

executable: $(OBJECTS)
	$(CC) -o $(EXECUTABLE) $^ $(CXXFLAGS)

test: $(filter-out $(OBJ)/main.o, $(OBJECTS)) $(TEST_OBJECTS)
	$(CC) -o $(TEST_EXECUTABLE) $^ $(CXXFLAGS)

$(OBJ)/%.o: $(SRC)/%.cpp
	mkdir -p $(@D)
	$(CC) -c $< -o $@ $(CXXFLAGS)

$(OBJ)/%.o: $(TESTS)/%.cpp
	mkdir -p $(@D)
	$(CC) -c $< -o $@ $(CXXFLAGS)

.PHONY: clean
clean:
	rm -rf $(OBJ)/* $(EXECUTABLE) $(TEST_EXECUTABLE)
