LIB=libarray.so
LIB_STATIC=libarray.a
OBJS = array.o
LIB_DIR_INSTALL=$(HOME)/local/lib
CFLAGS += -g1 -O0
LDFLAGS += -lm -shared
CC = gcc
LD = ld
AR = ar


all: $(LIB) $(LIB_STATIC)

$(LIB): $(OBJS)
	$(LD) -o $@ $^ $(LDFLAGS)

$(LIB_STATIC): $(OBJS)
	$(AR) -rcs $@ $^


%.o: %.c
	$(CC) -c $(CFLAGS) -o $@ $<

array.o: array.h

install:
	cp $(LIB) $(LIB_STATIC) $(LIB_DIR_INSTALL)/

clean:
	rm -f $(LIB) $(LIB_STATIC) $(OBJS)

