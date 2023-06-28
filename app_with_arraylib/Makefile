APP=app
OBJS = main.o
CFLAGS += -g1 -O0
LIBDIRFLAGS = -L $(HOME)/local/lib
INCLUDEDIRFLAGS = -I $(HOME)/local/include 
LDFLAGS += -larray
CC = gcc
LD = gcc

all: $(APP)

$(APP): $(OBJS)
	$(LD) -o $@ $^ $(LIBDIRFLAGS) $(LDFLAGS)

%.o: %.c
	$(CC) -c $(CFLAGS) $(INCLUDEDIRFLAGS) -o $@ $<

clean:
	rm -f $(APP) $(OBJS)

