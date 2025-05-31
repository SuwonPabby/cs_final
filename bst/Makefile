CXX = g++
CXXFLAGS = -std=c++11 -Wall -Wextra -g

TARGET = test_bst
SOURCES = test_bst.cpp

$(TARGET): $(SOURCES) BST.hpp
	$(CXX) $(CXXFLAGS) -o $(TARGET) $(SOURCES)

clean:
	rm -f $(TARGET)

run: $(TARGET)
	./$(TARGET)

.PHONY: clean run 