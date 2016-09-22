#include "systemc.h"

SC_MODULE(problem2) {
	sc_in<bool> clk, reset, clear;
	sc_in<sc_uint<12>> inData;
	
	sc_out<sc_uint<4>> payload;
	sc_out<sc_uint<8>> count;
	sc_out<sc_uint<8>> error;

	sc_uint<8> countInt = 0; 
	sc_uint<8> errorInt = 0;

	void process();

	SC_CTOR(problem2) {
		SC_METHOD(process);
		sensitive << clk << reset << clear << inData;
		
	}
};
