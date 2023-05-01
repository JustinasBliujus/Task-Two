main: funkcijos.o generator.o analize.o
	g++ -O2 -o main main.cpp funkcijos.cpp generator.cpp analize.cpp
clean:
	del *.o main
