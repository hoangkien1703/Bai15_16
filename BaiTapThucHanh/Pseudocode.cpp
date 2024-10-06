#include <iostream>
#include <string>
#include <cmath>

using namespace std;


void bai1() { string tenhinh;double  canha,  b,c,  chuvi, dientich;cout<<"Nhap ten hinh (tam giac, hinh chu nhat, hinh vuong): ";getline(cin,tenhinh);if(tenhinh=="tam giac"){cout<<"Nhap do dai ba canh: "; cin>>canha>>b>>c;if(canha+b>c&&canha+c>b&&b+c>canha&&canha>0&&b>0&&c>0){
chuvi=canha+b+c;double  nuaCV=chuvi/2;dientich =sqrt(nuaCV*(nuaCV-canha)*(nuaCV-b)*(nuaCV-c));
}else{cout<<"Do dai ba canh khong hop le."<<endl;return;}}else if   (tenhinh== "hinh chu nhat")
{cout<<"Nhap chieu dai va chieu rong: ";cin>>canha>>b;if(canha>0&&b>0)      {chuvi = 2*(canha+b);
    dientich=canha*b;}
    else{
        cout<<"Chieu dai va chieu rong phai lon hon 0."<<endl;
        return;
    }}else if(tenhinh=="hinh vuong"){
        cout<<"Nhap do dai canh: ";cin>>  canha;
        if(canha >0){chuvi= 4*canha;dientich=canha*  canha;}
        else{cout<<"Do dai canh phai lon hon 0."<<endl;return;
        }
    }
    else{cout<<"Ten hinh khong hop le."<<endl; return;}cout<<"Chu vi: "<<chuvi<<endl;cout<<"Dien tich: "<<dientich<<endl;}void    bt2(){int n;do{cout<<"Nhap so nguyen n (0 < n <= 100): ";cin>>n;}while(n<=0||n>100);
    int  soluoc =0;for(int i=1;i<=n;i++){if(n%i==0){soluoc++;
    }}cout<<"So uoc cua "<<  n<<" la: "  <<soluoc <<endl;}
void  bai_3(){
double a, b,  c;cout<<"Nhap a, b, c cua phuong trinh ax^2 + bx + c = 0: "; cin>>a>>b>>c;if(a==0){
        if (b==0){if(c==0){ cout<<"Phuong trinh vo so nghiem."<<endl;}
            else{cout <<"Phuong trinh vo nghiem."<<endl;}
        }else{ cout<<"Phuong trinh co mot nghiem: x = "<< -c/b<<endl;
}
    }
    else {double delta = b*b-4*a*c;
        if(delta<0)
{cout<<"Phuong trinh vo nghiem."<<endl;}else    if(delta==0)
{
    cout<<"Phuong trinh co nghiem kep: x = "<<-b/(2*a)<<endl;}else{cout<<"Phuong trinh co hai nghiem phan biet:"<<endl;cout<<"x1 = "<<(-b+sqrt(delta))/(2*a)<<endl;cout<<"x2 = "<<(-b-sqrt(delta))/(2*a)<<endl;}}
}void bai4(){double a, b,c,CV,  s, p;cout<<"Nhap ba canh a, b, c cua tam giac: ";cin>>a>>b>>c;
    if(a+b>c&&a+c>b&&b+c>a&&a>0&&b>0&&c>0){CV = a+b+c;
        p = CV/2;s = sqrt(p*(p-a)*(p-b)*(p-c));cout<<"Chu vi: "<<CV<<endl;cout<<"Dien tich: "<<s<<endl;
        if(a==b&&b==c){cout<<"Tam giac deu."<<endl;}else if(a==b||a==c||b==c){cout<<"Tam giac can."<<endl;
        }else{
            cout<<"Tam giac thuong."<<endl;}}else{cout<<"Ba canh khong tao thanh tam giac."<<endl;
}}void nhapmang(int** arr,int  m,int n){ for(int i=0;i<m;++i)
{for(int j=0;j<n;++j){
        cout<<"Nhap phan tu a["<< i<<"]["<<j<<"]: ";cin>>*(*(arr+i)+j);}}}void xuatmang(int** arr,int m,int n){for(int i=0;i<m;i++){
    for(int j=0;j<n;j++){cout<<arr[i][j]<<" ";}cout<<endl;}}void chuyenLeThanh0   (int** arr, int  m, int n)
{for(int  i=0; i<m;++i){for (int j=0;j<n;j++){if(arr[i][j]%2!=0){arr[i][j]=0;}}}}void sapxepgiam(int** a, int  m, int  n){
    for(int i=0;i<m;i++){
        for (int j=0;j<n;j++){for(int k=0;k<m;k++){for(int  l=0;l<n;l++){
                    if(a[i][j]>a[k][l]){int tmp=a[i][j];a[i][j]=a[k][l];a[k][l]=tmp;}
                }}}}
}


void chenx(int** a,int m, int n, int x)
{ int*b =new  int[m*n+1];int k=0;
for(int i=0;i< m; i++){for(int j=0;j<n;j++){b[k++]=a[i][j];}}b[k] = x;
    sapxepgiam(&b, 1, m * n + 1);k = 0;
    for (int i = 0; i < m; i++) {for (int j = 0; j < n; j++) {
        a[i][j] = b[k++];
    }}delete[] b;}void bai5(){int m,n;cout << "Nhap so dong (m): ";cin >> m;cout << "Nhap so cot (n): ";
    cin>> n;int** a = new int*[m];for (int i = 0; i < m; i++) {a[i] = new int[n];}nhapmang(a, m, n);cout << "Mang vua nhap:" << endl;
xuatmang(a,m,n);chuyenLeThanh0(a, m, n);cout << "Mang sau khi chuyen le thanh 0:" << endl;
xuatmang(a,m,  n);sapxepgiam(a, m, n);cout << "Mang sau khi sap xep giam dan:" << endl;
xuatmang(a, m, n);int x;cout<<"Nhap X: ";cin>>x;chenx(a,m,n,x);cout<<"Mang sau khi chen X:"<<endl;xuatmang(a, m, n);
for(int i=0;i<m;i++){delete[]a[i];}delete[]a;
}int main(){int lc;do{cout<<"\nMENU:\n";
cout<<"1. Bai tap 1 (Tinh chu vi, dien tich hinh hoc)\n";cout<<"2. Bai tap 2 (Dem so uoc)\n";
cout<<"3. Bai tap 3 (Giai phuong trinh bac 2)\n";cout<<"4. Bai tap 4 (Kiem tra tam giac)\n";
cout<<"5. Bai tap 5 (Xu ly mang 2 chieu)\n";cout<<"0. Thoat\n";cout<<"Nhap lua chon cua ban: ";
cin>>lc;cin.ignore();switch(lc){case 1:bai1();break;case 2:bt2();break;case 3:bai_3();break;case 4: bai4(); break;case 5:bai5();break;
case 0:cout<<"Thoat chuong trinh.\n";break;default:cout<<"Lua chon khong hop le. Vui long nhap lai.\n";
}}while(lc!=0);return 0;}