#include <systemc.h>

SC_MODULE(fullAdder) {
    sc_in< sc_lv<1> > A;
    sc_in< sc_lv<1> > B;
    sc_in< sc_lv<1> > Ci;
    sc_out< sc_lv<1> > S;
    sc_out< sc_lv<1> > C;
    void doit(void);
    SC_CTOR(fullAdder) {
        SC_METHOD(doit);
        sensitive << A;
        sensitive << B;
        sensitive << Ci;
    }
};
