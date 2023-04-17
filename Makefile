main: v05funkcijos.o generator.o analize.o
	g++ -o3 -o main v05.cpp v05funkcijos.cpp generator.cpp analize.cpp
v04funkcijos:
	g++ -o3 -c v04funkcijos.cpp
generator:
	g++ -o3 -c generator.cpp
analize:
	g++ -o3 -c analize.cpp
clean:
	del *.o main