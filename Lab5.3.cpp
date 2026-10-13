// Лабораторна робота № 5.3

#include <iostream>
#include <iomanip>
#include <cmath>

using namespace std;

double h(const double x);

int main()
{
    double qp, qk, q, z;
    int n;

    cout << "qp = "; cin >> qp;
    cout << "qk = "; cin >> qk;
    cout << "n = ";  cin >> n;

    if (n <= 0)
    {
        cout << "Error: n must be positive" << endl;
        return 1;
    }

    double dq = (qk - qp) / n;

    cout << fixed;
    cout << "Table of values of z(q)" << endl;
    cout << "-----------------------------" << endl;
    cout << "| " << setw(10) << "q"
        << " | " << setw(12) << "z" << " |" << endl;
    cout << "-----------------------------" << endl;

    for (int i = 0; i <= n; i++)
    {
        q = qp + i * dq;
        z = h(q + 1) + h(q * q + 1) + pow(h(q * q), 2);

        cout << "| " << setw(10) << setprecision(4) << q
            << " | " << setw(12) << setprecision(6) << z << " |" << endl;
    }
    cout << "-----------------------------" << endl;

    return 0;
}

double h(const double x)
{
    if (fabs(x) >= 1)
        return (cos(x) + 1) / (cos(x) * cos(x) + 1);
    else
    {
        double a = 1;       // доданок при i = 0
        double s = a;
        for (int i = 1; i <= 6; i++)
        {
            double R = x * x / ((2. * i - 1) * (2. * i));
            a *= R;         // рекурентне співвідношення
            s += a;
        }
        return s / cos(x);
    }
}
