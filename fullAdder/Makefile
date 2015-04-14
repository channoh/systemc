SRCs := main.cpp test.cpp fullAdder.cpp

all: $(SRCs)
	g++ -I. -I${SYSTEMC_HOME}/include -L. -L${SYSTEMC_HOME}/lib-linux64 -o adder.out $(SRCs) -lsystemc -lm

clean:
	rm adder.out wave.vcd
