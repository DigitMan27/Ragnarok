CXX_FLAGS = -std=c++11

PROGRAM = Bragi

OBJS = Bragi.o

SRC = Bragi.cpp

HEADER = Bragi.h

CXX = g++

all:    $(PROGRAM)

$(PROGRAM):   $(OBJS)
	$(CXX) $(CXX_FLAGS) -o $(PROGRAM) $(OBJS)

$(OBJS): $(SRC) $(HEADER)
	$(CXX) $(CXX_FLAGS) -c $(SRC)

clean: 
	rm -f $(PROGRAM) $(OBJS)

