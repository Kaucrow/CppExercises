a: main.o conversions.o
	g++ main.o conversions.o -o a

main.o: main.cpp
	g++ -c main.cpp

conversions.o: conversions.cpp
	g++ -c conversions.cpp

clean:
	del /s *.o