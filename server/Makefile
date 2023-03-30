CC := g++
CFLAGS := std=gnu++1y
INCLUDE := ./include
SRC := $(wildcard ./src/*.cpp)
NAME := libserver.so
LIBS := -lpthread

$(NAME) : $(SRC)
	$(CC) -I$(INCLUDE) -fPIC -shared -o $@ $(SRC) $(LIBS)