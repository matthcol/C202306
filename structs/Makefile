APP=app
OBJS = smartarray.o matrixio.o functional.o main.o
CFLAGS += -Wall -g1 -O0
# LDFLAGS += -lm
CC = gcc

all: $(APP)

$(APP): $(OBJS)
	$(CC) -o $@ $^ $(LDFLAGS)

%.o: %.c
	$(CC) -c $(CFLAGS) -o $@ $<

main.o: smartarray.h matrixio.h functional.h
smartarray.o: smartarray.h
matrixio.o: matrixio.h smartarray.h 
functional.o: functional.h

clean:
	rm -f $(APP) $(OBJS)

