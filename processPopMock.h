#pragma once
#include <gmock/gmock.h>
#include "processPop.h"

using namespace std;

class processPopMock:public processPop {
public:
	MOCK_METHOD(void, prepOutput, (long sum));
};