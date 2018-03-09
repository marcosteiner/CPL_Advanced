#include "cute.h"
#include "ide_listener.h"
#include "xml_listener.h"
#include "cute_runner.h"
#include <string>
#include <experimental/filesystem>

#include "directorySizer_h.txt"
namespace fs = std::experimental::filesystem;


void testDirectorySizerInNewlyCreatedDirectory() {
	int directorySize{6};
	std::string path{"sandbox"};
	int result {directorySizer(path)};
	//fs::remove_all("sandbox");
	ASSERT_EQUAL(directorySize, result);
}


void runAllTests(int argc, char const *argv[]){
	cute::suite s;
	s.push_back(CUTE(testDirectorySizerInNewlyCreatedDirectory));
	cute::xml_file_opener xmlfile(argc,argv);
	cute::xml_listener<cute::ide_listener<> >  lis(xmlfile.out);
	cute::makeRunner(lis,argc,argv)(s, "AllTests");
}

int main(int argc, char const *argv[]){
    runAllTests(argc,argv);
    return 0;
}
