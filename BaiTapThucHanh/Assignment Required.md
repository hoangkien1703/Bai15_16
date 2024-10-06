Bài 1.	Viết chương trình tính chu vi và diện tích của một số hình học cơ bản: 
•	Yêu cầu người dùng nhập vào tên của hình muốn tính diện tích. Tên là một trong ba loại sau: tam giac, hinh chu nhat, hinh vuong. 
•	Sau khi người dùng nhập vào tên hình cần tính, yêu cầu người dùng nhập các thông tin cần thiết để tính chu vi và diện tích.
o	Với tam giác, yêu cầu nhập độ dài ba cạnh.
o	Với hình chữ nhật, yêu cầu nhập chiều dài và chiều rộng.
o	Với hình vuông, yêu cầu nhập độ dài cạnh.
•	Sau khi người dùng nhập đủ thông tin theo yêu cầu, kiểm tra dữ liệu nhập vào có phù hợp hay không. Nếu có, tính chu vi, diện tích và in kết quả ra màn hình.
Bài 2: Viết chương trình nhập một số nguyên n sao cho 0 < n ≤ 100 (Nếu nhập sai thì yêu cầu nhập lại). Đếm và in ra màn hình số ước của n.
Bài 3: Giải phương trình bậc 2 một ẩn: ax^2 + bx + c =0
Bài 4: Nhập vào 3 số nguyên dương a, b, c. Kiểm tra xem 3 số đó có lập thành tam giác không? Nếu có hãy cho biết tam giác đó thuộc loại nào? (Cân, đều). Tính chu vi và diện tích của tam giác.
Bài 5: Viết chương trình nhập vào mảng 2 chiều m,n yêu cầu thực hiện:
a)	Nhập các phần tử và xuất ra mảng vừa nhập
b)	Các phần nào trong không phải là số chẵn thì chuyển thành 0
Ví dụ:
3    4 
2     1 
Sau chuyển:
0	4 
2	0
c)	Sắp xếp mảng giảm dần, sau đó thực hiện chèn X vào mảng làm sao mảng vẫn giảm dần. (X là số người dùng nhập vào)
Ví dụ: 
2 5 3 
495
672
Sau khi sắp xếp:
9 7 6
5 5 4
3 2 2









#Giải thích bài 5

Code này thực hiện các thao tác trên một mảng hai chiều như yêu cầu của đề bài. Dưới đây là giải thích chi tiết từng phần:

a) Nhập và xuất mảng:

cout << "Nhap so hang m: "; và cin >> m;: Nhập số hàng m.

cout << "Nhap so cot n: "; và cin >> n;: Nhập số cột n.

int arr[100][100];: Khai báo mảng hai chiều arr với kích thước tối đa 100x100. Lưu ý: Khai báo kích thước cố định như thế này có thể gây tràn bộ nhớ nếu m hoặc n lớn hơn 100. Nên sử dụng cấp phát động mảng để linh hoạt hơn (ví dụ: dùng vector trong C++).

Vòng lặp for lồng nhau để nhập các phần tử của mảng từ người dùng.

Vòng lặp for lồng nhau tiếp theo để in ra mảng vừa nhập.

b) Chuyển số lẻ thành 0:

Vòng lặp for lồng nhau duyệt qua từng phần tử của mảng.

if (arr[i][j] % 2 != 0): Kiểm tra xem phần tử hiện tại có phải là số lẻ hay không (phần dư khi chia cho 2 khác 0).

arr[i][j] = 0;: Nếu là số lẻ, gán giá trị phần tử đó thành 0.

In ra mảng sau khi chuyển đổi.

c) Sắp xếp giảm dần và chèn X:

Sắp xếp giảm dần: Đoạn code sử dụng thuật toán sắp xếp nổi bọt (bubble sort) để sắp xếp mảng theo thứ tự giảm dần. Tuy nhiên, nó được áp dụng trên mảng hai chiều được coi như mảng một chiều có kích thước m * n. Các chỉ số row1, col1, row2, col2 được tính toán để truy cập đúng vị trí trong mảng hai chiều.

Chèn X:

int x;: Khai báo biến x để lưu giá trị cần chèn.

cin >> x;: Nhập giá trị x từ người dùng.

int newArr[100][100];: Khai báo mảng mới newArr để lưu mảng sau khi chèn x.

bool inserted = false;: Biến cờ để kiểm tra xem x đã được chèn hay chưa.

Vòng lặp duyệt qua mảng đã sắp xếp.

if (!inserted && x >= arr[oldRow][oldCol]): Nếu x chưa được chèn và x lớn hơn hoặc bằng phần tử hiện tại, chèn x vào newArr.

else: Sao chép phần tử từ mảng cũ sang mảng mới. Đoạn code if(inserted){ oldRow = (i)/n; oldCol = (i)%n;} là cần thiết để đảm bảo sau khi chèn x, các phần tử còn lại của mảng cũ được sao chép đúng vị trí vào mảng mới. Nếu không có đoạn code này, một số phần tử của mảng cũ sẽ bị bỏ qua.

col++; if (col == n) { col = 0; row++; }: Tăng chỉ số cột và hàng để duyệt mảng mới.

if (!inserted): Nếu sau khi duyệt hết mảng mà x vẫn chưa được chèn (tức là x nhỏ hơn tất cả các phần tử), chèn x vào cuối newArr.

In ra mảng sau khi chèn x.

Lưu ý về việc cải tiến code:

Cấp phát động mảng: Sử dụng vector trong C++ để tránh tràn bộ nhớ khi m và n lớn.

Sắp xếp hiệu quả hơn: Sử dụng các thuật toán sắp xếp hiệu quả hơn như quicksort hoặc mergesort thay vì bubble sort.

Chèn X hiệu quả hơn: Có thể tối ưu việc chèn x bằng cách tìm vị trí chèn bằng tìm kiếm nhị phân và sau đó dịch chuyển các phần tử để chèn x vào.

Ví dụ về việc sử dụng vector:

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int m, n;
    cin >> m >> n;

    vector<vector<int>> arr(m, vector<int>(n));
    // ... (nhập và xử lý mảng như trong code gốc)

    // Sắp xếp (ví dụ dùng sort)
    vector<int> temp;
    for(int i=0; i<m; ++i){
        for(int j=0; j<n; ++j){
            temp.push_back(arr[i][j]);
        }
    }
    sort(temp.begin(), temp.end(), greater<int>());


    int k = 0;
    for(int i=0; i<m; ++i){
        for(int j=0; j<n; ++j){
            arr[i][j] = temp[k++];
        }
    }

    // ... (chèn X)
}
content_copy
Use code with caution.
C++

Việc sử dụng vector giúp code linh hoạt hơn và tránh được lỗi tràn bộ nhớ. Việc sử dụng sort của <algorithm> cũng giúp việc sắp xếp dễ dàng và hiệu quả hơn.








