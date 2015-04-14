#include "systemc.h"

SC_MODULE(test) {
    sc_in<bool> clock;
    sc_out<sc_lv<1>> X_in,Y_in,Ci;
    sc_in<sc_lv<1>> S_out,C_out;

    void do_test();
    void print();

    SC_CTOR(test) {
        SC_CTHREAD(do_test,clock.neg());
    }
};
