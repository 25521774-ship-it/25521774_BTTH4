#include "CVector.h"
#include <iostream>
#include <cmath>
#include <stdexcept>
using namespace std;

CVector::CVector(int dimension)
{
    n = dimension;
    data.resize(n, 0);
}

CVector::~CVector()
{
    //dtor
}
istream& operator >> (istream& is, CVector& vt)
{
    cout<<"Nhap so chieu: ";
    is >> vt.n;
    vt.data.resize(vt.n);
    cout<<"Nhap cac phan tu:\n";
    for (int i = 0; i<vt.n; i++)
    {
        is >> vt.data[i];
    }
    return is;
}
ostream& operator << (ostream& os, const CVector& vt)
{
    os << "(";
    for (int i = 0; i<vt.n; i++)
    {
        os << vt.data[i];
        if (i != vt.n - 1) os <<",";
    }
    os << ")";
    return os;
}
// Cong 2 vector
CVector CVector::operator + (const CVector& vt)
{
    if (n != vt.n) throw invalid_argument("Khac so chieu!");
    CVector res(n);
    for (int i = 0; i< n; i++)
    {
        res.data[i] = data[i] + vt.data[i];
    }
    return res;
}
// Tru 2 vector
CVector CVector::operator - (const CVector& vt)
{
    if (n != vt.n) throw invalid_argument("Khac so chieu!");
    CVector res(n);
    for (int i = 0; i< n; i++)
    {
        res.data[i] = data[i] - vt.data[i];
    }
    return res;
}
// Nhan voi so thuc
CVector CVector::operator*(double k)
{
    CVector res(n);
    for (int i = 0; i< n; i++)
    {
        res.data[i] = k*data[i];
    }
    return res;
}
// Tich vo huong
double CVector::operator * (const CVector& vt)
{
    if (n != vt.n) throw invalid_argument("Khac so chieu!");
    double sum = 0;
    for (int i = 0; i < n; i++)
    {
        sum += data[i] * vt.data[i];
    }
    return sum;
}
// Do dai vector
double CVector::DoDai()
{
    double sum = 0;
    for (int i = 0; i< n; i++)
    {
        sum += data[i] * data[i];
    }
    return sqrt(sum);
}
