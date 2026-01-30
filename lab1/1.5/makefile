CXX = g++
FLAGS = -std=c++17 -Wall -Wextra
TARGET = out
SRC = Fenwicktree.cpp

$(TARGET): $(SRC)
	$(CXX) $(FLAGS) $(SRC) -o $(TARGET)

clean:
ifeq ($(OS),Windows_NT)
	del /f $(TARGET).exe 2>nul || exit 0
else
	rm -f $(TARGET)
endif