#include <iostream>
#include <vector>
#include <string>
#include <cmath>
#include <algorithm>
#include <limits> // Để sử dụng numeric_limits

using namespace std;

// Bài 1: Tính chu vi và diện tích hình học
void bai1() {
    string ten_hinh;
    cout << "Nhap ten hinh (tam giac, hinh chu nhat, hinh vuong): ";
    cin >> ten_hinh;

    if (ten_hinh == "tam giac") {
        double a, b, c;
        cout << "Nhap do dai 3 canh: ";
        cin >> a >> b >> c;

        if (a + b > c && a + c > b && b + c > a) {
            double chu_vi = a + b + c;
            double p = chu_vi / 2; // Nửa chu vi
            double dien_tich = sqrt(p * (p - a) * (p - b) * (p - c)); // Công thức Heron
            cout << "Chu vi: " << chu_vi << endl;
            cout << "Dien tich: " << dien_tich << endl;
        } else {
            cout << "Ba canh khong tao thanh tam giac." << endl;
        }

    } else if (ten_hinh == "hinh chu nhat") {
        double chieu_dai, chieu_rong;
        cout << "Nhap chieu dai va chieu rong: ";
        cin >> chieu_dai >> chieu_rong;

        if (chieu_dai > 0 && chieu_rong > 0) {
            double chu_vi = 2 * (chieu_dai + chieu_rong);
            double dien_tich = chieu_dai * chieu_rong;
            cout << "Chu vi: " << chu_vi << endl;
            cout << "Dien tich: " << dien_tich << endl;
        } else {
            cout << "Chieu dai va chieu rong phai lon hon 0." << endl;
        }

    } else if (ten_hinh == "hinh vuong") {
        double canh;
        cout << "Nhap do dai canh: ";
        cin >> canh;

        if (canh > 0) {
            double chu_vi = 4 * canh;
            double dien_tich = canh * canh;
            cout << "Chu vi: " << chu_vi << endl;
            cout << "Dien tich: " << dien_tich << endl;
        } else {
            cout << "Canh phai lon hon 0." << endl;
        }

    } else {
        cout << "Ten hinh khong hop le." << endl;
    }
}


// Bài 2: Đếm số ước của n
void bai2() {
    int n;

    // Vòng lặp nhập liệu cho đến khi n hợp lệ
    do {
        cout << "Nhap so nguyen n (0 < n <= 100): ";
        cin >> n;
        if (cin.fail() || n <= 0 || n > 100) { // Kiểm tra nhập sai kiểu dữ liệu hoặc ngoài phạm vi
            cout << "Nhap sai. Vui long nhap lai." << endl;
            cin.clear(); // Xóa cờ lỗi
            cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Xóa bộ đệm
        }
    } while (n <= 0 || n > 100);

    int so_uoc = 0;
    for (int i = 1; i <= n; i++) {
        if (n % i == 0) {
            so_uoc++;
        }
    }
    cout << "So uoc cua " << n << " la: " << so_uoc << endl;
}

// Bài 3: Giải phương trình bậc 2
void bai3() {
    double a, b, c;
    cout << "Nhap a, b, c: ";
    cin >> a >> b >> c;

    if (a == 0) {
        if (b == 0) {
            if (c == 0) {
                cout << "Phuong trinh vo so nghiem." << endl;
            } else {
                cout << "Phuong trinh vo nghiem." << endl;
            }
        } else {
            cout << "Phuong trinh co nghiem x = " << -c / b << endl;
        }
    } else {
        double delta = b * b - 4 * a * c;
        if (delta < 0) {
            cout << "Phuong trinh vo nghiem." << endl;
        } else if (delta == 0) {
            cout << "Phuong trinh co nghiem kep x = " << -b / (2 * a) << endl;
        } else {
            cout << "Phuong trinh co 2 nghiem phan biet:" << endl;
            cout << "x1 = " << (-b + sqrt(delta)) / (2 * a) << endl;
            cout << "x2 = " << (-b - sqrt(delta)) / (2 * a) << endl;
        }
    }
}



// Bài 4: Kiểm tra tam giác và tính chu vi, diện tích
void bai4() {
    double a, b, c;
    cout << "Nhap 3 canh a, b, c: ";
    cin >> a >> b >> c;

    if (a + b > c && a + c > b && b + c > a) {
        double chu_vi = a + b + c;
        double p = chu_vi / 2; // Nửa chu vi
        double dien_tich = sqrt(p * (p - a) * (p - b) * (p - c)); // Công thức Heron

        cout << "Chu vi: " << chu_vi << endl;
        cout << "Dien tich: " << dien_tich << endl;


        if (a == b && b == c) {
            cout << "Tam giac deu." << endl;
        } else if (a == b || a == c || b == c) {
            cout << "Tam giac can." << endl;
        } else {
            cout << "Tam giac thuong." << endl;
        }
    } else {
        cout << "Ba canh khong tao thanh tam giac." << endl;
    }
}


// Bài 5: Xử lý mảng 2 chiều
void bai5() {
    int m, n;
    cout << "Nhap so hang m va so cot n: ";
    cin >> m >> n;

    vector<vector<int>> mang_2chieu(m, vector<int>(n));

    // a) Nhập và xuất mảng
    cout << "Nhap cac phan tu cua mang:" << endl;
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            cin >> mang_2chieu[i][j];
        }
    }

    cout << "Mang vua nhap:" << endl;
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            cout << mang_2chieu[i][j] << "\t";
        }
        cout << endl;
    }

    // b) Chuyển các phần tử không chẵn thành 0
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            if (mang_2chieu[i][j] % 2 != 0) {
                mang_2chieu[i][j] = 0;
            }
        }
    }

    cout << "Mang sau khi chuyen cac phan tu le thanh 0:" << endl;
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            cout << mang_2chieu[i][j] << "\t";
        }
        cout << endl;
    }

        // Chuyển ma trận thành mảng 1 chiều để sắp xếp
    vector<int> mang_1chieu;
    for(int i=0; i<m; ++i) {
        for(int j=0; j<n; ++j) {
            mang_1chieu.push_back(mang_2chieu[i][j]);
        }
    }


    // c) Sắp xếp mảng giảm dần và chèn X
    sort(mang_1chieu.begin(), mang_1chieu.end(), greater<int>());

    int x;
    cout << "Nhap gia tri x can chen: ";
    cin >> x;

    // Tìm vị trí chèn x để mảng vẫn giảm dần
    auto it = upper_bound(mang_1chieu.begin(), mang_1chieu.end(), x, greater<int>());
    mang_1chieu.insert(it, x);

    cout << "Mang sau khi sap xep giam dan va chen x:" << endl;
       for (int val : mang_1chieu) {
        cout << val << " ";
    }
    cout << endl;

}




int main() {
    int lua_chon;
    do {
        cout << "\nChon bai tap (1-5, 0 de thoat): ";
        cin >> lua_chon;

        switch (lua_chon) {
            case 1: bai1(); break;
            case 2: bai2(); break;
            case 3: bai3(); break;
            case 4: bai4(); break;
            case 5: bai5(); break;
            case 0: cout << "Thoat chuong trinh." << endl; break;
            default: cout << "Lua chon khong hop le." << endl;
        }
    } while (lua_chon != 0);

    return 0;
}