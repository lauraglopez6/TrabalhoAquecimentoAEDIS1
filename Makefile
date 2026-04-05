CXX      := gcc
CXXFLAGS := -Wall -Wextra -Werror
LDFLAGS  := -lm

BUILD    := ./build
OBJ_DIR  := $(BUILD)/objects
APP_DIR  := $(BUILD)
TARGET   := app

INCLUDE  := -Iinclude/
SRC      := $(wildcard src/*.c)

OBJECTS := $(SRC:src/%.c=$(OBJ_DIR)/%.o)

all: build $(APP_DIR)/$(TARGET)

$(OBJ_DIR)/%.o: src/%.c
	@mkdir -p $(@D)
	$(CXX) $(CXXFLAGS) $(INCLUDE) -c $< -o $@

$(APP_DIR)/$(TARGET): $(OBJECTS)
	@mkdir -p $(@D)
	$(CXX) $(CXXFLAGS) $(INCLUDE) -o $@ $(OBJECTS) $(LDFLAGS)

.PHONY: all build clean run

build:
	@mkdir -p $(OBJ_DIR)

clean:
	rm -rf build

run: all
	./$(BUILD)/$(TARGET)