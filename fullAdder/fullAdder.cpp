#include "fullAdder.h"

void fullAdder::doit(void){
    sc_lv<1>tmp_A,tmp_B,tmp_Ci;
    sc_lv<1>tmp_S,tmp_C;

    tmp_Ci=(sc_lv<1>)Ci.read();
    tmp_A=(sc_lv<1>)A.read();
    tmp_B=(sc_lv<1>)B.read();

    tmp_S=tmp_A^tmp_B^tmp_Ci;
    tmp_C=(tmp_A&tmp_B)|(tmp_A&tmp_Ci)|(tmp_B&tmp_Ci);

    S.write((sc_lv<1>)tmp_S);
    C.write((sc_lv<1>)tmp_C);


}
