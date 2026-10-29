#include <iostream>
#include <cmath>
using namespace std;
int timUCLN(int x, int y) {
    x = abs(x);
    y = abs(y);
    while (y != 0) {
        int temp = y;
        y = x % y;
        x = temp;
    }
    return x;
}
void rutGonPhanSo(int &a, int &b) {
    if (a == 0) {
        b = 1;
        return;
    }
    int ucln = timUCLN(a, b);
    a /= ucln;
    b /= ucln;
    if (b < 0) {
        a = -a;
        b = -b;
    }
}

int main() {
    int a, b;
    cout << "Nhap vao tu so (a): ";
    cin >> a;
    cout << "Nhap vao mau so (b): ";
    cin >> b;
    cout << "Phan so ban dau: " << a << "/" << b << endl;
    rutGonPhanSo(a, b);
    if (b != 0) {
        cout << "Phan so sau khi rut gon: " << a << "/" << b << endl;
    }
    return 0;
}
// Độ phức tạp thời gian: O(log(min(a, b)))
// Độ phức tạp bộ nhớ: O(1)
