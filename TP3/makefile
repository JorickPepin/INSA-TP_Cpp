CXXFLAGS = -g -ansi -pedantic -Wall -std=c++11 -MMD -MP
CC := g++

SRC := src
TESTS := tests
OBJ := obj

SOURCES := $(wildcard $(SRC)/*.cpp $(SRC)/*/*.cpp)
OBJECTS := $(patsubst $(SRC)/%.cpp, $(OBJ)/%.o, $(SOURCES))
DEPENDS := $(patsubst $(SRC)/%.cpp, $(OBJ)/%.d, $(SOURCES))
EXECUTABLE := sejours

TEST_SOURCES := $(wildcard $(TESTS)/*.cpp $(TESTS)/*/*.cpp)
TEST_OBJECTS := $(patsubst $(TESTS)/%.cpp, $(OBJ)/%.o, $(TEST_SOURCES))
TEST_EXECUTABLE := test

.PHONY: all debug test executable clean

all: $(EXECUTABLE)

debug: CXXFLAGS += -D MAP
debug: $(EXECUTABLE)

executable : $(EXECUTABLE)

$(EXECUTABLE): $(OBJECTS)
	$(CC) -o $(EXECUTABLE) $^ $(CXXFLAGS)

test: $(filter-out $(OBJ)/main.o, $(OBJECTS)) $(TEST_OBJECTS)
	$(CC) -o $(TEST_EXECUTABLE) $^ $(CXXFLAGS)

-include $(DEPENDS)

$(OBJ)/%.o: $(SRC)/%.cpp
	mkdir -p $(@D)
	$(CC) -c $< -o $@ $(CXXFLAGS)

$(OBJ)/%.o: $(TESTS)/%.cpp
	mkdir -p $(@D)
	$(CC) -c $< -o $@ $(CXXFLAGS)

clean:
	rm -rf $(OBJ) $(EXECUTABLE) $(TEST_EXECUTABLE)
