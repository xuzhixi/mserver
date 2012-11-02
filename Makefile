################################################################################
### Compilers ##################################################################
################################################################################
	
INCLUDEPATH=
LIBS=-lpthread -lrt -L/usr/lib/mysql -lmysqlclient -L/root/kuaipan/program/cpp/ops -lops
	
CC=gcc -c $(INCLUDEPATH) -W -Wall -Wpointer-arith -pipe -D_REENTRANT -O3 -o
CC_DEBUG=gcc -g -c $(INCLUDEPATH) -W -Wall -Wpointer-arith -pipe -D_REENTRANT -o
CC_LINKER=gcc $(INCLUDEPATH) -W -Wall -Wpointer-arith -pipe -D_REENTRANT -O3 -o
CC_LINKER_DEBUG=gcc -g $(INCLUDEPATH) -W -Wall -Wpointer-arith -pipe -D_REENTRANT -o
	
CPP=g++ -c $(INCLUDEPATH) -W -Wall -Wpointer-arith -pipe -D_REENTRANT -O3 -o
CPP_DEBUG=g++ -g -c $(INCLUDEPATH) -W -Wall -Wpointer-arith -pipe -D_REENTRANT -o
CPP_LINKER=g++ $(INCLUDEPATH) -W -Wall -Wpointer-arith -pipe -D_REENTRANT -O3 -o
CPP_LINKER_DEBUG=g++ -g $(INCLUDEPATH) -W -Wall -Wpointer-arith -pipe -D_REENTRANT -o
	
AR=ar  cqs
AR_DEBUG=ar  cqs
	
################################################################################
### Generated object files #####################################################
################################################################################
	
OBJECTS=\
	MServer.o\
	buffer.o\
	global.o\
	AnalysePackTask.o\
	SendThread.o\
	SendThreadPool.o\
	Online.o\
	MThread.o\
	main.o\
	
OBJECTS_DEBUG=\
	MServer.od\
	buffer.od\
	global.od\
	AnalysePackTask.od\
	SendThread.od\
	SendThreadPool.od\
	Online.od\
	MThread.od\
	main.od\
	
################################################################################
### Project Files ##############################################################
################################################################################
	
all: $(OBJECTS)
	$(CPP_LINKER) mserver $(OBJECTS) $(LIBS)
MServer.o: ./MServer.cpp\
	./global.h\
	./MServer.h\
	./Buffer.h\
	./Online.h
	$(CPP) MServer.o ./MServer.cpp
buffer.o: ./buffer.cpp\
	./global.h\
	./Online.h\
	./Buffer.h
	$(CPP) buffer.o ./buffer.cpp
global.o: ./global.cpp\
	./global.h\
	./Online.h
	$(CPP) global.o ./global.cpp
AnalysePackTask.o: ./AnalysePackTask.cpp\
	./global.h\
	./Online.h
	$(CPP) AnalysePackTask.o ./AnalysePackTask.cpp
SendThread.o: ./SendThread.cpp\
	./SendThread.h
	$(CPP) SendThread.o ./SendThread.cpp
SendThreadPool.o: ./SendThreadPool.cpp\
	./SendThreadPool.h\
	./SendThread.h
	$(CPP) SendThreadPool.o ./SendThreadPool.cpp
Online.o: ./Online.cpp\
	./Online.h
	$(CPP) Online.o ./Online.cpp
MThread.o: ./MThread.cpp\
	./MThread.h\
	./global.h\
	./MServer.h\
	./Online.h
	$(CPP) MThread.o ./MThread.cpp
main.o: ./main.cpp\
	./MThread.h\
	./global.h\
	./Online.h
	$(CPP) main.o ./main.cpp
	
debug: $(OBJECTS_DEBUG)
	$(CPP_LINKER_DEBUG) mserver $(OBJECTS_DEBUG) $(LIBS)
MServer.od: ./MServer.cpp\
	./global.h\
	./MServer.h\
	./Buffer.h\
	./Online.h
	$(CPP_DEBUG) MServer.od ./MServer.cpp
buffer.od: ./buffer.cpp\
	./global.h\
	./Online.h\
	./Buffer.h
	$(CPP_DEBUG) buffer.od ./buffer.cpp
global.od: ./global.cpp\
	./global.h\
	./Online.h
	$(CPP_DEBUG) global.od ./global.cpp
AnalysePackTask.od: ./AnalysePackTask.cpp\
	./global.h\
	./Online.h
	$(CPP_DEBUG) AnalysePackTask.od ./AnalysePackTask.cpp
SendThread.od: ./SendThread.cpp\
	./SendThread.h
	$(CPP_DEBUG) SendThread.od ./SendThread.cpp
SendThreadPool.od: ./SendThreadPool.cpp\
	./SendThreadPool.h\
	./SendThread.h
	$(CPP_DEBUG) SendThreadPool.od ./SendThreadPool.cpp
Online.od: ./Online.cpp\
	./Online.h
	$(CPP_DEBUG) Online.od ./Online.cpp
MThread.od: ./MThread.cpp\
	./MThread.h\
	./global.h\
	./MServer.h\
	./Online.h
	$(CPP_DEBUG) MThread.od ./MThread.cpp
main.od: ./main.cpp\
	./MThread.h\
	./global.h\
	./Online.h
	$(CPP_DEBUG) main.od ./main.cpp
	
install:
	echo 'install command not set'
	
clean:
	rm -f mserver mserver
	rm -rf *.o *.od
