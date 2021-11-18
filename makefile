

main.ex: main.o element.o anr.o
	g++ -ggdb main.o element.o anr.o -o main.ex

main.o : main.cpp element.h  anr.h
	g++ -ggdb -Wall -c main.cpp

mainabr.o : mainabr.cpp element.h  abr.h
	g++ -ggdb -Wall -c mainabr.cpp

element.o : element.cpp element.h
	g++ -ggdb -Wall -c element.cpp

anr.o : anr.cpp anr.h
	g++ -ggdb -Wall -c anr.cpp

abr.o : abr.cpp abr.h
	g++ -ggdb -Wall -c abr.cpp
clean :
	-rm *.o 

veryclean : clean 
	-rm *.ex
