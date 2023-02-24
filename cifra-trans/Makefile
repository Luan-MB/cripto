# Luan Machado Bernardt | GRR20190363

PROG = cifra
OBJS = cifra.py

.PHONY: clean purge all

all: $(PROG)

$(PROG): $(OBJS)
	cp $^ $@
	chmod +x $@

clean:
	@rm $(PROG)