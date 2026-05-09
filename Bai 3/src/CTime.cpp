#include "CTime.h"

CTime::CTime(int h, int m, int s)
{
    gio = h;
    phut = m;
    giay = s;
}

CTime::~CTime()
{
    //dtor
}

void CTime::ChuanHoa()
{
    int tong = gio * 3600 + phut * 60 + giay;

    tong %= 86400;

    gio = tong / 3600;
    tong %= 3600;

    phut = tong / 60;
    giay = tong % 60;
}
CTime CTime::operator+(int s)
{
    CTime temp = *this;

    temp.giay += s;
    temp.ChuanHoa();

    return temp;
}

CTime CTime::operator-(int s)
{
    CTime temp = *this;

    temp.giay -= s;
    temp.ChuanHoa();

    return temp;
}

CTime CTime::operator++()
{
    giay++;

    ChuanHoa();

    return *this;
}

CTime CTime::operator++(int)
{
    CTime temp = *this;

    ++(*this);

    return temp;
}

CTime CTime::operator--()
{
    giay--;

    ChuanHoa();

    return *this;
}

CTime CTime::operator--(int)
{
    CTime temp = *this;

    --(*this);

    return temp;
}

ostream& operator<<(ostream& os, const CTime& tg)
{
    if (tg.gio < 10) os << "0";
    os << tg.gio << ":";

    if (tg.phut < 10) os << "0";
    os << tg.phut << ":";

    if (tg.giay < 10) os << "0";
    os << tg.giay;

    return os;
}

istream& operator>>(istream& is, CTime& tg)
{
    do
    {
        cout << "Nhap gio: ";
        is >> tg.gio;
    }while (tg.gio < 0 || tg.gio > 24);

    do
    {
        cout << "Nhap phut: ";
        is >> tg.phut;
    }while (tg.phut < 0 || tg.phut > 60);

    do
    {
        cout << "Nhap giay: ";
        is >> tg.giay;
    }while(tg.giay < 0 || tg.giay > 60);

    tg.ChuanHoa();

    return is;
}
