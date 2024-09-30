#include <iostream>

using namespace std;

// Hàm tìm phần tử lớn nhất và lớn thứ hai
void findTwoLargest(int a[], int n, int& largest, int& largestIndex, int& secondLargest, int& secondLargestIndex) {
    if (n < 2) {
        cerr << "Mang phai co it nhat 2 phan tu." << endl;
        return;
    }

    // Khởi tạo largest và secondLargest bằng hai phần tử đầu tiên của mảng
    if (a[0] > a[1]) {
        largest = a[0];
        largestIndex = 0;
        secondLargest = a[1];
        secondLargestIndex = 1;
    } else {
        largest = a[1];
        largestIndex = 1;
        secondLargest = a[0];
        secondLargestIndex = 0;
    }

    for (int i = 2; i < n; i++) {
        if (a[i] > largest) {
            secondLargest = largest;
            secondLargestIndex = largestIndex;
            largest = a[i];
            largestIndex = i;
        } else if (a[i] > secondLargest && a[i] != largest) {
            secondLargest = a[i];
            secondLargestIndex = i;
        }
    }
}

// Hàm sắp xếp mảng giảm dần (Selection Sort)
void sortDescending(int a[], int n) {
    for (int i = 0; i < n - 1; i++) {
        for (int j = i + 1; j < n; j++) {
            if (a[i] < a[j]) {
                swap(a[i], a[j]);
            }
        }
    }
}


// Hàm chèn phần tử x vào mảng đã sắp xếp giảm dần
void insertSorted(int a[], int& n, int x) {
    int i = n - 1; // Bắt đầu từ phần tử cuối cùng của mảng

    while (i >= 0 && a[i] < x) {

        a[i + 1] = a[i]; // Dịch chuyển các phần tử lớn hơn x sang phải
        i--;
    }

    a[i + 1] = x; // Chèn x vào vị trí đúng
    n++;           // Tăng kích thước mảng
}

// Hàm in mảng
void printArray(const int* a, int n) {
    for (int i = 0; i < n; i++) {
        cout << a[i] << " ";
    }
    cout << endl;
}

int main() {
    int n;
    int a[101]; // Khai báo mảng với kích thước tối đa +1 để chèn thêm phần tử

    cout << "Nhap so phan tu n (<= 100): ";
    cin >> n;

    if (n <= 0 || n > 100) {
        cerr << "So phan tu khong hop le." << endl;
        return 1;
    }

    cout << "Nhap mang A:\n";
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    int largest, largestIndex, secondLargest, secondLargestIndex;
    findTwoLargest(a, n, largest, largestIndex, secondLargest, secondLargestIndex);


    if (n >= 2) { // Chỉ in nếu mảng có ít nhất 2 phần tử
        cout << "Phan tu lon nhat: " << largest << " tai index " << largestIndex << endl;
        cout << "Phan tu lon thu hai: " << secondLargest << " tai index " << secondLargestIndex << endl;
    }


    sortDescending(a, n);
    cout << "Mang sau khi sap xep giam dan:\n";
    printArray(a, n);

    int x;
    cout << "Nhap so nguyen x can chen: ";
    cin >> x;

    insertSorted(a, n, x);
    cout << "Mang sau khi chen x va sap xep:\n";
    printArray(a, n);

    return 0;
}