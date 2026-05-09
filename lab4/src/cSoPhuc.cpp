#include "cSoPhuc.h"

cSoPhuc::cSoPhuc(double t, double a)
{
    thuc = t;
    ao = a;
}

cSoPhuc::~cSoPhuc()
{
}

cSoPhuc cSoPhuc::operator+(const cSoPhuc& sp)
{
    return cSoPhuc(thuc + sp.thuc,
                    ao + sp.ao);
}

cSoPhuc cSoPhuc::operator-(const cSoPhuc& sp)
{
    return cSoPhuc(thuc - sp.thuc,
                    ao - sp.ao);
}

cSoPhuc cSoPhuc::operator*(const cSoPhuc& sp)
{
    return cSoPhuc(
        thuc * sp.thuc - ao * sp.ao,
        thuc * sp.ao + ao * sp.thuc
    );
}

cSoPhuc cSoPhuc::operator/(const cSoPhuc& sp)
{
    double mau = sp.thuc * sp.thuc + sp.ao * sp.ao;

    return cSoPhuc(
        (thuc * sp.thuc + ao * sp.ao) / mau,
        (ao * sp.thuc - thuc * sp.ao) / mau
    );
}

bool cSoPhuc::operator==(const cSoPhuc& sp)
{
    return (thuc == sp.thuc && ao == sp.ao);
}

bool cSoPhuc::operator!=(const cSoPhuc& sp)
{
    return !(*this == sp);
}

ostream& operator<<(ostream& os, const cSoPhuc& sp)
{
    if (sp.thuc == 0)
    {
        if (sp.ao > 0)
            os << sp.ao << "i";
        else if (sp.ao < 0)
            os << " - " << -sp.ao << "i";
    }
    else
    {
        os << sp.thuc;

        if (sp.ao > 0)
            os << " + " << sp.ao << "i";
        else if (sp.ao < 0)
            os << " - " << -sp.ao << "i";
    }

    return os;
}

istream& operator>>(istream& is, cSoPhuc& sp)
{
    cout << "Nhap phan thuc: ";
    is >> sp.thuc;

    cout << "Nhap phan ao: ";
    is >> sp.ao;

    return is;
}
