#include <iostream>
#include "CVector.h"
using namespace std;

int main()
{
    CVector A, B;
    cout<<"Vector A: "<<endl;
    cin>>A;

    cout<<"Vector B: "<<endl;
    cin>>B;

    cout<<"A + B = "<<A + B<<endl;
    cout<<"A - B = "<<A - B<<endl;

    double k;
    cout<<"Nhap so thuc k: ";
    cin>>k;
    cout<<"k * A = "<<A * k<<endl;

    cout<<"Tich vo huong cua A va B = "<<A*B<<endl;
    return 0;
}
