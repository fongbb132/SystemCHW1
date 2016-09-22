#include "problem1.h"
#include "problem1Driver.h"
// void problem1::monitor() {
	// cout << "@" << sc_time_stamp() << clock << " " << " in 1: " << in1 <<" in 2:" << in2<< " in3: " << in3<< " load1: "  << load1 << " load2: " << load2 <<" dec1: " << dec1 << " dec2: " << dec2 << " count1: " << count1 << " count2: " << count2 << endl;


// }

void problem1::process() {
	if (clock) {

		// bool isTheSame = load1.read() == load2.read();
		// if (load1.read()) {
		// 	count1.write(in1.read());
		// }

		// if (dec1.read() && !isTheSame) {
		// 	count1.write(count1.read() - 1);
		// }

		// if (load2.read()) {
		// 	count2.write(in2.read());
		// }

		// if (dec2.read() && !isTheSame) {
		// 	count2.write(count2.read() - in3.read());
		// }

		// if (count1.read() == count2.read()) {
		// 	ended.write(1);
		// }

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
	sc_trace(wf, count1, "count1");
	sc_trace(wf, count2, "count2");

	sc_start(100, SC_NS);
	sc_close_vcd_trace_file(wf);

	return 0;
}


