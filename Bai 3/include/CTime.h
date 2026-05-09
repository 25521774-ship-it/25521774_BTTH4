#ifndef CTIME_H
#define CTIME_H
#include <iostream>
using namespace std;
class CTime
{
    public:
        CTime(int h = 0, int m = 0, int s = 0);
        virtual ~CTime();
        CTime operator + (int s);
        CTime operator - (int s);
        CTime operator ++ ();
        CTime operator ++ (int);
        CTime operator -- ();
        CTime operator -- (int);
        void ChuanHoa();

        friend ostream& operator << (ostream& os, const CTime& tg);
        friend istream& operator >> (istream& os, CTime& tg);


    protected:

    private:
        int gio, phut, giay;
};

#endif // CTIME_H
