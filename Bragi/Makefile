CXX_FLAGS = -std=c++11

PROGRAM = Bragi

OBJS = Bragi.o

MAIN_O = Main.o

SRC = Bragi.cpp

MAIN = Main.cpp

HEADER = Bragi.h

CXX = g++

all:    $(PROGRAM)

$(PROGRAM):   $(OBJS) $(MAIN_O)
	$(CXX) $(CXX_FLAGS) -o $(PROGRAM) $(OBJS) $(MAIN_O)

$(MAIN_O):  $(MAIN)
	$(CXX)  $(CXX_FLAGS) -c $(MAIN)

$(OBJS): $(SRC) $(HEADER)
	$(CXX) $(CXX_FLAGS) -c $(SRC)

clean:
	rm -f $(PROGRAM) $(OBJS) $(MAIN_O)
