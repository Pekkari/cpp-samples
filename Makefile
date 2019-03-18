BIN=./bin/
INC=./include/
SOURCE=./src/
CC=gcc
CFLAGS=-I$(INC)
LIST=$(BIN)assignment.01 $(BIN)assignment.02

all: $(LIST)


$(BIN)%: $(SOURCE)%.cpp
	$(CC) $< $(CFLAGS) -o $@

%: $(SOURCE)%.cpp
	$(CC) $< $(CFLAGS) -o $(BIN)$@

clean:
	rm $(BIN)/*
