CXX = g++
CXXFLAGS = -Wall

ifdef DEBUG
CXXFLAGS += -g
endif

TARGET = a
OBJ = main.o set.o test_set.o

all: $(TARGET)

$(TARGET): $(OBJ)
	$(CXX) $(OBJ) -o $(TARGET)

main.o: main.cpp set.h
	$(CXX) $(CXXFLAGS) -c main.cpp

set.o: set.cpp set.h
	$(CXX) $(CXXFLAGS) -c set.cpp

test_set.o: test_set.cpp set.h
	$(CXX) $(CXXFLAGS) -c test_set.cpp

clean:
	rm -f $(OBJ) $(TARGET)
