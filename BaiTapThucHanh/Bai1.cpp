/*
Bài 1.	Viết chương trình tính chu vi và diện tích của một số hình học cơ bản: 
•	Yêu cầu người dùng nhập vào tên của hình muốn tính diện tích. Tên là một trong ba loại sau: tam giac, hinh chu nhat, hinh vuong. 
•	Sau khi người dùng nhập vào tên hình cần tính, yêu cầu người dùng nhập các thông tin cần thiết để tính chu vi và diện tích.
o	Với tam giác, yêu cầu nhập độ dài ba cạnh.
o	Với hình chữ nhật, yêu cầu nhập chiều dài và chiều rộng.
o	Với hình vuông, yêu cầu nhập độ dài cạnh.
•	Sau khi người dùng nhập đủ thông tin theo yêu cầu, kiểm tra dữ liệu nhập vào có phù hợp hay không. Nếu có, tính chu vi, diện tích và in kết quả ra màn hình.
*/

#include <iostream>
#include <string>
#include <cmath>

using namespace std;

int main() {
    string tenHinh;
    double canhA, canhB, canhC, chuVi, dienTich;

    cout << "Nhap ten hinh (tam giac, hinh chu nhat, hinh vuong): ";
    getline(cin, tenHinh);

    if (tenHinh == "tam giac") {
        cout << "Nhap do dai ba canh: ";
        cin >> canhA >> canhB >> canhC;

        // Kiểm tra điều kiện tam giác
        if (canhA + canhB > canhC && canhA + canhC > canhB && canhB + canhC > canhA && canhA > 0 && canhB > 0 && canhC > 0) {
            chuVi = canhA + canhB + canhC;
            double nCv = chuVi / 2.0; // Nửa chu vi
            dienTich = sqrt(nCv * (nCv - canhA) * (nCv - canhB) * (nCv - canhC)); 
        } else {
            cout << "Do dai ba canh khong hop le." << endl;
            return 1; 
        }
    } else if (tenHinh == "hinh chu nhat") {
        cout << "Nhap chieu dai va chieu rong: ";
        cin >> canhA >> canhB; // canhA là chiều dài, canhB là chiều rộng

        if (canhA > 0 && canhB > 0) {
            chuVi = 2 * (canhA + canhB);
            dienTich = canhA * canhB;
        } else {
            cout << "Chieu dai va chieu rong phai lon hon 0." << endl;
            return 1;
        }

    } else if (tenHinh == "hinh vuong") {
        cout << "Nhap do dai canh: ";
        cin >> canhA;

        if (canhA > 0) {
            chuVi = 4 * canhA;
            dienTich = canhA * canhA;
        } else {
            cout << "Do dai canh phai lon hon 0." << endl;
            return 1;
        }
    } else {
        cout << "Ten hinh khong hop le." << endl;
        return 1;
    }

    cout << "Chu vi: " << chuVi << endl;
    cout << "Dien tich: " << dienTich << endl;

    return 0;
}