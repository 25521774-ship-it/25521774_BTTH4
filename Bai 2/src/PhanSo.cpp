#include "PhanSo.h"
#include <numeric>
using namespace std;
PhanSo::PhanSo(int t, int m)
{
    tu = t;
    if (m == 0)
    {
        cout<<"Mau phai khac 0";
        mau = 1;
    }
    else mau = m;
}
PhanSo::~PhanSo()
{
    //dtor
}
PhanSo PhanSo::Rutgon(PhanSo a)
{
    int ucln = gcd(a.tu, a.mau);
    a.tu /= ucln;
    a.mau /= ucln;

    return a;
}
PhanSo PhanSo::operator + (const PhanSo& ps)
{
    return Rutgon(PhanSo(tu*ps.mau + ps.tu* mau, mau*ps.mau));
}
PhanSo PhanSo::operator - (const PhanSo& ps)
{
    return Rutgon(PhanSo(tu*ps.mau - ps.tu* mau, mau*ps.mau));
}
PhanSo PhanSo::operator * (const PhanSo& ps)
{
    return Rutgon(PhanSo(tu * ps.tu, mau * ps.mau));
}
PhanSo PhanSo::operator / (const PhanSo& ps)
{
    if (ps.tu == 0)
    {
        cout << "Khong the chia cho 0";
        return PhanSo();
    }
    return Rutgon(PhanSo(tu * ps.mau, mau * ps.tu));
}
bool PhanSo::operator==(const PhanSo& ps)
{
    PhanSo a = Rutgon(*this);
    PhanSo b = Rutgon(ps);

    return(a.tu == b.tu && a.mau == b.mau);
}
bool PhanSo::operator > (const PhanSo& ps)
{
    PhanSo a = Rutgon(*this);
    PhanSo b = Rutgon(ps);

    return(a.tu * b.mau - a.mau * b.tu > 0);
}
bool PhanSo::operator < (const PhanSo& ps)
{
    return !(*this > ps) && !(*this == ps);
}
ostream& operator<<(ostream& os, const PhanSo& ps)
{
    if (ps.tu == 0)
    {
        os << 0;
    }
    else if (ps.mau == 1)
    {
        os << ps.tu;
    }
    else if (ps.mau < 0)
    {
        os << -ps.tu << "/" << -ps.mau;
    }
    else
    {
        os << ps.tu << "/" << ps.mau;
    }

    return os;
}
istream& operator>>(istream& is, PhanSo& ps)
{
    cout << "Nhap tu: ";
    is >> ps.tu;

    do
    {
        cout << "Nhap mau: ";
        is >> ps.mau;

        if (ps.mau == 0)
        {
            cout << "Mau phai khac 0\n";
        }

    } while (ps.mau == 0);

    return is;
}
