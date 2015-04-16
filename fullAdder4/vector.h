SC_MODULE (vector2bits) {
    sc_in<sc_lv<4>> I;
    sc_out<sc_lv<1>> O3, O2, O1, O0;

    SC_CTOR (vector2bits) {
        SC_METHOD (process);
        sensitive << I;
    }

    void process() {
        sc_lv<4> temp = I.read();

        O3.write((sc_lv<1>)temp[3]);
        O2.write((sc_lv<1>)temp[2]);
        O1.write((sc_lv<1>)temp[1]);
        O0.write((sc_lv<1>)temp[0]);


    }
};

SC_MODULE (bits2vector) {
    sc_in<sc_lv<1>> O3, O2, O1, O0;
    sc_out<sc_lv<4>> S;

    SC_CTOR (bits2vector) {
        SC_METHOD (process);
        sensitive << O3 << O2 << O1 << O0 << S;
    }

    void process() {
        S.write((O3.read(), O2.read(), O1.read(), O0.read()));
    }
};
