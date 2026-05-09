#ifndef CMATRIX_H
#define CMATRIX_H
#include <iostream>
#include <vector>
using namespace std;

class CMatrix
{
    public:
        CMatrix(int rows = 0, int cols = 0);
        virtual ~CMatrix();
        friend istream& operator >> (istream& is, CMatrix& mt);
        friend ostream& operator << (ostream& os, const CMatrix& mt);
        CMatrix operator + (const CMatrix& mt);
        CMatrix operator - (const CMatrix& mt);
        CMatrix operator * (const CMatrix& mt);
        vector<double> operator * (const vector<double>& mt);
    protected:

    private:
        int rows, cols;
        vector<vector<double>> a;
};

#endif // CMATRIX_H
