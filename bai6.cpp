#include <iostream>
#include <vector>

using namespace std;

void xoaPhanTu(vector<int> &a, int &n, int k) {
    if (k < 0 || k >= n) {
        cout << "Vi tri k khong hop le!" << endl;
        return;
    }
    for (int i = k; i < n - 1; ++i) {
        a[i] = a[i + 1];
    }
    n--; 
    a.pop_back(); 
}

void chenPhanTu(vector<int> &a, int &n, int m, int y) {
    if (m < 0 || m > n) {
        cout << "Vi tri m khong hop le!" << endl;
        return;
    }
    a.push_back(0); 
    
    for (int i = n; i > m; --i) {
        a[i] = a[i - 1];
    }
    a[m] = y; 
    n++; 
} 
int main() {
    int n;
    cout << "Nhap vao so luong phan tu N: ";
    cin >> n;
    
    vector<int> a(n);
    cout << "Nhap cac phan tu cua day:" << endl;
    for (int i = 0; i < n; ++i) {
        cout << "a[" << i << "] = ";
        cin >> a[i];
    }
    int k;
    cout << "Nhap vi tri k can xoa (tu 0 den " << n - 1 << "): ";
    cin >> k;
    xoaPhanTu(a, n, k);
    
    cout << "Day sau khi xoa: ";
    for (int i = 0; i < n; ++i) {
        cout << a[i] << " ";
    }
    cout << endl;

    int m, y;
    cout << "Nhap gia tri y can chen: ";
    cin >> y;
    cout << "Nhap vi tri m can chen (tu 0 den " << n << "): ";
    cin >> m;
    chenPhanTu(a, n, m, y);
    
    cout << "Day sau khi chen: ";
    for (int i = 0; i < n; ++i) {
        cout << a[i] << " ";
    }
    cout << endl;

    return 0;
}
