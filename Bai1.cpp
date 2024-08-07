#include <stdio.h>

// Hàm chuyển một đĩa từ chồng nguồn sang chồng đích
void MoveDisk(char colA, char colC) {
    printf("Chuyen dia tu chong %c sang chuong %c\n", colA, colC);
}

// Hàm đệ quy thực hiện thuật toán Tháp Hà Nội
void Tower(int n, char colA, char colB, char colC) {
    if (n == 1) {
        MoveDisk(colA, colC);
    }
    else {
        Tower(n - 1, colA, colC, colB); // Chuyển n-1 đĩa từ colA sang colB (dùng colC làm trung gian)
        MoveDisk(colA, colC);           // Chuyển đĩa thứ n từ colA sang colC
        Tower(n - 1, colB, colA, colC); // Chuyển n-1 đĩa từ colB sang colC (dùng colA làm trung gian)
    }
}

int main() {
    int n; // Số lượng đĩa
    printf("Nhap so luong dia: ");
    scanf_s("%d", &n);

    printf("Thu tu chuyen cac dia:\n");
    Tower(n, 'A', 'B', 'C'); // A là chồng nguồn, C là chồng đích, B là chồng trung gian
    return 0;
}
