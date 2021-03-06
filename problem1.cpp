#include "problem1.h"
#include "problem1Driver.h"


void problem1::process() {
	// ended = 0; 
	if (clock ) {
		bool isTheSame = (count1.read() == count2.read());

		if (load1.read()) {
			lc1 = in1.read();
		}  

		if(lc1 == 0){
			ended.write(1);
		}else if (dec1.read() && !isTheSame) {
			lc1 -= 1; 

		}
		
		if (load2.read()) {
			lc2 = in2.read();
		}

		if(lc2 < in3.read()){
			lc2 = 0;
			ended.write(1);
		}
		else if (dec2.read() && !isTheSame) {
			lc2 -= in3.read();
		}


		if (lc1 == lc2) {
			ended.write(1);
		}

		count1.write(lc1);
		count2.write(lc2);
	}
}


int sc_main(int argc, char* argv[]) {
	problem1 model1("model");
	problem1Driver driver("driver");
	sc_clock td("td", 5, SC_NS);

	sc_signal<sc_uint<8>> in1, in2, in3;
	sc_signal<bool> load1, load2, dec1, dec2;

	sc_signal<sc_uint<8>> count1, count2;
	sc_signal<bool> ended;

	driver.in1(in1);
	driver.in2(in2);
	driver.in3(in3);
	driver.dec1(dec1);
	driver.dec2(dec2);
	driver.load1(load1);
	driver.load2(load2);


	model1.clock(td);
	model1.dec1(dec1);
	model1.dec2(dec2);
	model1.load1(load1);
	model1.load2(load2);
	model1.in1(in1);
	model1.in2(in2);
	model1.in3(in3);
	model1.ended(ended);
	model1.count1(count1);
	model1.count2(count2);

	sc_trace_file *wf = sc_create_vcd_trace_file("problem1 output");
	sc_trace(wf, td, "clk");
	sc_trace(wf, in1, "in1");
	sc_trace(wf, in2, "in2");
	sc_trace(wf, in3, "in3");
	sc_trace(wf, load1, "load1");
	sc_trace(wf, load2, "load2");
	sc_trace(wf, dec1, "dec1");
	sc_trace(wf, dec2, "dec2");
	sc_trace(wf, ended, "ended");
	sc_trace(wf, count1, "count1");
	sc_trace(wf, count2, "count2");

	sc_start(100, SC_NS);
	sc_close_vcd_trace_file(wf);

	return 0;
}


