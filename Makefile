CC=gcc
CFLAGS=-Wall

all: affinity-cmd affinity-fork

affinity-cmd:
	$(CC) $(CFLAGS) affinity-cmd.c -o affinity-cmd

affinity-fork:
	$(CC) $(CFLAGS) affinity-fork.c -o affinity-fork

clean:
	rm affinity-cmd
	rm affinity-fork


