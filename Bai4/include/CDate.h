#ifndef CDATE_H
#define CDATE_H
#include <iostream>
using namespace std;

class CDate
{
    public:
        CDate(int d = 0, int m = 0, int y = 0);
        virtual ~CDate();
        void ChuanHoa();
        bool IsLeapYear(int y) const;
        int DaysInMonth(int m, int y) const;
        long long ToDays() const;
        void FromDays(long long totalDays);
        CDate operator+(int n);
        CDate operator-(int n);
        long long operator-(const CDate& other);
        CDate& operator++();
        CDate operator++(int);
        CDate& operator--();
        CDate operator--(int);
        friend istream& operator>>(istream& in, CDate& d);
        friend ostream& operator<<(ostream& out, const CDate& d);
    protected:

    private:
        int day, month, year;
};

#endif // CDATE_H

