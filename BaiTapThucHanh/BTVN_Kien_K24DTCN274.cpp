#include <iostream>
#include <string>
#include <cmath>


using namespace std;

void baiTap1() {
    string tenHinh;
    double canhA, canhB, canhC, chuVi, dienTich;
    cout <<"Nhap ten hinh (tam giac, hinh chu nhat, hinh vuong): ";
    getline(cin, tenHinh);

    if (tenHinh == "tam giac") {
        cout <<"Nhap do dai ba canh: ";
        cin>> canhA >>canhB>> canhC;

        
        if(canhA + canhB > canhC && canhA+ canhC >canhB&& canhB + canhC>canhA && canhA> 0 && canhB > 0 && canhC > 0) {
            chuVi = canhA + canhB + canhC;
            double nCv =chuVi / 2.0;
            dienTich =sqrt(nCv * (nCv - canhA) * (nCv - canhB) * (nCv - canhC)); 
        }else{
            cout << "Do dai ba canh khong hop le." << endl;
            return; 
        }
    }else if (tenHinh == "hinh chu nhat") {
        cout << "Nhap chieu dai va chieu rong: ";
        cin >> canhA >> canhB; 
        if (canhA > 0 &&canhB> 0) {
            chuVi = 2*(canhA + canhB);
            dienTich = canhA * canhB;
        } else{
            cout << "Chieu dai va chieu rong phai lon hon 0." << endl;
            return;
        }

    } else if(tenHinh == "hinh vuong") {
        cout<< "Nhap do dai canh: ";
        cin>> canhA;

        if (canhA > 0) {
            chuVi = 4 * canhA;
            dienTich = canhA * canhA;
        }else {
            cout<< "Do dai canh phai lon hon 0." << endl;
            return;
        }
    }else {
        cout << "Ten hinh khong hop le." << endl;
        return;
    }

    cout<< "Chu vi: " << chuVi << endl;
    cout<< "Dien tich: "<< dienTich << endl;
}

void baiTap2(){
    int n;

    do {
        cout << "Nhap so nguyen n (0 < n <= 100): ";
        cin >> n;
    } while (n <= 0 || n > 100);

    int soUoc = 0;
    for (int i = 1; i <= n; ++i) {
        if (n % i == 0) {
            soUoc++;
        }
    }

    cout <<"So uoc cua "<< n <<" la: "<<soUoc << endl;
}

void baiTap3() {
    double a,b,c;

    cout << "Nhap a, b, c cua phuong trinh ax^2 + bx + c = 0: ";
    cin>> a >> b >> c;

    if(a == 0){
        if (b == 0) {
            if (c == 0) {
                cout << "Phuong trinh vo so nghiem." << endl;
            } else {
                cout << "Phuong trinh vo nghiem." << endl;
            }
        } else {
            cout << "Phuong trinh co mot nghiem: x = " << -c / b << endl;
        }
    }else {
        double delta = b * b - 4 * a * c;
        if(delta < 0) {
            cout << "Phuong trinh vo nghiem." << endl;
        }else if (delta == 0) {
            cout << "Phuong trinh co nghiem kep: x = " << -b / (2 * a) << endl;
        }else {
            cout << "Phuong trinh co hai nghiem phan biet:" << endl;
            cout << "x1 = " << (-b + sqrt(delta)) / (2 * a) << endl;
            cout << "x2 = " << (-b - sqrt(delta)) / (2 * a) << endl;
        }
    }
}

void baiTap4() {
    double a,b,c,chuVi, dienTich, nCv;

    cout<< "Nhap ba canh a, b, c cua tam giac: ";
    cin>> a >> b >> c;

    if(a + b > c && a + c > b && b + c > a && a > 0 && b > 0 && c > 0) {
        chuVi = a + b + c;
        nCv = chuVi / 2;
        dienTich = sqrt(nCv * (nCv - a) * (nCv - b) * (nCv - c));

        cout << "Chu vi: " << chuVi << endl;
        cout << "Dien tich: " << dienTich << endl;

        if (a == b && b == c) {
            cout << "Tam giac deu." << endl;
        } else if (a == b || a == c || b == c) {
            cout << "Tam giac can." << endl;
        } else {
            cout << "Tam giac thuong." << endl;
        }
    }else {
        cout << "Ba canh khong tao thanh tam giac." << endl;
    }
}

//--baiTap5


void nhapMang(int** a, int m, int n) {
    for(int i = 0; i < m; i++){
        for(int j = 0; j < n; j++) {
            cout<< "Nhap phan tu a[" << i << "][" << j << "]: ";
            cin>> a[i][j];
        }
    }
}


void xuatMang(int** a, int m, int n) {
    for(int i = 0; i < m; i++) {
        for(int j = 0; j < n; j++) {
            cout << a[i][j] << " ";
        }
        cout << endl;
    }
}


void chuyenLeThanh0(int** a, int m, int n) {
    for(int i = 0; i < m; i++) {
        for(int j = 0; j < n; j++) {
            if (a[i][j] % 2 != 0) {
                a[i][j] = 0;
            }
        }
    }
}


void sapXepGiam(int** a, int m, int n) {
    for(int i = 0; i<m; i++) {
        for(int j = 0; j<n; j++) {
            for (int k = 0; k < m; k++) {
                for(int l = 0; l< n; l++) {
                    if (a[i][j] > a[k][l]) {
                        int temp =a[i][j];
                        a[i][j]=a[k][l];
                        a[k][l]=temp;
                    }
                }
            }
        }
    }
}


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

void baiTap5() {

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
}


int main() {
    
     int luaChon;

    do {
        cout << "\nMENU:\n";
        cout << "1. Bai tap 1 (Tinh chu vi, dien tich hinh hoc)\n";
        cout << "2. Bai tap 2 (Dem so uoc)\n";
        cout << "3. Bai tap 3 (Giai phuong trinh bac 2)\n";
        cout << "4. Bai tap 4 (Kiem tra tam giac)\n";
        cout << "5. Bai tap 5 (Xu ly mang 2 chieu)\n";
        cout << "0. Thoat\n";
        cout << "Nhap lua chon cua ban: ";
        cin >> luaChon;
        cin.ignore(); // Xóa bộ nhớ đệm

        switch (luaChon) {
            case 1: baiTap1(); break;
            case 2: baiTap2(); break;
            case 3: baiTap3(); break;
            case 4: baiTap4(); break;
            case 5: baiTap5(); break;
            case 0: cout << "Thoat chuong trinh.\n"; break;
            default: cout << "Lua chon khong hop le. Vui long nhap lai.\n";
        }
    } while (luaChon != 0);

    return 0;
}