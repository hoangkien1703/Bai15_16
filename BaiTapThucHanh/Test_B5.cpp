#include <iostream>
using namespace std;

// Hàm nhập mảng 2 chiều
void nhapMang(int** a, int m, int n) {
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            cout << "Nhap phan tu a[" << i << "][" << j << "]: ";
            cin >> a[i][j];
        }
    }
}

// Hàm xuất mảng 2 chiều
void xuatMang(int** a, int m, int n) {
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            cout << a[i][j] << " ";
        }
        cout << endl;
    }
}

// Hàm chuyển các phần tử không phải số chẵn thành 0
void chuyenLeThanh0(int** a, int m, int n) {
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            if (a[i][j] % 2 != 0) {
                a[i][j] = 0;
            }
        }
    }
}

// Hàm sắp xếp mảng giảm dần
void sapXepGiam(int** a, int m, int n) {
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            for (int k = 0; k < m; k++) {
                for (int l = 0; l < n; l++) {
                    if (a[i][j] > a[k][l]) {
                        int temp = a[i][j];
                        a[i][j] = a[k][l];
                        a[k][l] = temp;
                    }
                }
            }
        }
    }
}

// Hàm chèn X vào mảng làm sao mảng vẫn giảm dần
void chenX(int** a, int m, int n, int X) {
    int* b = new int[m * n + 1];
    int k = 0;
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            b[k++] = a[i][j];
        }
    }
    b[k] = X;
    sapXepGiam(&b, 1, m * n + 1);
    k = 0;
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            a[i][j] = b[k++];
        }
    }
    delete[] b;
}

int main() {
    int m, n;
    cout << "Nhap so dong (m): ";
    cin >> m;
    cout << "Nhap so cot (n): ";
    cin >> n;

    int** a = new int*[m];
    for (int i = 0; i < m; i++) {
        a[i] = new int[n];
    }

    nhapMang(a, m, n);
    cout << "Mang vua nhap:" << endl;
    xuatMang(a, m, n);

    chuyenLeThanh0(a, m, n);
    cout << "Mang sau khi chuyen le thanh 0:" << endl;
    xuatMang(a, m, n);

    sapXepGiam(a, m, n);
    cout << "Mang sau khi sap xep giam dan:" << endl;
    xuatMang(a, m, n);

    int X;
    cout << "Nhap X: ";
    cin >> X;
    chenX(a, m, n, X);
    cout << "Mang sau khi chen X:" << endl;
    xuatMang(a, m, n);

    for (int i = 0; i < m; i++) {
        delete[] a[i];
    }
    delete[] a;

    return 0;
}