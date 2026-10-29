#include <iostream>
using namespace std;
int main() {
    int n;
    cout << "Nhap so luong phan tu ";
    cin >> n;
    int a[1000]; 
    long long sum = 0;
    cout << "Nhap cac phan tu:\n";
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        sum += a[i];
    }
    cout << "Tong cac phan tu la: " << sum << endl;
    return 0;
}
//Độ phức tạp thời gian:O(n)
//Độ phức tạp bộ nhớ: O(1)
