CXX = g++
CXXFLAGS = -std=c++11 -Wall -Wextra -g

TARGET = test_hashmap
SOURCES = test_hashmap.cpp

$(TARGET): $(SOURCES) HashMap.hpp
	$(CXX) $(CXXFLAGS) -o $(TARGET) $(SOURCES)

clean:
	rm -f $(TARGET)

run: $(TARGET)
	./$(TARGET)

.PHONY: clean run 