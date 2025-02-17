SRC_DIR = src
OBJ_DIR = ../../build/obj

SOURCES = $(wildcard $(SRC_DIR)/*.cpp)
OBJECTS = $(patsubst $(SRC_DIR)/%.cpp, $(OBJ_DIR)/%.o, $(SOURCES))

INCLUDES =

all:
	$(COMPILER) $(CFLAGS) $(INCLUDES) -c $(SOURCES) -o $(OBJECTS)

.PHONY: all