#include "CMatrix.h"
#include <iostream>
#include <stdexcept>
using namespace std;

CMatrix::CMatrix(int rows, int cols)
{
    this->rows = rows;
    this->cols = cols;
    a.resize(rows, vector<double>(cols));
}

CMatrix::~CMatrix() {}

istream& operator>>(istream& is, CMatrix& mt)
{
    cout<<"Nhap so hang: ";
    is >> mt.rows;
    cout<<"Nhap so cot: ";
    is >> mt.cols;
    mt.a.resize(mt.rows, vector<double>(mt.cols));
    for (int i = 0; i < mt.rows; i++)
        for (int j = 0; j < mt.cols; j++)
            is >> mt.a[i][j];
    return is;
}

ostream& operator<<(ostream& os, const CMatrix& mt)
{
    for (int i = 0; i < mt.rows; i++)
    {
        for (int j = 0; j < mt.cols; j++)
            os << mt.a[i][j] << " ";
        os << "\n";
    }
    return os;
}

CMatrix CMatrix::operator+(const CMatrix& mt)
{
    if (rows != mt.rows || cols != mt.cols)
        throw invalid_argument("Khong the cong hai ma tran khac kich thuoc");
    CMatrix temp(rows, cols);
    for (int i = 0; i < rows; i++)
        for (int j = 0; j < cols; j++)
            temp.a[i][j] = a[i][j] + mt.a[i][j];
    return temp;
}

CMatrix CMatrix::operator-(const CMatrix& mt)
{
    if (rows != mt.rows || cols != mt.cols)
        throw invalid_argument("Khong the tru hai ma tran khac kich thuoc");
    CMatrix temp(rows, cols);
    for (int i = 0; i < rows; i++)
        for (int j = 0; j < cols; j++)
            temp.a[i][j] = a[i][j] - mt.a[i][j];
    return temp;
}

CMatrix CMatrix::operator*(const CMatrix& mt)
{
    if (cols != mt.rows)
        throw invalid_argument("Khong the nhan hai ma tran");
    CMatrix temp(rows, mt.cols);
    for (int i = 0; i < rows; i++)
        for (int j = 0; j < mt.cols; j++)
            for (int k = 0; k < cols; k++)
                temp.a[i][j] += a[i][k] * mt.a[k][j];
    return temp;
}
vector<double> CMatrix::operator * (const vector<double>& mt)
{
    if (cols != mt.size()) throw invalid_argument("Sai kich thuoc");
    vector<double>result(rows, 0);
    for (int i = 0; i<rows;i++)
    {
        for (int j = 0; j<cols; j++)
        {
            result[i] += a[i][j] * mt[j];
        }
    }
    return result;
}
