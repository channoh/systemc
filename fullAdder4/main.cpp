#include "systemc.h"
#include "fullAdder.h"
#include "test.h"
#include "vector.h"

int sc_main(int argc, char* argv[]) {
    sc_signal<sc_lv<4>> X, Y;
    sc_signal<sc_lv<1>> Ci;
    sc_signal<sc_lv<4>> S;
    sc_signal<sc_lv<1>> Co;

    sc_signal<sc_lv<1>> X1, X2, X3, X4;
    sc_signal<sc_lv<1>> Y1, Y2, Y3, Y4;
    sc_signal<sc_lv<1>> C1, C2, C3;
    sc_signal<sc_lv<1>> S1, S2, S3, S4;

    sc_clock CLK("clock", 10, SC_NS);

    vector2bits v2b1("v2b1");
    v2b1(X, X4, X3, X2, X1);

    vector2bits v2b2("v2b2");
    v2b2(Y, Y4, Y3, Y2, Y1);

    fullAdder FA0("FA0");
    FA0(X1, Y1, Ci, S1, C1);

    fullAdder FA1("FA1");
    FA1(X2, Y2, C1, S2, C2);

    fullAdder FA2("FA0");
    FA2(X3, Y3, C2, S3, C3);

    fullAdder FA3("FA0");
    FA3(X4, Y4, C3, S4, Co);

    bits2vector b2v1("b2v1");
    b2v1(S4, S3, S2, S1, S);

    test TEST("TEST");
    TEST(CLK, X, Y, Ci, S, Co);

    sc_trace_file *tf = sc_create_vcd_trace_file("wave");
    sc_trace(tf, CLK, "clock");
    sc_trace(tf, X, "X");
    sc_trace(tf, Y, "Y");
    sc_trace(tf, Ci, "Ci");
    sc_trace(tf, S, "S");
    sc_trace(tf, Co, "Co");

    sc_start(80, SC_NS);
    sc_close_vcd_trace_file(tf);
    return(0);
}
