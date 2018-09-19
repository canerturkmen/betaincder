CC ?= gcc
CFLAGS ?= -g -Wall -O3

all: test.c digamma.c
	$(CC) $(CFLAGS) test.c digamma.c beta.c -lm

clean:
	$(RM) $(TARGET)
