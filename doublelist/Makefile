CXX = g++
CXXFLAGS = -std=c++11 -Wall -Wextra -g

TARGET = test_doublelist
SOURCES = test_doublelist.cpp

$(TARGET): $(SOURCES) DoubleList.hpp
	$(CXX) $(CXXFLAGS) -o $(TARGET) $(SOURCES)

clean:
	rm -f $(TARGET)

run: $(TARGET)
	./$(TARGET)

.PHONY: clean run 