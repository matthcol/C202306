APP=app
OBJS = main.o
CFLAGS += -Wall -g1 -O0
LDFLAGS += -lm
CC = gcc

all: $(APP)

$(APP): $(OBJS)
	$(CC) -o $@ $^ $(LDFLAGS)

%.o: %.c
	$(CC) -c $(CFLAGS) -o $@ $<

clean:
	rm -f $(APP) $(OBJS)

