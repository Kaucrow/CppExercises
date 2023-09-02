a: main.o date_class.o
	g++ main.o date_class.o -o a

main.o: main.cpp
	g++ -c main.cpp

date_class.o: date_class.cpp
	g++ -c date_class.cpp

clean:
	del /s *.o