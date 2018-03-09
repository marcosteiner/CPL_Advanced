#include "cute.h"
#include "ide_listener.h"
#include "xml_listener.h"
#include "cute_runner.h"
#include "Exercise1.h"

#include <limits>

void testIncrement() {
	int v { 1 };
	ASSERT_EQUAL(2, inc_by_value(v));
}

void testIncrementWSideeffect() {
	int v { 5 };
	ASSERT_EQUAL(6, inc_by_value(v));
}

void testOverflow() {
	int v { std::numeric_limits<int>::max() };
	ASSERT_THROWS(inc(v), std::overflow_error);
}

void testTemplateVersion() {
	double value { 4.2 };
	inc(value);
	ASSERT_EQUAL(5.2, value);
}

bool runAllTests(int argc, char const *argv[]) {
	cute::suite s { };
	//TODO add your test here
	s.push_back(CUTE(testIncrement));
	s.push_back(CUTE(testIncrementWSideeffect));
	s.push_back(CUTE(testOverflow));
	s.push_back(CUTE(testTemplateVersion));
	cute::xml_file_opener xmlfile(argc, argv);
	cute::xml_listener<cute::ide_listener<>> lis(xmlfile.out);
	auto runner = cute::makeRunner(lis, argc, argv);
	bool success = runner(s, "AllTests");
	return success;
}

int main(int argc, char const *argv[]) {
    return runAllTests(argc, argv) ? EXIT_SUCCESS : EXIT_FAILURE;
}
