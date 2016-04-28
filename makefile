all : test

test : test.cpp word.h
	g++ -o test test.cpp -std=c++11

clean : 
	rm *.out
	rm *.exe

