NAME = convex_hull
TEST_NAME = convex_hull_test
CC = g++
SRC_DIR = ./src
INC_DIR = ./include
LIB_DIR = $(INC_DIR)/lib
BIN_DIR = ./bin
OBJ_DIR = ./obj
CFLAGS = --std=c++2a -O0 -Wall -g
TEST_DIR = $(SRC_DIR)/test
EXE = $(BIN_DIR)/$(NAME)
EXE_TEST = $(BIN_DIR)/$(TEST_NAME)

OBJS = \
	$(OBJ_DIR)/Sort.o \
	$(OBJ_DIR)/MergeSort.o \
	$(OBJ_DIR)/InsertionSort.o \
	$(OBJ_DIR)/RadixSort.o \
	$(OBJ_DIR)/Point.o \
	$(OBJ_DIR)/GrahamScan.o \
	$(OBJ_DIR)/JarvisMarch.o

TEST_OBJS = \
	$(OBJ_DIR)/TestLinkedList.o

all: mkdir $(EXE)

run: all
	$(EXE) $(ARGS)

mkdir:
	mkdir -p $(BIN_DIR)
	mkdir -p $(OBJ_DIR)

$(EXE): $(OBJ_DIR)/$(NAME).o $(OBJS) 
	$(CC) $(CFLAGS) $< $(OBJS) -o $@

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.cpp $(INC_DIR)/%.hpp
	$(CC) -c $(CFLAGS) $< -I $(INC_DIR) -o $@

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.cpp
	$(CC) -c $(CFLAGS) $< -I $(INC_DIR) -o $@ 

test: mkdir $(TEST_OBJS) $(EXE_TEST)

run_test: test
	$(EXE_TEST)

$(EXE_TEST): $(OBJ_DIR)/$(TEST_NAME).o $(OBJS) $(TEST_OBJS)
	$(CC) $(CFLAGS) $< $(OBJS) $(TEST_OBJS) -o $(EXE_TEST)

$(OBJ_DIR)/%.o: $(TEST_DIR)/%.cpp
	$(CC) -c $(CFLAGS) $< -I $(INC_DIR) -I $(LIB_DIR) -o $@

$(OBJ_DIR)/%.o: $(TEST_DIR)/%.cpp
	$(CC) -c $(CFLAGS) $< -I $(INC_DIR) -I $(LIB_DIR) -o $@

clean:
	rm -f $(OBJ_DIR)/*
	rm -f $(EXE)
	rm -f $(EXE_TEST)