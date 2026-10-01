#include <iostream>
#include <vector>
using namespace std;
int main() {
    int n;
    cout << "Nhap vao do dai cua day: ";
    cin >> n;
    vector<double> a(n);
    double tong = 0;
    cout << "Nhap cac phan tu cua day so thuc:" << endl;
    for (int i = 0; i < n; ++i) {
        cout << "a[" << i << "] = ";
        cin >> a[i];
        tong += a[i];
    }
    double trung_binh = tong / n;
    cout << "\nGia tri trung binh cua day la: " << trung_binh << endl;
    cout << "Cac gia tri lon hon hoac bang gia tri trung binh gom:" << endl;
    bool found = false;
    for (int i = 0; i < n; ++i) {
        if (a[i] >= trung_binh) {
            cout << a[i] << " ";
            found = true;
        }
    }
    if (!found) {
        cout << "Khong co phan tu nao thoa man.";
    }
    cout << endl;
    return 0;
}
// Độ phức tạp thời gian: O(n)
// Độ phức tạp bộ nhớ: O(n)
