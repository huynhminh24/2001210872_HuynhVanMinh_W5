#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define N 8

int solutions = 0;

bool is_safe(int board[N][N], int row, int col) {
    int i, j;

    // Kiểm tra cột này ở hàng trên
    for (i = 0; i < row; i++) {
        if (board[i][col]) {
            return false;
        }
    }

    // Kiểm tra đường chéo bên trái trên
    for (i = row, j = col; i >= 0 && j >= 0; i--, j--) {
        if (board[i][j]) {
            return false;
        }
    }

    // Kiểm tra đường chéo bên phải trên
    for (i = row, j = col; i >= 0 && j < N; i--, j++) {
        if (board[i][j]) {
            return false;
        }
    }

    return true;
}

void print_solution(int board[N][N]) {
    printf("Loi giai %d:\n", ++solutions);
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            printf("%s ", board[i][j] ? "H" : ".");
        }
        printf("\n");
    }
    printf("\n");
}

bool solve_n_queens(int board[N][N], int row) {
    if (row == N) {
        print_solution(board);
        return true;
    }

    bool found_solution = false;
    for (int col = 0; col < N; col++) {
        if (is_safe(board, row, col)) {
            board[row][col] = 1;

            found_solution = solve_n_queens(board, row + 1) || found_solution;

            board[row][col] = 0; 
        }
    }

    return found_solution;
}

int main() {
    int board[N][N] = { 0 };

    if (!solve_n_queens(board, 0)) {
        printf("Khong tim thay loi giai nao.\n");
    }

    return 0;
}
