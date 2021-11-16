main.ex: main.o element.o abr.o
	g++ main.o element.o abr.o -o main.ex

main.o : main.cpp element.h  abr.h
	g++ -Wall -c main.cpp

element.o : element.cpp element.h
	g++ -Wall -c element.cpp

abr.o : abr.cpp abr.h
	g++ -Wall -c abr.cpp

clean :
	-rm *.o 

veryclean : clean 
	-rm *.ex
