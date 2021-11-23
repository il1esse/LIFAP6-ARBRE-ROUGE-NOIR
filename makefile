all: bin/main.ex bin/mainperfABR.ex bin/mainperfANR.ex

bin/main.ex: obj/main.o obj/element.o obj/abr.o obj/anr.o
	g++ -ggdb obj/main.o obj/element.o obj/abr.o obj/anr.o -o bin/main.ex

bin/mainperfABR.ex: obj/mainperfABR.o obj/element.o obj/abr.o
	g++ -ggdb obj/mainperfABR.o obj/element.o obj/abr.o -o bin/mainperfABR.ex

bin/mainperfANR.ex: obj/mainperfANR.o obj/element.o obj/anr.o
	g++ -ggdb obj/mainperfANR.o obj/element.o obj/anr.o -o bin/mainperfANR.ex

obj/main.o: src/main.cpp src/element.h src/abr.h src/anr.h src/collection.h
	g++ -ggdb -Wall -c src/main.cpp -o obj/main.o

obj/anr.o : src/anr.cpp src/anr.h
	g++ -ggdb -Wall -c src/anr.cpp -o obj/anr.o

obj/abr.o : src/abr.cpp src/abr.h
	g++ -ggdb -Wall -c src/abr.cpp -o obj/abr.o

obj/mainperfABR.o : src/mainperfABR.cpp src/element.h src/abr.h
	g++ -ggdb -Wall -c src/mainperfABR.cpp -o obj/mainperfABR.o

obj/mainperfANR.o : src/mainperfANR.cpp src/element.h src/anr.h
	g++ -ggdb -Wall -c src/mainperfANR.cpp -o obj/mainperfANR.o
	
obj/element.o : src/element.cpp src/element.h
	g++ -ggdb -Wall -c src/element.cpp -o obj/element.o

clean :
	-rm obj/*.o 
	-rm bin/*.ex

