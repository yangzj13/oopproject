all : test

test : test.cpp word.h explain.h
	g++ -o test.out test.cpp -std=c++11

clean : 
	rm *.out
