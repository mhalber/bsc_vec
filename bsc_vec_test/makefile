# Executable name
EXE_NAME = bsc_vec_test.exe

# Useful Directories
BIN_DIR = ./
OUT_DIR = ./

# List of source files
SRCS = main.cpp
OBJS = $(SRCS:%.cpp=$(OUT_DIR)%.o)

# Compile and link options
CC = clang++
WARNINGS = -Wall
CPPFLAGS = -std=c++14 -Os -I. -I../ -ggdb

# Libraries
LIBS = -lm


# Make targets
all: clean bvuTest

bvuTest: $(OBJS)
		$(CC) $(CPPFLAGS) $(OBJS) $(LIBS) -o ${BIN_DIR}${EXE_NAME}

clean:
		rm -f $(OUT_DIR)*.a $(OUT_DIR)*.o ${BIN_DIR}${EXE_NAME}

# Compile command
$(OUT_DIR)%.o: %.cpp
		$(CC) $(WARNINGS) $(CPPFLAGS) -c $< -o $@

# GNU Make: targets that don't build files
.PHONY: all clean
