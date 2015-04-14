#include <systemc.h>
#include <iostream>

SC_MODULE(Hello_SystemC) {
    sc_in_clk iclk;
    SC_CTOR(Hello_SystemC) {
        SC_METHOD(main_method);
        sensitive << iclk.neg();
        dont_initialize();
    }
    void main_method(void) {
        std:cout << sc_time_stamp()
                 << "Hello world"
                 << std::endl;
    }
};

int sc_main(int argc, char* argv[]) {
    const sc_time t_PERIOD(8, SC_NS);
    sc_clock clk("clk", t_PERIOD);
    Hello_SystemC iHelloWorld("iHelloWorld");
    iHelloWorld.iclk(clk);
    sc_start(10, SC_NS);
    return 0;
}
