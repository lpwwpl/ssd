CC=g++
CFLAGS=-g -ansi -pedantic
LFLAGS=-L/lib -lwsock32

SERVER-SRC=main.cpp processrequest.cpp buildpage.cpp \
		Date.cpp Advertisement.cpp Client.cpp \
		Listing.cpp Group.cpp \
		Category.cpp CategoryHierarchy.cpp \
		SortBy.cpp CopyByKeyword.cpp \
		buildbidpage.cpp Bid.cpp \
		Shortest.cpp buildpathpage.cpp

SERVER-INC=main.h processrequest.h buildpage.h \
		Date.h Advertisement.h Client.h \
		Listing.h Group.h \
		Category.h CategoryHierarchy.h \
		SortBy.h CopyByKeyword.h \
		buildbidpage.h Bid.h \
		Shortest.h buildpathpage.h

SERVER-OBJ=main.o processrequest.o buildpage.o \
		Date.o Advertisement.o Client.o \
		Listing.o Group.o \
		Category.o CategoryHierarchy.o \
		SortBy.o CopyByKeyword.o \
		buildbidpage.o Bid.o \
		Shortest.o buildpathpage.o

all: server 

server: $(SERVER-INC) $(SERVER-OBJ)
	$(CC) $(SERVER-SRC) $(CFLAGS) $(LFLAGS) -o auction-server.exe

clean: 
	rm *.o
	rm auction-server.exe

%.o: %.cpp
	$(CC) $(CFLAGS) -c $(@:%.o=%.cpp)
