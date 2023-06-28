APP=app
OBJS = smartarray.o main.o
CFLAGS += -g1 -O0
# LDFLAGS += -lm
CC = gcc

all: $(APP)

$(APP): $(OBJS)
	$(CC) -o $@ $^ $(LDFLAGS)

%.o: %.c
	$(CC) -c $(CFLAGS) -o $@ $<

main.o: smartarray.h
array.o: smartarray.h

clean:
	rm -f $(APP) $(OBJS)

