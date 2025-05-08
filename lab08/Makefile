CXX = g++
CXXFLAGS = -std=c++17 -Wall -Wextra -O2 -MMD -MP
TARGET = main

SRC = $(wildcard *.cpp)
OBJ = $(SRC:.cpp=.o)
DEPS = $(SRC:.cpp=.d)

all: $(TARGET)

$(TARGET): $(OBJ)
	$(CXX) $(CXXFLAGS) -o $@ $^

%.o: %.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

clean:
	rm -f $(OBJ) $(TARGET) $(DEPS)

-include $(DEPS)

.PHONY: all clean
