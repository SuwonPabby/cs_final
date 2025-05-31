CXX = g++
CXXFLAGS = -std=c++11 -Wall -Wextra -g

TARGET = test_vector
SOURCES = test_vector.cpp

$(TARGET): $(SOURCES) smcVector.hpp
	$(CXX) $(CXXFLAGS) -o $(TARGET) $(SOURCES)

clean:
	rm -f $(TARGET)

run: $(TARGET)
	./$(TARGET)

.PHONY: clean run 