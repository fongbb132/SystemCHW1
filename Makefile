SYSTEMC_HOME    = /usr/local/systemc-2.3.1
TARGET_ARCH     = linux64

SYSTEMC_BUS_DIR = $(SYSTEMC_HOME)/simple_bus
SYSTEMC_INC_DIR = $(SYSTEMC_HOME)/include
SYSTEMC_LIB_DIR = $(SYSTEMC_HOME)/lib-$(TARGET_ARCH)

# LIBTOOL Setting
SHELL           = /bin/bash
LIBTOOL_DIR     = /home/ka/Desktop/testing/libtool
LIBTOOL         = $(SHELL) $(LIBTOOL_DIR)/libtool

GXX             = g++ -std=c++11 
GCC             = gcc
LD              = g++

FLAGS           = -g -Wall -pedantic -Wno-long-long \
                 -DSC_INCLUDE_DYNAMIC_PROCESSES -fpermissive \
                 -I$(SYSTEMC_INC_DIR) 
LDFLAGS         = -L. -L$(SYSTEMC_LIB_DIR) -lsystemc -lm

SRCS = problem1.cpp problem1Driver.cpp
OBJS=$(SRCS:.cpp=.o)

# main
main: $(OBJS)
	$(GXX) -o $@ $(OBJS) $(LDFLAGS)

.cpp.o:
	$(GXX) -I$(SYSTEMC_INC_DIR) -c $< 
 
	$(GXX) -I$(SYSTEMC_INC_DIR) -c $< $(LDFLAGS) 

clean:
	rm -f main *.o *.lo
	rm -rf .libs