
#include <stdio.h>
#include <iostream>
#include "processPop.h"

using namespace std;

int mymain(int argc, const char* argv[]) {
    processPop processPopObj;
    if (argc < 2) {
        cout << "usage: must include file to parse" << endl;
    }
    else {
        processPopObj.mainFunction(argv[1]);
    }
    return 0;
}
