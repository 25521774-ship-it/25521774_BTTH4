#include <iostream>
#include "CMatrix.h"
#include <vector>
#include <exception>
using namespace std;

int main()
{
    CMatrix a,b;

    cout<<"---Nhap ma tran A---\n";
    cin>>a;
    cout<<"---Nhap ma tran B---\n";
    cin>>b;

    try
    {
        cout << a + b << endl;
    }
    catch (const exception& e)
    {
        cout << e.what() << endl;
    }

    try
    {
        cout << a - b << endl;
    }
    catch (const exception& e)
    {
        cout << e.what() << endl;
    }

    try
    {
        cout << a * b << endl;
    }
    catch (const exception& e)
    {
        cout << e.what() << endl;
    }

    vector<double>k;
    int n;
    cout<<"Nhap so phan tu vector k: ";
    cin>>n;
    k.resize(n);
    cout<<"Nhap vector k: ";
    for (int i = 0; i< n; i++)
    {
        cin>>k[i];
    }

    try
    {
        vector<double> result = a * k;

        cout<<"A * k = "<<endl;
        for (double x : result)
        {
            cout<< x << " ";
        }
        cout << endl;
    }
    catch (exception &e)
    {
        cout<<e.what() <<endl;
    }
    return 0;
}
