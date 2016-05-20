objects = test.o dict.o counter.o beidanci.o user.o

test : $(objects)
	g++ -o test $(objects) -std=c++11

test.o : test.cpp beidanci.h counter.h dict.h word.h
	g++ -c test.cpp -std=c++11

dict.o : dict.cpp dict.h word.h
	g++ -c dict.cpp -std=c++11

counter.o : counter.cpp counter.h dict.h word.h
	g++ -c counter.cpp -std=c++11

beidanci.o : beidanci.h beidanci.cpp counter.h dict.h word.h
	g++ -c beidanci.cpp -std=c++11
user.o : user.h user.cpp dict.h history.h
	g++ -c user.cpp -std=c++11

.PHONY : clean
clean : 
	del $(objects)