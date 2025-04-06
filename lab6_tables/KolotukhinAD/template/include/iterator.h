#pragma once
#include <iostream>
using namespace std;
template <typename T>
class Iterator {
private:
    virtual bool hasNext() = 0;
    virtual T& next() = 0;
};
