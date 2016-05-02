all : test

test : test.cpp word.h dict.h dict.cpp counter.h counter.cpp
	g++ -o test dict.cpp counter.cpp test.cpp -std=c++11

clean : 
	rm *.out
	rm *.exe

