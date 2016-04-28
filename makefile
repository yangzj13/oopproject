all : test

test : test.cpp word.h dict.h
	g++ -o test dict.cpp test.cpp -std=c++11

clean : 
	rm *.out
	rm *.exe

