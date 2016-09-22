#include "problem1Driver.h"

void problem1Driver::process() {


	in1.write(0b0001111);
	in2.write(0b1000101);
	in3.write(0b0000011);

	load1.write(1);
	load2.write(1);

	wait(10, SC_NS);

	load1.write(0);
	load2.write(0);

	dec1.write(1);
	dec2.write(1);

	wait(10, SC_NS);

	wait(10, SC_NS);
	for (int i = 0; i < 5; i++) {
		wait(10, SC_NS);
	}

}
