#include <iostream>
#include "PhanSo.h"
using namespace std;

int main()
{
    PhanSo a, b;

    cout<<"Nhap phan so A: "<<endl;
    cin>> a;

    cout<<"Nhap phan so B: "<<endl;
    cin>>b;

    cout<<"a = "<<a<<endl;
    cout<<"b = "<<b<<endl;

    cout<<"a + b = "<<a + b<<endl;
    cout<<"a - b = "<<a - b<<endl;
    cout<<"a * b = "<<a * b<<endl;
    cout<<"a / b = "<<a /  b<<endl;

    if (a == b) cout<<"a = b"<<endl;
    else if (a > b) cout<<"a > b"<<endl;
    else cout<<"a < b"<<endl;

    return 0;
}
