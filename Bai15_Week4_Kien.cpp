/*
Bài 15: Viết chương trình nhập vào vào ma trận A có n dòng, m cột, 
các phần tử là những số nguyên lớn hơn 0 và nhỏ hơn 100 được nhập vào từ bàn phím. 
Thực hiện các chức năng sau:
1. Tìm phần tử lớn nhất của ma trận cùng chỉ số của số đó.
2. Tìm và in ra các phần tử là số nguyên tố của ma trận (các phần tử không nguyên tố thì thay bằng số 0).
3. Sắp xếp tất cả các cột của ma trận theo thứ tự tăng dần và in kết quả ra màn hình.
*/

#include <iostream>
#include <cmath>

using namespace std;

void findMaxInx(int (&a)[100][100], int n, int m, int &maxVal, int &rowInx, int &colInx){
    maxVal = a[0][0];
    rowInx = 0;
    colInx = 0;
    for (int i=0; i<n;i++){
        for (int j=0; j<m; j++){
            if (a[i][j]>maxVal){
                maxVal = a[i][j];
                rowInx = i;
                colInx = j;
            }

        }

    }
}

bool isPrime(int n){
    if (n <=1 ) return false;
    for (int i= 2; i < sqrt(n); i++){
        if (n %i == 0){
            return false;
        }
        
    }
    return true;

}

void sortCollumnsAsc(int (&a)[100][100], int n, int m){
    for (int j = 0; j< m; j++){
        for (int i= 0; i < n; i++){
            for (int k= i+1; k < n; k++){
                if (a[i][j]> a[k][j]){
                    int temp= a[i][j];
                    a[i][j] = a[k][j];
                    a[k][j] =temp;
                }
            }
        }

    }
}

void replaceNonPrime(int (&a)[100][100],int n, int m){
    for (int i = 0; i < n; i++){
        for (int j = 0;j < m; j++){
            if (!isPrime(a[i][j])){
                a[i][j] = 0;
            }
        }
}
}

void print(int (&a)[100][100], int n, int m){
    for (int i= 0; i < n; i++){
        for (int j = 0;j < m; j++){
            cout << a[i][j] << " ";
        }
        cout <<  endl;
    }
}

int main(){
    int n,m;
    int a[100][100];

    cout << "Nhap so dong n: ";
    cin >> n;
    cout << "Nhap so cot m: ";
    cin >> m;
    if (n < 0||n >100){
        cerr << "So phan tu khong hop le. "<< endl;
        return -1;
    }
    
    cout << "Nhap ma tran A:\n";
    for (int i=0;i<n; i++){
        for (int j=0; j<m; j++){
            cin>> a[i][j];
        }
    }
    int maxVal, rowInx, colInx;
    findMaxInx(a, n, m, maxVal, rowInx, colInx);
    cout<< "Phan tu lon nhat: "<<maxVal << " tai vi tri ("<< rowInx<<", "<< colInx<<")"<< endl;

    int b[100][100]; // Make copy of a[][]
    for (int i= 0;i < n; i++) {
        for (int j = 0; j< m; j++) {
            b[i][j] = a[i][j];
        }
    }

    replaceNonPrime(b, n, m);
    cout << "Ma tran sau khi thay the cac phan tu khong phai la so nguyen to bang 0:\n";
    print(b, n, m);

    sortCollumnsAsc(a, n, m);
    cout << "Ma tran sau khi sap xep cac cot theo thu tu tang dan:\n";
    print(a, n, m);

    sortCollumnsAsc(b,n,m); // Option
    cout << "Ma tran chi co so nguyen tố sau khi sap xep cac cot theo thu tu tang dan:\n";
    print(b, n, m);

    return 0;


}

