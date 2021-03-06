#include "systemc.h"

SC_MODULE(problem1) {
	sc_in<bool> clock;
	sc_in<bool> dec1, dec2;
	sc_in<bool> load1, load2;
	sc_in<sc_uint<8>>  in1, in2, in3;

	sc_out<bool> ended ; 
	sc_out<sc_uint<8>> count1, count2; 
	sc_uint<8> lc1, lc2; 
	void process();
	SC_CTOR(problem1) {

		SC_METHOD(process);

		sensitive << clock << load1 << dec1 << in1 << load2 << dec2 << in2;

	}
};
