#ifndef DATHUC_H
#define DATHUC_H
#include <iostream>
using namespace std;

class DaThuc
{
    public:
        DaThuc(int mu = 0);
        DaThuc(const DaThuc& dt);
        virtual ~DaThuc();
        DaThuc operator + (const DaThuc& dt);
        DaThuc operator - (const DaThuc& dt);
        DaThuc& operator = (const DaThuc& dt);
        friend istream& operator >> (istream& is, DaThuc& dt);
        friend ostream& operator << (ostream& os, const DaThuc& dt);

    protected:

    private:
        double* heso;
        int mu;
};

#endif // DATHUC_H
