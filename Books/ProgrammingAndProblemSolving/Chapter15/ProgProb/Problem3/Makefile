a: main.o sorted_list.o
	g++ main.o sorted_list.o -o a

main.o: main.cpp
	g++ -c main.cpp

sorted_list.o: sorted_list.cpp
	g++ -c sorted_list.cpp
	
clean:
	del /s *.o