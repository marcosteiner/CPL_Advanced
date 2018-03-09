#include "Exercise1.h"
#include <stdexcept>
#include <limits>

int inc_by_value(int value) {
	return ++value;
}

int inc(int &value){
	if(std::numeric_limits<int>::max() <= value) {
		throw std::overflow_error("cannot increment");
	}
	return ++value;
}
