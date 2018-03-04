//:fifo.h linpeiwen
#ifndef FIFO_H
#define FIFO_H
#include "simulator.h"
#include <iostream>
#include <string>
using namespace std;

//define class fifo
class fifo : public simulator {
public:
	fifo(int seconds_per_page) : simulator(seconds_per_page) {}
	void simulate(string file); 
};

#endif
///:~