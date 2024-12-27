# Compiler and flags
CXX = g++
CXXFLAGS = -std=c++17 -Wall -Wextra -g

# Source files and object files
SRCS = Cards.cpp Game.cpp Player.cpp Project.cpp
OBJS = $(SRCS:.cpp=.o)

# Header files
HEADERS = Cards.H Game.H Player.H

# Executable
TARGET = blackjack

# Default target
all: $(TARGET)

# Linking target
$(TARGET): $(OBJS)
	$(CXX) $(CXXFLAGS) -o $@ $^

# Compile .cpp files to .o files
%.o: %.cpp $(HEADERS)
	$(CXX) $(CXXFLAGS) -c $< -o $@

# Clean build files
clean:
	rm -f $(OBJS) $(TARGET)

# Phony targets
.PHONY: all clean