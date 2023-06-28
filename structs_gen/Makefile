APP=app
OBJS = smartarray.o main.o
CFLAGS += -Wall -g1 -O0
# LDFLAGS += -lm
CC = gcc

all: $(APP)

$(APP): $(OBJS)
	$(CC) -o $@ $^ $(LDFLAGS)

%.o: %.c
	$(CC) -c $(CFLAGS) -o $@ $<

main.o: smartarray.h
smartarray.o: smartarray.h

clean:
	rm -f $(APP) $(OBJS)

