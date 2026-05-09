#include "CDate.h"
#include <iostream>
using namespace std;
int main() {
    CDate d1, d2;

    cout << "Nhap ngay thu nhat:\n";
    cin >> d1;

    cout << "Nhap ngay thu hai:\n";
    cin >> d2;

    cout << "\nNgay thu nhat: " << d1 << endl;
    cout << "Ngay thu hai : " << d2 << endl;

    cout << "\nKhoang cach giua 2 ngay: ";
    cout << d2 - d1 << " ngay\n";

    int n; cout<<"Nhap so ngay cong them: "; cin>>n;
    cout << d1 + n << endl;

    int m; cout<<"Nhap so ngay bot di: "; cin>>m;
    cout << d2 - m << endl;

    ++d1;
    cout << "\nSau ++d1: " << d1 << endl;

    d2--;
    cout << "Sau d2--: " << d2 << endl;

    return 0;
}


