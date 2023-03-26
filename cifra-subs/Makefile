# Luan Machado Bernardt | GRR20190363

CC     = g++
CFLAGS = -Wall #-Wshadow

PROG = main
OBJS = Criptografia.o main.o

.PHONY: clean purge all

all: $(PROG)

$(PROG): $(OBJS)
	$(CC) $(CFLAGS) -o  $@ $^

clean:
	@rm -f *.o

purge:   
	@rm -f $(PROG)