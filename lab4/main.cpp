#include <iostream>
#include "cSoPhuc.h"

using namespace std;

int main()
{
    cSoPhuc a, b;

    cout << "Nhap so phuc a:\n";
    cin >> a;

    cout << "\nNhap so phuc b:\n";
    cin >> b;

    cout << "\na = " << a << endl;
    cout << "b = " << b << endl;

    cout << "\na + b = " << a + b << endl;
    cout << "a - b = " << a - b << endl;
    cout << "a * b = " << a * b << endl;
    cout << "a / b = " << a / b << endl;

    if (a == b)
        cout << "a == b\n";
    else
        cout << "a != b\n";

    return 0;
}


