EXEC = assignment7
CPP = g++
CFLAGS = -c

$(EXEC): Assignment7.o Graph.o LinkedList.o Stack.o
	$(CPP) Assignment7.o Graph.o LinkedList.o Stack.o -o $(EXEC)

Assignment7.o: Assignment7.cpp
	$(CPP) $(CFLAGS) Assignment7.cpp -o Assignment7.o

Graph.o: Graph.cpp Graph.h LinkedList.h Stack.h
	$(CPP) $(CFLAGS) Graph.cpp -o Graph.o

LinkedList.o: LinkedList.cpp LinkedList.h
	$(CPP) $(CFLAGS) LinkedList.cpp -o LinkedList.o

Stack.o: Stack.cpp Stack.h LinkedList.h
	$(CPP) $(CFLAGS) Stack.cpp -o Stack.o

clean:
	rm *.o $(EXEC)