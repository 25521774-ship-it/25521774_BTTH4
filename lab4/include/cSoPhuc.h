#ifndef CSOPHUC_H
#define CSOPHUC_H

#include <iostream>
using namespace std;

class cSoPhuc
{
private:
    double thuc, ao;

public:
    cSoPhuc(double t = 0, double a = 0);
    ~cSoPhuc();

    cSoPhuc operator+(const cSoPhuc& sp);
    cSoPhuc operator-(const cSoPhuc& sp);
    cSoPhuc operator*(const cSoPhuc& sp);
    cSoPhuc operator/(const cSoPhuc& sp);

    bool operator==(const cSoPhuc& sp);
    bool operator!=(const cSoPhuc& sp);

    friend ostream& operator<<(ostream& os, const cSoPhuc& sp);
    friend istream& operator>>(istream& is, cSoPhuc& sp);
};

#endif

