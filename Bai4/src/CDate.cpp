#include "CDate.h"

CDate::CDate(int d, int m, int y)
{
    day = d;
    month = m;
    year = y;
}

CDate::~CDate()
{
    //dtor
}
bool CDate::IsLeapYear(int y) const {
        return (y % 400 == 0 || (y % 4 == 0 && y % 100 != 0));
}
int CDate::DaysInMonth(int m, int y) const {
        int days[] = {0,31,28,31,30,31,30,31,31,30,31,30,31};

        if (m == 2 && IsLeapYear(y))
            return 29;

        return days[m];
    }
long long CDate::ToDays() const {
        long long total = 0;

        for (int y = 1; y < year; y++) {
            total += IsLeapYear(y) ? 366 : 365;
        }

        for (int m = 1; m < month; m++) {
            total += DaysInMonth(m, year);
        }

        total += day;

        return total;
    }
void CDate::FromDays(long long totalDays) {
        year = 1;

        while (true) {
            int daysYear = IsLeapYear(year) ? 366 : 365;

            if (totalDays > daysYear) {
                totalDays -= daysYear;
                year++;
            } else break;
        }

        month = 1;

        while (true) {
            int daysMonth = DaysInMonth(month, year);

            if (totalDays > daysMonth) {
                totalDays -= daysMonth;
                month++;
            } else break;
        }

        day = totalDays;
    }
CDate CDate::operator+(int n) {
        CDate temp = *this;
        long long total = temp.ToDays();
        total += n;
        temp.FromDays(total);
        return temp;
    }

    // Trừ đi n ngày
CDate CDate::operator-(int n) {
        CDate temp = *this;
        long long total = temp.ToDays();
        total -= n;
        temp.FromDays(total);
        return temp;
    }

    // Khoảng cách giữa 2 ngày
long long CDate:: operator-(const CDate& other) {
    int khoangcach = this ->ToDays() - other.ToDays();
    if (khoangcach < 0) khoangcach =- khoangcach;
        return khoangcach;
    }

    // ++date
CDate& CDate::operator++() {
        *this = *this + 1;
        return *this;
    }

    // date++
CDate CDate::operator++(int) {
        CDate temp = *this;
        *this = *this + 1;
        return temp;
    }

    // --date
CDate& CDate::operator--() {
        *this = *this - 1;
        return *this;
    }

    // date--
CDate CDate::operator--(int) {
        CDate temp = *this;
        *this = *this - 1;
        return temp;
    }
istream& operator>>(istream& in, CDate& d)
{
    cout<<"Nhap ngay thang nam: ";
    in >> d.day >> d.month>> d.year;
    return in;
}
ostream& operator<<(ostream& out, const CDate& d)
{
    out<< d.day << "/" << d.month << "/" << d.year;
    return out;
}
