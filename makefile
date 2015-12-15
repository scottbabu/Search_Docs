# makefile for testing win32
# Dec. 11, 2015
# Scott Cann
# /usr/bin/i686-w64-mingw32-g++ -mwindows main.cpp -o main.exe
# /usr/bin/i686-w64-mingw32-g++ -mwindows  search_docs.cpp -o search_docs.exe
# gcc -shared sqlite3.c -o sqlite3.dll
#  -lsqlite3
# gcc -c sqlite3.c
# g++ -c main.cpp
# g++ -o program main.o sqlite3.o -lpthread -ldl

CPP = /usr/bin/i686-w64-mingw32-g++
CC = /usr/bin/i686-w64-mingw32-gcc
CFLAGS = -mwindows -lpthread # -lsqlite3 
# INCLUDES = -I/usr/include
# -lsqlite3 -ldl
# CCFLAGS=-Wall -W -O2 -Wl,-R/usr/lib/i386-linux-gnu -lsqlite3
CPPFLAGS=-Wall -mwindows -lpthread
GCCFLAGS=-Wall
TARGET = search_docs
LIBRARY=-L /usr/lib/i386-linux-gnu

all: $(TARGET)

.cpp.o:	$*.h $*.cpp
	$(CPP) -c $(CPPFLAGS) $*.cpp

.c.o:
	$(CC) -c $(GCCFLAGS)  $*.c

$(TARGET): $(TARGET).o 
	$(CPP) $(CFLAGS) -o $(TARGET).exe $(TARGET).o 
#sqlite3.o

clean:
	rm $(TARGET).exe
	rm *.o
