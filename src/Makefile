CC = gcc
CFLAGS=-I. -g
DEPS = 
OBJ = proxy.o proxy_util.o
FLAGS = -g -Wall
default: all

all: proxy

%.o: %.c $(DEPS)
	$(CC) $(FLAGS) -c -o $@ $< $(CFLAGS)

proxy: $(OBJ)
	$(CC) -o $@ $^ $(CFLAGS)

clean:
	rm -f *~ *.o *.log proxy

