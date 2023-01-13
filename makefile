# makefile for windows, executed by powershell
# Note that you need to modify the path of CC and ALLEGRO_PATH
CC = "g++"
CFLAGS = -Wall -std=c++17 -O2 -v
ALLEGRO_PATH = allegro
ALLEGRO_FLAGS = -I$(ALLEGRO_PATH)/include -L$(ALLEGRO_PATH)/lib/liballegro_monolith.dll.a
DLL_PATH = $(ALLEGRO_PATH)/lib/liballegro_monolith.dll.a

OUT:= game
SOURCE = Main.cpp GameWindow.cpp Buttom.cpp Bird.cpp Pipe.cpp Title.cpp
OBJ = Main.o GameWindow.o Buttom.o Bird.o Pipe.o Title.o

all:
	$(CC) -c -g $(CFLAGS) $(SOURCE) $(ALLEGRO_FLAGS)
	$(CC) $(CFLAGS) -o $(OUT) $(OBJ) $(ALLEGRO_FLAGS) $(DLL_PATH)
	del $(OBJ)

.PHONY:clean
clean:
	del $(OUT)