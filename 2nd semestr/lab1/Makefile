DEPS=../utils.c
EXECUTABLE=$(shell basename "$(shell PWD)")

all: run

$(EXECUTABLE): $(EXECUTABLE).c
	gcc $(DEPS) $? -o $@

run: $(EXECUTABLE)
	./$(EXECUTABLE)
