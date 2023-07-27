CXX := g++
CXX_FLAGS := -Wall -Wextra -std=c++17 -ggdb


BIN := bin
SRC := src
INCLUDE := "include"
SFML_INCLUDE := "C:\SFML-2.5.1\include"
LIB := "C:\SFML-2.5.1\lib"
LIBARIES :=  -lsfml-graphics -lsfml-window -lsfml-system -lopengl32
EXECUTABLE := main.exe # You can change it according to your liking

all : build clean

build : compile link

compile:
	g++ -c $(SRC)/*.cpp -I$(SFML_INCLUDE) -I$(INCLUDE)	

link:
	g++ *.o -o $(BIN)/$(EXECUTABLE) -L$(LIB) $(LIBARIES)

run:
	cd ./bin

clean:
	del *.o