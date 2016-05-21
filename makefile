objects = test_w.o dict.o counter.o beidanci.o user.o

test_w : $(objects)
	g++ -o test_w $(objects) -std=c++11 -fexec-charset=GBK -finput-charset=GBK

test_w.o : test_w.cpp beidanci.h counter.h dict.h word.h
	g++ -c test_w.cpp -std=c++11 -fexec-charset=GBK -finput-charset=GBK

dict.o : dict.cpp dict.h word.h
	g++ -c dict.cpp -std=c++11 -fexec-charset=GBK -finput-charset=GBK

counter.o : counter.cpp counter.h dict.h word.h
	g++ -c counter.cpp -std=c++11 -fexec-charset=GBK -finput-charset=GBK

beidanci.o : beidanci.h beidanci.cpp counter.h dict.h word.h command.h
	g++ -c beidanci.cpp -std=c++11 -fexec-charset=GBK -finput-charset=GBK
user.o : user.h user.cpp dict.h history.h
	g++ -c user.cpp -std=c++11 -fexec-charset=GBK -finput-charset=GBK

.PHONY : clean
clean : 
	del $(objects)