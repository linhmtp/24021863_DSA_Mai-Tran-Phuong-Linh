#include <iostream>
using namespace std;
void sapXepTangDan(int a[], int n) {
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (a[j] > a[j + 1]) {
                int temp = a[j];
                a[j] = a[j + 1];
                a[j + 1] = temp;
            }
        }
    }
}
int main() {
    int n;
    cout << "Nhap so luong phan tu N: ";
    cin >> n;
    int a[10000];
    cout << "Nhap cac phan tu cua day:\n";
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    sapXepTangDan(a, n);
    cout << "Day sau khi sap xep tang dan la:\n";
    for (int i = 0; i < n; i++) {
        cout << a[i] << " ";
    }
    cout << endl;
    return 0;
}
//Độ phức tạp thời gian: O(n^2)
//Độ phức tạp bộ nhớ:O(1) 
