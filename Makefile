CXX = g++
CXXFLAGS = -std=c++20 -Iinclude -g

TARGET = main.exe

SRCS = main.cpp $(wildcard src/**/*.cpp) $(wildcard src/*.cpp)

OBJS = $(SRCS:.cpp=.o)

all: $(TARGET)

$(TARGET): $(OBJS)
	$(CXX) $(OBJS) -o $(TARGET)

%.o: %.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

clean:
	del /s /q *.o $(TARGET)