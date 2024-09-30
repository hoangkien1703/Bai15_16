#include <iostream>
#include <cmath>

using namespace std;

// Hàm kiểm tra số nguyên tố
bool isPrime(int n) {
    if (n <= 1) return false;
    for (int i = 2; i <= sqrt(n); i++) {
        if (n % i == 0) return false;
    }
    return true;
}

// Hàm tìm phần tử lớn nhất và chỉ số của nó
void findMax(int (&a)[100][100], int n, int m, int &maxVal, int &rowIndex, int &colIndex) {
    maxVal = a[0][0];
    rowIndex = 0;
    colIndex = 0;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (a[i][j] > maxVal) {
                maxVal = a[i][j];
                rowIndex = i;
                colIndex = j;
            }
        }
    }
}


// Hàm sắp xếp cột theo thứ tự tăng dần
void sortColumns(int (&a)[100][100], int n, int m) {
    for (int j = 0; j < m; j++) {
        for (int i = 0; i < n - 1; i++) {
            for (int k = i + 1; k < n; k++) {
                if (a[i][j] > a[k][j]) {
                    int temp = a[i][j];
                    a[i][j] = a[k][j];
                    a[k][j] = temp;
                }
            }
        }
    }
}

// Hàm tìm và thay thế các phần tử không nguyên tố bằng 0
void replaceNonPrimes(int (&a)[100][100], int n, int m) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (!isPrime(a[i][j])) {
                a[i][j] = 0;
            }
        }
    }
}

// Hàm in ma trận
void printMatrix(int (&a)[100][100], int n, int m) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cout << a[i][j] << " ";
        }
        cout << endl;
    }
}

int main() {
    int n, m;
    int a[100][100];

    cout << "Nhap so dong n: ";
    cin >> n;
    cout << "Nhap so cot m: ";
    cin >> m;

    cout << "Nhap ma tran A:\n";
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> a[i][j];
        }
    }

    int maxVal, rowIndex, colIndex;
    findMax(a, n, m, maxVal, rowIndex, colIndex);
    cout << "Phan tu lon nhat: " << maxVal << " tai vi tri (" << rowIndex << ", " << colIndex << ")" << endl;

    int b[100][100]; // Tạo bản sao
    for(int i=0; i<n; ++i) {
        for(int j=0; j<m; ++j) {
            b[i][j] = a[i][j];
        }
    }

    replaceNonPrimes(b, n, m); // Thay thế trên bản sao b
    cout << "Ma tran sau khi thay the cac phan tu khong nguyen to bang 0:\n";
    printMatrix(b, n, m);

    sortColumns(a, n, m); // Sắp xếp trên ma trận gốc a
    cout << "Ma tran sau khi sap xep cac cot theo thu tu tang dan:\n";
    printMatrix(a, n, m);

    sortColumns(b, n, m); // Sắp xếp ma trận b
    cout << "Ma tran chi co so nguyen tố sau khi sap xep cac cot theo thu tu tang dan:\n";
    printMatrix(b, n, m);

    return 0;
}