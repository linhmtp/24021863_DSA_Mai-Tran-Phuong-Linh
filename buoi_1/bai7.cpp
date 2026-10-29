#include <iostream>
#include <vector>
using namespace std;
int tinhTong(const vector<vector<int> > &a, int n, int m) {
    int tong = 0;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            tong += a[i][j];
        }
    }
    return tong;
}
void xoaDong(vector<vector<int> > &a, int &n, int i) {
    if (i < 0 || i >= n) {
        cout << "Chi so dong i khong hop le!" << endl;
        return;
    }
    a.erase(a.begin() + i);
    n--;
}
int main() {
    int n, m;
    cout << "Nhap so dong N: ";
    cin >> n;
    cout << "Nhap so cot M: ";
    cin >> m;
    if (n <= 0 || m <= 0) {
        cout << "Kich thuoc mang khong hop le!" << endl;
        return 0;
    }
    vector<vector<int> > a(n, vector<int>(m));
    cout << "Nhap cac phan tu cua mang 2 chieu:" << endl;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            cout << "a[" << i << "][" << j << "] = ";
            cin >> a[i][j];
        }
    }
    int tongPhanTu = tinhTong(a, n, m);
    cout << "\n--- CAU a: TINH TONG ---" << endl;
    cout << "Tong cac phan tu trong mang la: " << tongPhanTu << endl;
    int i_xoa;
    cout << "\n--- CAU b: XOA DONG ---" << endl;
    cout << "Nhap chi so dong i can xoa (tu 0 den " << n - 1 << "): ";
    cin >> i_xoa;
    xoaDong(a, n, i_xoa);
    cout << "Mang sau khi xoa dong " << i_xoa << " la:" << endl;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            cout << a[i][j] << "\t";
        }
        cout << endl;
    }

    return 0;
}
// Độ phức tạp thời gian: O(n * m)
// Độ phức tạp bộ nhớ: O(n * m)
