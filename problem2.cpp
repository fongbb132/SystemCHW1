#include "problem2.h"
#include "problem2Driver.h"
void problem2::process() {

	if (!reset) {
		payload = 0;
		count = 0;
		error = 0;
	}
	else if (clear) {
		payload = 0;
	}
	else if (clk) {
		int part1 = inData.read().range(11, 8).to_int();
		if (part1) {
			sc_uint<4> part2 = inData.read().range(7, 4);
			payload.write(part2);
			int num1s = 0;

			if (part2[0])num1s++;
			if (part2[1]) num1s++;
			if (part2[2]) num1s++;
			if (part2[3]) num1s++;

			if ((num1s % 2 == 0) == inData.read().range(3, 0).to_int()) {
				countInt++;
			}
			else {
				errorInt++;
			}

			count.write(countInt);
			error.write(errorInt);

		}
	}

}


int sc_main(int argc, char* argv[]) {
	
	problem2 model("problem 2");
	problem2_driver driver("driver2");
	sc_signal <bool> clk;
	sc_signal <bool> reset;
	sc_signal <bool> clear;
	sc_signal <sc_uint<12>> indata;

	sc_clock td("td", 5, SC_NS);
	sc_signal<sc_uint<4>> payload;
	sc_signal<sc_uint<8>> count;
	sc_signal<sc_uint<8>> error;
	
	driver.clear(clear);
	driver.inData(indata);
	reset = 1; 
	model.clk(td);
	model.reset(reset);
	model.clear(clear);
	model.inData(indata);
	
	model.payload(payload);
	model.count(count);
	model.error(error);



	sc_trace_file *wf = sc_create_vcd_trace_file("ports_access");
	sc_trace(wf, clk, "clk");
	sc_trace(wf, reset, "reset");
	sc_trace(wf, clear, "clear");
	sc_trace(wf, indata, "indata");
	sc_trace(wf, payload, "payload");
	sc_trace(wf, count, "count");
	sc_trace(wf, error, "error");

	

	sc_start(100, SC_NS);
	sc_close_vcd_trace_file(wf);

	return 0;

}