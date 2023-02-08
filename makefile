OBJS_EXEMPLE = $(OBJ_DIR)/mainExemple.o $(OBJ_DIR)/Pixel.o $(OBJ_DIR)/Image.o
OBJS_TEST = $(OBJ_DIR)/mainTest.o $(OBJ_DIR)/Pixel.o $(OBJ_DIR)/Image.o

FLAGS = -ggdb -Wall
CC = g++
SRC_DIR = ./src
BIN_DIR = ./bin
OBJ_DIR = ./obj

all: $(BIN_DIR)/exemple $(BIN_DIR)/test

$(BIN_DIR)/exemple: $(OBJS_EXEMPLE)
	$(CC) $(FLAGS) $(OBJS_EXEMPLE) -o $(BIN_DIR)/exemple 

$(BIN_DIR)/test: $(OBJS_TEST)
	$(CC) $(FLAGS) $(OBJS_TEST) -o $(BIN_DIR)/test 

$(OBJ_DIR)/mainExemple.o: $(SRC_DIR)/mainExemple.cpp $(SRC_DIR)/Image.h $(SRC_DIR)/Pixel.h
	$(CC) $(FLAGS) -c $(SRC_DIR)/mainExemple.cpp -o $(OBJ_DIR)/mainExemple.o

$(OBJ_DIR)/mainTest.o: $(SRC_DIR)/mainTest.cpp $(SRC_DIR)/Image.h $(SRC_DIR)/Pixel.h
	$(CC) $(FLAGS) -c $(SRC_DIR)/mainTest.cpp -o $(OBJ_DIR)/mainTest.o
	
$(OBJ_DIR)/Image.o: $(SRC_DIR)/Image.cpp $(SRC_DIR)/Image.h $(SRC_DIR)/Pixel.h
	$(CC) $(FLAGS) -c $(SRC_DIR)/Image.cpp -o $(OBJ_DIR)/Image.o
	
$(OBJ_DIR)/Pixel.o: $(SRC_DIR)/Pixel.cpp $(SRC_DIR)/Pixel.h
	$(CC) $(FLAGS) -c $(SRC_DIR)/Pixel.cpp -o $(OBJ_DIR)/Pixel.o

clean:
	rm -f $(OBJS_EXEMPLE) $(OBJS_TEST) $(BIN_DIR)/exemple $(BIN_DIR)/test
