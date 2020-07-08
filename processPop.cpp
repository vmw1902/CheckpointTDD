
#include <iostream>
#include <fstream>
#include <sstream>
#include <string.h>
#include <vector>
#include "processPop.h"

using namespace std;

processPop::processPop() {}

bool processPop::processFile(string fileName) {
    ifstream cityFile(fileName);
    if (!cityFile) //Always test the file open.
    {
        std::cout << "Error opening output file" << std::endl;
        system("pause");
        return false;
    }
    return true;
}

long processPop::calculateSum(string fileName)
{
    string line;
    vector<string> lines;
    ifstream cityFile(fileName);
    string substring;
    long sum = 0;

    while (std::getline(cityFile, line))
    {
        lines.push_back(line);
    }
    stringstream* token_ptr;
    for (int i = 1; i < lines.size(); i++) {
        vector<string> lineItems;
        token_ptr = new stringstream(lines[i]);
        while ((*token_ptr).good()) {
            getline(*token_ptr, substring, ',');
            lineItems.push_back(substring);
        }
        substring = lineItems[4];
        long pop = 0;
        if (substring.length() > 0) {
            pop = stoi(substring);
        }
        sum += pop;
        delete token_ptr;     
    }
    return sum;
}

void processPop::prepOutput(long sum) {
    stringstream ss;
    ss.imbue(std::locale(""));
    ss << std::fixed << sum;
    string num = ss.str();
    printf("World population is: %s.",num);
    //cout << "World population is: " << num << "." << endl; //throws some error
}

int processPop::mainFunction(string fileName)
{
    long sum = 0;
    if (!processFile(fileName)) //Always test the file open.
    {
        return -1;
    }
    sum = calculateSum(fileName);
    //--------------------------------------------------
    prepOutput(sum);
    return 0;
}

