#include "systemc.h"
#include "fullAdder4.h"
#include "test.h"

int sc_main(int argc, char* argv[]) {
    sc_signal< sc_lv<4> > X_in, Y_in, S_out;
    sc_signal< sc_lv<1> > C_in, C_out;

    sc_clock CLK("clock",10,SC_NS);

    fullAdder4 FA4("FA4");
    FA4(X_in, Y_in, C_in, S_out, C_out);

    test TEST("TEST");
    TEST(CLK,X_in,Y_in,C_in,S_out,C_out);

    sc_trace_file *tf = sc_create_vcd_trace_file("wave");
    sc_trace(tf,CLK,"clock");
    sc_trace(tf,X_in,"X_in");
    sc_trace(tf,Y_in,"Y_in");
    sc_trace(tf,C_in,"C_in");
    sc_trace(tf,S_out,"S_out");
    sc_trace(tf,C_out,"C_out");

    sc_start(80, SC_NS);
    sc_close_vcd_trace_file(tf);
    return(0);
}
