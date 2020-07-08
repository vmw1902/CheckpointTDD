#pragma once
#include <string.h>
#include <gmock/gmock.h>
#include "processPop.h"

using namespace std;

class processPopMock:public processPop {
public:
	MOCK_METHOD(void, prepOutput, (long sum));
	MOCK_METHOD(long, calculateSum, (string fileName));
};