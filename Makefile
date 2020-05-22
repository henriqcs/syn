IDIR=include
CC=gcc
CFLAGS=-I$(IDIR)

ODIR=obj
SDIR=src

_DEPS = token.h syn.h
DEPS=$(patsubst %,$(IDIR)/%,$(_DEPS))

_OBJ = token.o syn.o main.o
OBJ=$(patsubst %,$(ODIR)/%,$(_OBJ))

$(ODIR)/%.o: $(SDIR)/%.c $(DEPS)
	$(CC) -c -o $@ $< $(CFLAGS)

syn: $(OBJ)
	$(CC) -o $@ $^

.PHONY: clean check

clean:
	rm -f $(ODIR)/*.o $(IDIR)/*~ *~ core

check: syn
	@test/check.sh
