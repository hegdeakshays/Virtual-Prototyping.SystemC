# Christian De Schryver 2014
# Markus Steffes 2015

CC=g++
CFLAGS=-Wall -std=c++0x
LDFLAGS=-I ./polynom -L$(SYSTEMC_LIB_DIR) -lsystemc

all:
	$(CC) $(CFLAGS) $(LDFLAGS) -o main polynom/poly.cpp polyInt.cpp polyInt_tb.cpp main.cpp

dbg:
	$(CC) -v -g $(CFLAGS) $(LDFLAGS) -o main polynom/poly.cpp polyInt.cpp main.cpp

clean:	
	rm -f *.o main Output.bmp *.cpp.*

