EXEC = assignment8
CPP = g++
CFLAGS = -c

$(EXEC): Assignment8.o Graph.o LinkedList.o Stack.o
	$(CPP) Assignment8.o Graph.o LinkedList.o Stack.o -o $(EXEC)

Assignment8.o: Assignment8.cpp
	$(CPP) $(CFLAGS) Assignment8.cpp -o Assignment8.o

Graph.o: Graph.cpp Graph.h LinkedList.h Stack.h
	$(CPP) $(CFLAGS) Graph.cpp -o Graph.o

LinkedList.o: LinkedList.cpp LinkedList.h
	$(CPP) $(CFLAGS) LinkedList.cpp -o LinkedList.o

Stack.o: Stack.cpp Stack.h LinkedList.h
	$(CPP) $(CFLAGS) Stack.cpp -o Stack.o

clean:
	rm *.o $(EXEC)