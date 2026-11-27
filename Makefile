CC  = g++
SRC = tokenizer.cpp
OBJ = tokenizer.o
BIN = tokenizer

run: $(BIN)
	./$(BIN)

$(BIN): $(OBJ)
	$(CC) $(OBJ) -o $(BIN) 

$(OBJ): $(SRC)
	$(CC) -c $(SRC)

clean:
	rm $(OBJ) $(BIN)
