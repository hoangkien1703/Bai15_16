#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

// Bài 1
void tinhHinhHoc() {
    char tenHinh[20];
    float a, b, c, cv, dt;

    printf("Nhap ten hinh (tam giac, hinh chu nhat, hinh vuong): ");
    scanf("%s", tenHinh);

    if (strcmp(tenHinh, "tam giac") == 0) {
        printf("Nhap do dai 3 canh: ");
        scanf("%f %f %f", &a, &b, &c);
        if (a + b > c && a + c > b && b + c > a) {
            cv = a + b + c;
            float p = cv / 2;
            dt = sqrt(p * (p - a) * (p - b) * (p - c)); // Heron's formula
            printf("Chu vi: %.2f\n", cv);
            printf("Dien tich: %.2f\n", dt);
        } else {
            printf("3 canh khong tao thanh tam giac.\n");
        }
    } else if (strcmp(tenHinh, "hinh chu nhat") == 0) {
        printf("Nhap chieu dai va chieu rong: ");
        scanf("%f %f", &a, &b);
        if (a > 0 && b > 0) {
            cv = 2 * (a + b);
            dt = a * b;
            printf("Chu vi: %.2f\n", cv);
            printf("Dien tich: %.2f\n", dt);
        } else {
            printf("Chieu dai va chieu rong phai duong.\n");
        }

    } else if (strcmp(tenHinh, "hinh vuong") == 0) {
        printf("Nhap do dai canh: ");
        scanf("%f", &a);
        if (a > 0) {
            cv = 4 * a;
            dt = a * a;
            printf("Chu vi: %.2f\n", cv);
            printf("Dien tich: %.2f\n", dt);
        } else {
            printf("Canh phai duong.\n");
        }
    } else {
        printf("Ten hinh khong hop le.\n");
    }
}



// Bài 2
void demUoc() {
    int n, dem = 0;
    do {
        printf("Nhap so nguyen n (0 < n <= 100): ");
        scanf("%d", &n);
    } while (n <= 0 || n > 100);

    for (int i = 1; i <= n; i++) {
        if (n % i == 0) {
            dem++;
        }
    }
    printf("So uoc cua %d la: %d\n", n, dem);
}

// Bài 3
void giaiPTBac2() {
    float a, b, c, delta, x1, x2;
    printf("Nhap a, b, c: ");
    scanf("%f %f %f", &a, &b, &c);

    if (a == 0) {
        if (b == 0) {
            if (c == 0) {
                printf("Phuong trinh vo so nghiem.\n");
            } else {
                printf("Phuong trinh vo nghiem.\n");
            }
        } else {
            printf("Phuong trinh co nghiem duy nhat: x = %.2f\n", -c / b);
        }
    } else {
        delta = b * b - 4 * a * c;
        if (delta < 0) {
            printf("Phuong trinh vo nghiem.\n");
        } else if (delta == 0) {
            x1 = -b / (2 * a);
            printf("Phuong trinh co nghiem kep: x1 = x2 = %.2f\n", x1);
        } else {
            x1 = (-b + sqrt(delta)) / (2 * a);
            x2 = (-b - sqrt(delta)) / (2 * a);
            printf("Phuong trinh co 2 nghiem phan biet:\n");
            printf("x1 = %.2f\n", x1);
            printf("x2 = %.2f\n", x2);
        }
    }
}

// Bài 4
void kiemTraTamGiac() {
    int a, b, c;
    float cv, dt, p;

    printf("Nhap 3 canh a, b, c: ");
    scanf("%d %d %d", &a, &b, &c);

    if (a + b > c && a + c > b && b + c > a) {
        cv = a + b + c;
        p = cv / 2.0;
        dt = sqrt(p * (p - a) * (p - b) * (p - c));

        printf("Chu vi: %.2f\n", cv);
        printf("Dien tich: %.2f\n", dt);


        if (a == b && b == c) {
            printf("Tam giac deu.\n");
        } else if (a == b || a == c || b == c) {
            printf("Tam giac can.\n");
           
        } else {
            printf("Tam giac thuong.\n");
        }
    } else {
        printf("3 canh khong tao thanh tam giac.\n");
    }
}


// Bài 5
void xuLyMang2Chieu() {
    int m, n, i, j;

    printf("Nhap so hang m: ");
    scanf("%d", &m);
    printf("Nhap so cot n: ");
    scanf("%d", &n);

    int mang[m][n];

    // a) Nhập và xuất mảng
    printf("Nhap cac phan tu cua mang:\n");
    for (i = 0; i < m; i++) {
        for (j = 0; j < n; j++) {
            scanf("%d", &mang[i][j]);
        }
    }

    printf("Mang vua nhap:\n");
    for (i = 0; i < m; i++) {
        for (j = 0; j < n; j++) {
            printf("%d\t", mang[i][j]);
        }
        printf("\n");
    }


    // b) Chuyển số lẻ thành 0
    printf("Mang sau khi chuyen so le thanh 0:\n");
    for (i = 0; i < m; i++) {
        for (j = 0; j < n; j++) {
             if (mang[i][j] % 2 != 0) {
                mang[i][j] = 0;
             }
            printf("%d\t", mang[i][j]);
        }
        printf("\n");
    }

      // c) Sắp xếp giảm dần và chèn X


        int mang1D[m * n];
        int k = 0;
        for (i = 0; i < m; i++) {
            for (j = 0; j < n; j++) {
                mang1D[k++] = mang[i][j];
            }
        }



        // Sắp xếp giảm dần mảng 1 chiều (bubble sort)
         for (i = 0; i < m * n - 1; i++) {
            for (j = 0; j < m * n - i - 1; j++) {
                if (mang1D[j] < mang1D[j + 1]) {
                    int temp = mang1D[j];
                    mang1D[j] = mang1D[j + 1];
                    mang1D[j + 1] = temp;
                }
            }
        }


        int x;
        printf("Nhap gia tri X can chen: ");
        scanf("%d", &x);



        int mangMoi[m*n+1];

        int daChen = 0;
         k=0;
        for (i=0; i < m*n; i++){
            if (x > mang1D[i] && daChen == 0){
                mangMoi[k++] = x;
                daChen = 1;

            }
                mangMoi[k++] = mang1D[i];
        }
        if (daChen == 0){
                mangMoi[k++] = x;

        }

        printf("Mang sau sap xep va chen:\n");


        int dem1 = 0;
         for(i=0; i < m; i++){
            for (j=0; j < n; j++){
                printf("%d\t", mangMoi[dem1++]);

            }
            printf("\n");
         }
}




int main() {
    int chonBai;

    do {
        printf("\nChon bai tap (1-5, 0 de thoat): ");
        scanf("%d", &chonBai);

        switch (chonBai) {
            case 1: tinhHinhHoc(); break;
            case 2: demUoc(); break;
            case 3: giaiPTBac2(); break;
            case 4: kiemTraTamGiac(); break;
            case 5: xuLyMang2Chieu(); break;
            case 0: printf("Thoat chuong trinh.\n"); break;
            default: printf("Lua chon khong hop le.\n");
        }
    } while (chonBai != 0);


    return 0;
}