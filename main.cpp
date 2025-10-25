#include <iostream>
#include "Thoigian.h"
using namespace std;

int main() {
    cout << "=== TEST CLASS DATE ===" << endl;
    Date d;
    cin >> d;
    cout << "Ngay vua nhap: " << d << endl;
    cout << "Tang 1 ngay: " << ++d << endl;
    cout << "Giam 1 ngay: " << --d << endl;

    cout << "\n=== TEST CLASS TIME ===" << endl;
    Time t;
    cin >> t;
    cout << "Thoi gian vua nhap: " << t << endl;
    cout << "Tang 1 giay: " << ++t << endl;
    cout << "Giam 1 giay: " << --t << endl;

    cout << "\n=== TEST CLASS DATETIME ===" << endl;
    DateTime dt;
    cin >> dt;
    cout << "Ngay gio vua nhap: " << dt << endl;
    cout << "Tang 1 giay: " << ++dt << endl;
    cout << "Giam 1 giay: " << --dt << endl;

    return 0;
}
