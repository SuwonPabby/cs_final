CXX = g++
CXXFLAGS = -std=c++11 -Wall -Wextra -g

TARGET = test_singlylist
SOURCES = test_singlylist.cpp

$(TARGET): $(SOURCES) SinglyList.hpp
	$(CXX) $(CXXFLAGS) -o $(TARGET) $(SOURCES)

clean:
	rm -f $(TARGET)

run: $(TARGET)
	./$(TARGET)

.PHONY: clean run 