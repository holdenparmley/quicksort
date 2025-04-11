qs: quicksort.o
        g++ -o qs quicksort.o

quicksort.o: quicksort.cpp
        g++ -c quicksort.cpp

clean:
        rm -f qs *.o *-
