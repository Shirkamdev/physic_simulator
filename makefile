.PHONY= clean

CC=g++
OPTIONS= -g -std=gnu++0x
FLAGS= -lncurses
DEBUG= #-D DEBUG
LIBDIR=lib
INCLUDEDIR=include
SALIDA=main
SRC=src/$(SALIDA).cpp
_OBJ= basicWindow.o colorWindow.o
OBJ = $(patsubst %,$(LIBDIR)/%,$(_OBJ))

all: clean simulador

simulador:    $(SRC) $(OBJ)
	$(CC) $(OPTIONS) $(DEBUG) -I$(INCLUDEDIR) $(SRC) $(OBJ) -o $(SALIDA) $(FLAGS)

$(LIBDIR)/%.o : $(LIBDIR)/%.cpp $(INCLUDEDIR)/%.h
	$(CC) $(OPTIONS) $(DEBUG) -c -I$(INCLUDEDIR) -o $@ $< $(FLAGS)

clean:
	rm -f $(OBJ) 