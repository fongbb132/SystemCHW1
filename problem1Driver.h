#include "systemc.h"
SC_MODULE(problem1Driver) {
	sc_out<bool> load1, load2;
	sc_out<bool> dec1, dec2;

	sc_out<sc_uint<8>> in1, in2, in3; 
	
	void process();
	SC_CTOR(problem1Driver) {
		SC_THREAD(process);
	}
};