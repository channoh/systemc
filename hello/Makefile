SRCs := hello.cpp

all: $(SRCs)
	g++ -I. -I${SYSTEMC_HOME}/include -L${SYSTEMC_HOME}/lib-linux64 -o hello $(SRCs) -lsystemc -lm

clean:
	rm hello
