
#include <stdio.h>
#include <streambuf>
#include <sstream>
#include <iostream>
#include <ostream>
#include <string>
#include <gmock/gmock.h>
#include <gtest/gtest.h>

#include "processPop.h" 
#include "processPopMock.h"

using namespace std;

TEST(processPopulation, fileReadTest) {
    processPop wpFile;
    ostringstream strCout;
    streambuf* oldCout = cout.rdbuf(strCout.rdbuf());
    bool test = wpFile.processFile("./data/QuickTest.csv");
    EXPECT_EQ(test,true);
}

TEST(processPopulation, linesPushTest) {
    processPop wpFile;
    long sum = 0;
    sum = wpFile.calculateSum("./data/QuickTest.csv");
    EXPECT_GT(sum, 0);
}

TEST(processPopulation, outputCalled) {
    processPopMock PPM;
    EXPECT_CALL(PPM, prepOutput(100));
    PPM.prepOutput(100);
}

TEST(processPopulation, calcSumCalled) {
    processPopMock PPM;
    EXPECT_CALL(PPM, calculateSum);
    PPM.calculateSum("./data/QuickTest.csv");
}

TEST(processPopulation, mainFunctionTest) {
    processPop wpFile;
    int test = wpFile.mainFunction("./data/QuickTest.csv");
    EXPECT_EQ(test, 0);
}

int main(int argc, char** argv) {
    testing::InitGoogleMock(&argc, argv);
    return RUN_ALL_TESTS();
}
