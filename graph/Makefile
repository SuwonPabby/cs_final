CXX = g++
CXXFLAGS = -std=c++11 -Wall -Wextra -g

TARGET = test_graph
SOURCES = test_graph.cpp

$(TARGET): $(SOURCES) Graph.hpp
	$(CXX) $(CXXFLAGS) -o $(TARGET) $(SOURCES)

clean:
	rm -f $(TARGET)

run: $(TARGET)
	./$(TARGET)

.PHONY: clean run 