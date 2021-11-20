all: mainabr.ex mainperf.ex mainanr.ex

mainabr.ex: mainabr.o element.o abr.o
	g++ -ggdb mainabr.o element.o abr.o -o mainabr.ex
	
mainanr.ex: mainanr.o element.o anr.o
	g++ -ggdb mainanr.o element.o anr.o -o mainanr.ex

mainperf.ex: mainperf.o element.o anr.o
	g++ -ggdb mainperf.o element.o anr.o -o mainperf.ex

mainabr.o : mainabr.cpp element.h abr.h
	g++ -ggdb -Wall -c mainabr.cpp

mainanr.o : mainanr.cpp element.h anr.h
	g++ -ggdb -Wall -c mainanr.cpp

mainperf.o : mainperf.cpp element.h anr.h
	g++ -ggdb -Wall -c mainperf.cpp

element.o : element.cpp element.h
	g++ -ggdb -Wall -c element.cpp

anr.o : anr.cpp anr.h
	g++ -ggdb -Wall -c anr.cpp

abr.o : abr.cpp abr.h
	g++ -ggdb -Wall -c abr.cpp
	

clean :
	-rm *.o 
	-rm *.ex
veryclean : clean 
	-rm *.ex
