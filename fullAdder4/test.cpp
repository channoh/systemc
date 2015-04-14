#include"test.h"
void test::do_test() {
    while(true) {
        X_in.write(0);
        Y_in.write(0);
        Ci.write(0);
        wait(1);

        X_in.write(1);
        Y_in.write(0);
        Ci.write(0);
        wait(1);

        X_in.write(1);
        Y_in.write(0);
        Ci.write(1);
        wait(1);

        X_in.write(0);
        Y_in.write(0);
        Ci.write(1);
        wait(1);

        X_in.write(1);
        Y_in.write(1);
        Ci.write(1);
        wait(1);
    }
}
