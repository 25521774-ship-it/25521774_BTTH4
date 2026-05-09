#ifndef PHANSO_H
#define PHANSO_H
#include <iostream>
using namespace std;
class PhanSo
{
    public:
        PhanSo(int t = 0, int m = 1);
        virtual ~PhanSo();

        PhanSo operator + (const PhanSo& ps);
        PhanSo operator - (const PhanSo& ps);
        PhanSo operator * (const PhanSo& ps);
        PhanSo operator / (const PhanSo& ps);

        PhanSo Rutgon(PhanSo a);

        bool operator == (const PhanSo& ps);
        bool operator > (const PhanSo& ps);
        bool operator < (const PhanSo& ps);

        friend ostream& operator<<(ostream& os, const PhanSo& ps);
        friend istream& operator>>(istream& os, PhanSo& ps);

    protected:

    private:
        int tu, mau;
};

#endif // PHANSO_H

