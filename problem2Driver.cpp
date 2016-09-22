#include "problem2Driver.h"

void problem2_driver::prc_driver() {

	clear = 1; 
	for (int i = 0; i < 20; i++) {
		clear = 0;
		wait(5, SC_NS);
		switch (i) {
		case 3:
			inData = 0x1F1;
			break;
		case 5:
			inData = 0x0E0;
			break;
		case 7:
			inData = 0x171;
			break;
		case 9:
			inData = 0x0E0;
			break;
		default:
			inData = 0;

		}
	}

	clear = 1; 

}
