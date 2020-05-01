#ifndef STRINGOPERATIONS_H
#define STRINGOPERATIONS_H

#include <iostream>
#include <sstream>
#include <algorithm>
#include <string>
#include <vector>

using namespace std;

class StringOperations
{
public:
    StringOperations();

    static vector<string> Split(const string& s, char separator);
};

#endif // STRINGOPERATIONS_H
