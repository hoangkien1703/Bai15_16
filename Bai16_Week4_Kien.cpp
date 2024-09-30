/*
Bài 16: Viết chương trình nhập vào vào mảng A có n phần tử, 
các phần tử là những số nguyên lớn hơn 0 và nhỏ hơn 100 được nhập vào từ bàn phím. 
Thực hiện các chức năng sau:
1. Tìm phần tử lớn nhất và lớn thứ 2 trong mảng cùng chỉ số của các số đó.
2. Sắp xếp mảng theo thứ tự giảm dần.
3. Nhập một số nguyên x và chèn x vào mảng A sao cho vẫn đảm bảo tính sắp xếp giảm dần.

*/

#include <iostream>
using namespace std;

void findTwoLagest(int a[], int n, int& lagest, int& lagestInx,int& secondlagest,int seconlagestInx){
    if (a[0] >a[1]){
        lagest = a[0];
        lagestInx = 0;
        secondlagest =a[1];
        seconlagestInx= 1;
    }
    else{
        lagest = a[1];
        lagestInx= 1;
        secondlagest = a[0];
        seconlagestInx = 0;
    }
    for (int i = 2; i < n; i++){
        if(a[i] > lagestInx){
            secondlagest=lagest;
            seconlagestInx=lagestInx;
            lagest = a[i];
            lagestInx= i;
        }else if (a[i] >secondlagest && a[i] !=lagest){
            secondlagest= a[i];
            seconlagestInx= i;
        }
   
    }
}

void sortDesc(int a[], int n){  
    for (int i = 0; i < n-1; i++){
        for (int j = i+1; j < n; j++){
            if(a[i] < a[j]){
                int temp = a[i];
                a[i] = a[j];
                a[j] = temp;
            }
        }
    }

}

void insertNumber(int a[], int& n, int x){
    int i= n-1;
    while(i>=0 && a[i] < x){
        a[i+1]= a[i];
        i--;
    }
    a[i+1] = x;
    n++;
}

void printArray(int a[], int n){
    for(int i = 0; i < n; i++){
        cout<< a[i]<< " ";
    }
    cout<< endl;
}
int main(){
    int n;
    int a[101]; //insert +1
    cout<<"Nhap so phan tu n (<100): ";
    cin>> n;
    cout<<"Nhap cac phan tu cua mang: ";
    
    if (n < 0||n >100){
        cerr << "So phan tu khong hop le. "<< endl;
        return -1;
    }
    cout<<"Nhap mang A:\n";
    for(int i = 0; i < n; i++){
        cin>> a[i];
    }
    int lagest, lagestInx, secondlagest, seconlagestInx;
    findTwoLagest(a, n, lagest, lagestInx, secondlagest, seconlagestInx);
    cout<<"Phan tu lon nhat: "<< lagest<< " tai vi tri "<< lagestInx<< endl;
    cout<<"Phan tu lon thu hai: "<< secondlagest<< " tai vi tri "<< seconlagestInx<< endl;

    sortDesc(a, n);
    cout<<"Mang sau khi sap xep giam dan:\n";
    printArray(a, n);

    int x;
    cout<<"Nhap so nguyen x can chen: ";
    cin>> x;
    insertNumber(a, n, x);
    cout<<"Mang sau khi chen x:\n";
    printArray(a, n);
    return 0;
    
    
}


