#ifndef CVECTOR_H
#define CVECTOR_H
#include <vector>
#include <iostream>
using namespace std;

class CVector
{
    public:
        CVector(int dimension = 0);
        virtual ~CVector();
        friend istream& operator >> (istream& is, CVector& vt);
        friend ostream& operator << (ostream& os, const CVector& vt);
        CVector operator + (const CVector& vt);
        CVector operator - (const CVector& vt);
        CVector operator * (double k);
        double operator * (const CVector& vt);
        double DoDai();
    protected:

    private:
        int n;
        vector<double> data;
};

#endif // CVECTOR_H
