#include <systemc.h>
#include "fullAdder.h"

SC_MODULE(fullAdder4) {
    sc_in< sc_lv<4> > X;
    sc_in< sc_lv<4> > Y;
    sc_in< sc_lv<1> > Ci;
    sc_out< sc_lv<4> > S;
    sc_out< sc_lv<1> > Co;

    fullAdder fa0, fa1, fa2, fa3;

    sc_signal< sc_lv<1> > X0, X1, X2, X3;
    sc_signal< sc_lv<1> > Y0, Y1, Y2, Y3;
    sc_signal< sc_lv<1> > C1, C2, C3;
    sc_signal< sc_logic > S0, S1, S2, S3;

    SC_CTOR(fullAdder4) : fa0("fa0"), fa1("fa1"), fa2("fa2"), fa3("fa3")
    {
        SC_METHOD (process);
        sensitive << X << Y << Ci;
    }

    void process() {
        sc_lv<4> Stmp;

        X0 = (sc_lv<1>)X.read()[0];
        Y0 = (sc_lv<1>)Y.read()[0];
        fa0(X0, Y0, Ci, S0, C1);

        // X1 = (sc_lv<1>)X.read()[1];
        // Y1 = (sc_lv<1>)Y.read()[1];
        // fa1(X1, Y1, C1, S1, C2);

        // X2 = (sc_lv<1>)X.read()[1];
        // Y2 = (sc_lv<1>)Y.read()[1];
        // fa2(X2, Y2, C2, S2, C3);

        // X3 = (sc_lv<1>)X.read()[1];
        // Y3 = (sc_lv<1>)Y.read()[1];
        // fa3(X3, Y3, C3, S3, Co);

        // Stmp[3] = S3;
        // Stmp[2] = S2;
        // Stmp[1] = S1;
        // Stmp[0] = S0;

        // S = Stmp;
    }
};
