#include "systemc.h"
SC_MODULE(problem2_driver) {
	sc_out<bool> clear; 
	sc_out<sc_uint<12>> inData;

	void prc_driver();

	SC_CTOR(problem2_driver) {
		SC_THREAD(prc_driver);
	}
};


