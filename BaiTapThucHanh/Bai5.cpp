#include <iostream>

using namespace std;

int main() {
    int m, n;

    // a) Nhập và xuất mảng
    cout << "Nhap so hang m: ";
    cin >> m;
    cout << "Nhap so cot n: ";
    cin >> n;

    int arr[100][100]; // Giới hạn kích thước mảng (cần xử lý nếu m, n lớn hơn)

    cout << "Nhap cac phan tu cua mang:\n";
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            cin >> arr[i][j];
        }
    }

    cout << "Mang vua nhap:\n";
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            cout << arr[i][j] << " ";
        }
        cout << endl;
    }

    // b) Chuyển số lẻ thành 0
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            if (arr[i][j] % 2 != 0) {
                arr[i][j] = 0;
            }
        }
    }

    cout << "Mang sau khi chuyen so le thanh 0:\n";
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            cout << arr[i][j] << " ";
        }
        cout << endl;
    }


    // c) Sắp xếp giảm dần và chèn X
    int temp;
    for (int i = 0; i < m * n - 1; i++) {
        for (int j = i + 1; j < m * n; j++) {
            int row1 = i / n;
            int col1 = i % n;
            int row2 = j / n;
            int col2 = j % n;

            if (arr[row1][col1] < arr[row2][col2]) {
                temp = arr[row1][col1];
                arr[row1][col1] = arr[row2][col2];
                arr[row2][col2] = temp;
            }
        }
    }

    cout << "Mang sau khi sap xep giam dan:\n";
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            cout << arr[i][j] << " ";
        }
        cout << endl;
    }

    int x;
    cout << "Nhap gia tri X can chen: ";
    cin >> x;

    int newArr[100][100];
    int row = 0, col = 0;
    bool inserted = false;

    for (int i = 0; i < m * n; i++) {
        int oldRow = i / n;
        int oldCol = i % n;

        if (!inserted && x >= arr[oldRow][oldCol]) {
            newArr[row][col] = x;
            inserted = true;
        } else {
            newArr[row][col] = arr[oldRow][oldCol];  // Sao chép phần tử từ mảng cũ
            if(inserted){
                oldRow = (i)/n; //reset the oldRow index after insertion to avoid skip values.
                oldCol = (i)%n;
            }

        }

        col++;                // Tăng cột
        if (col == n) {      // Nếu cột đạt đến giới hạn
            col = 0;          // Đặt lại cột về 0
            row++;            // Tăng hàng
        }


    }

    if (!inserted) {     // Nếu x nhỏ hơn tất cả các phần tử
        newArr[m-1][n-1] = x;    // Thêm x vào cuối mảng
    }


    cout << "Mang sau khi chen X:\n";
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            cout << newArr[i][j] << " ";
        }
        cout << endl;
    }

    return 0;
}