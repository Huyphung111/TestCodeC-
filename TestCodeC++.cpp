#include <iostream>
using namespace std;

// Hàm kiểm tra số nguyên tố (prime number)
bool isPrime(int n) {
    if (n < 2) return false;
    for (int i = 2; i <= n / 2; i++) {
        if (n % i == 0)
            return false;
    }
    return true;
}

int main() {
    int n;
    cout << "Nhap so luong phan tu: ";
    cin >> n;

    int x, sum = 0;

    for (int i = 1; i <= n; i++) {
        cout << "Nhap so thu " << i << ": ";
        cin >> x;

        // Chẵn / lẻ
        if (x % 2 == 0)
            cout << x << " la so chan\n";
        else
            cout << x << " la so le\n";

        // Nguyên tố
        if (isPrime(x))
            cout << x << " la so nguyen to\n";

        sum += x;
        cout << "-------------------\n";
    }

    cout << "Tong cac so: " << sum << endl;

    return 0;
}
