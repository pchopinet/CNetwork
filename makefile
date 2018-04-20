CC=gcc
CFLAGS=-Wall -Wextra -pedantic -I.
LDFLAGS= -lpthread
PATHSRC=src/
PATHOBJ=obj/
PATHBIN=bin/

all: TCPserver TCPclient

TCPserver: $(addprefix $(PATHOBJ), TCPserver.o TCPutil.o testTCPserver.o)
	$(CC) $^ $(LDFLAGS) -o $(PATHBIN)$@


TCPclient : $(addprefix $(PATHOBJ), TCPclient.o TCPutil.o testTCPclient.o)
	$(CC) $^ $(LDFLAGS) -o $(PATHBIN)$@

test:
	$(CC) $^ $(LDFLAGS) -o $(PATHBIN)$@

lib : TCPserver.o TCPclient.o TCPutil.o
	ar rcs lib/Clibnetwork.a $^

$(PATHOBJ)%.o: $(PATHSRC)%.c
	$(CC) $< $(CFLAGS) -c -o $@

clean:
	rm -rf $(PATHBIN)*
	rm -rf $(PATHOBJ)*.o
