#include <iostream>
#include "CTime.h"

using namespace std;

int main()
{
    CTime t;

    cout << "Nhap thoi gian:\n";
    cin >> t;

    cout << "\nThoi gian hien tai: " << t << endl;

    int x;

    cout << "\nNhap so giay can cong: ";
    cin >> x;

    cout << "Sau khi cong: " << t + x << endl;

    cout << "\nNhap so giay can tru: ";
    cin >> x;

    cout << "Sau khi tru: " << t - x << endl;

    cout << "\nPrefix ++:\n";
    cout << ++t << endl;

    cout << "\nPostfix ++:\n";
    cout << t++ << endl;

    cout << "Sau postfix ++: ";
    cout << t << endl;

    cout << "\nPrefix --:\n";
    cout << --t << endl;

    cout << "\nPostfix --:\n";
    cout << t-- << endl;

    cout << "Sau postfix --: ";
    cout << t << endl;

    return 0;
}
