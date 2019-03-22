BIN=./bin/
LIB=./lib/
INC=./include/
SOURCE=./src/
CC=g++
CFLAGS=-I$(INC)
LDFLAGS=-L$(LIB) -Wl,-rpath,$(LIB) -g
LDSHAREDFLAGS=-fPIC -shared
TEST=./test/
LIST=$(LIB)libassignment-01 $(BIN)assignment-01 # $(LIB)libassignment-02 $(BIN)assignment-02

all: $(LIST)

$(LIB)%: $(SOURCE)%.cpp
	$(CC) -o $@.so $< $(CFLAGS) $(LDFLAGS) $(LDSHAREDFLAGS)

$(BIN)%: $(TEST)%.cpp $(LIB)lib%.so
	$(CC) -o $@ $< $(CFLAGS) $(LDFLAGS) -l$*

clean:
	rm $(BIN)*
	rm $(LIB)*
