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
	buffer.o\
	main.o\
	mthread.o\
	global.o\
	mserver.o\
	
OBJECTS_DEBUG=\
	buffer.od\
	main.od\
	mthread.od\
	global.od\
	mserver.od\
	
################################################################################
### Project Files ##############################################################
################################################################################
	
all: $(OBJECTS)
	$(CPP_LINKER) mserver $(OBJECTS) $(LIBS)
buffer.o: ./buffer.cpp
	$(CPP) buffer.o ./buffer.cpp
main.o: ./main.cpp\
	./global.h\
	./MThread.h
	$(CPP) main.o ./main.cpp
mthread.o: ./mthread.cpp\
	./global.h\
	./MThread.h
	$(CPP) mthread.o ./mthread.cpp
global.o: ./global.cpp\
	./global.h
	$(CPP) global.o ./global.cpp
mserver.o: ./mserver.cpp\
	./global.h
	$(CPP) mserver.o ./mserver.cpp
	
debug: $(OBJECTS_DEBUG)
	$(CPP_LINKER_DEBUG) mserver $(OBJECTS_DEBUG) $(LIBS)
buffer.od: ./buffer.cpp
	$(CPP_DEBUG) buffer.od ./buffer.cpp
main.od: ./main.cpp\
	./global.h\
	./MThread.h
	$(CPP_DEBUG) main.od ./main.cpp
mthread.od: ./mthread.cpp\
	./global.h\
	./MThread.h
	$(CPP_DEBUG) mthread.od ./mthread.cpp
global.od: ./global.cpp\
	./global.h
	$(CPP_DEBUG) global.od ./global.cpp
mserver.od: ./mserver.cpp\
	./global.h
	$(CPP_DEBUG) mserver.od ./mserver.cpp
	
install:
	echo 'install command not set'
	
clean:
	rm -f mserver mserver
	rm -rf *.o *.od
