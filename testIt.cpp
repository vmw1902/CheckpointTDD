
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

/*TEST(processPopulation, outputTest) {
    //setup
    string expected = "World population is: 1,347,982,728.\n";
    processPop processPopObj;

    //redirect standard out
    ostringstream strCout;
    streambuf* oldCout = cout.rdbuf(strCout.rdbuf());

    processPopObj.processPopulationFile("./data/worldcitiespop.csv");

    string actual = strCout.str();
    EXPECT_EQ(actual, expected);

    cout.rdbuf(oldCout);
}*/

TEST(processPopulation, fileReadTest) {
    processPop wpFile;
    ostringstream strCout;
    streambuf* oldCout = cout.rdbuf(strCout.rdbuf());
    bool test = wpFile.processFile("./data/worldcitiespop.csv");
    EXPECT_EQ(test,true);
}

TEST(processPopulation, linesPushTest) {
    processPop wpFile;
    long sum = 0;
    sum = wpFile.calculateSum("./data/worldcitiespop.csv");
    EXPECT_GT(sum, 0);
}

TEST(processPopulation, outputCalled) {
    processPopMock PPM;
    EXPECT_CALL(PPM, prepOutput(100));
    PPM.prepOutput(100);
}

TEST(processPopulation, mainFunctionTest) {
    processPop wpFile;
    int test = wpFile.mainFunction("./data/worldcitiespop.csv");
    EXPECT_EQ(test, 0);
}

int main(int argc, char** argv) {
    testing::InitGoogleMock(&argc, argv);
    return RUN_ALL_TESTS();
}
