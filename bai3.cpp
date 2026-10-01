#include <iostream>
using namespace std;
int main() {
    int n;
    cout << "Nhap vao mot so nguyen n: ";
    cin >> n;
    long long giai_thua = 1;
    for (int i = 1; i <= n; ++i) {
        giai_thua *= i;
    }
    cout << n << "! = " << giai_thua << endl;
    return 0;
}
//Độ phức tạp thời gian: O(n)
//Độ phức tạp bộ nhớ:O(1) 
