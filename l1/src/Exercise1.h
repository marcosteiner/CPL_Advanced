#ifndef SRC_EXERCISE1_H_
#define SRC_EXERCISE1_H_
#include <limits>
#include <stdexcept>

int inc_by_value(int value);

template<typename T>
void inc(T & value) {
	if(std::numeric_limits<int>::max() <= value) {
			throw std::overflow_error("cannot increment");
		}
		++value;
}


#endif /* SRC_EXERCISE1_H_ */
