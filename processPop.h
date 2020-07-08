
#ifndef processPop_h
#define processPop_h
#include <vector>
#include <string.h>
using namespace std;

class processPop {
public:
	bool processFile(std::string fileName);
	int mainFunction(std::string fileName);
	long calculateSum(string fileName);
	void prepOutput(long sum);
	processPop();
};
#endif /* processPop_h */
