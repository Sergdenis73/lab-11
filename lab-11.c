#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Функція для обчислення сум додатніх елементів кожного рядка
void calculate_row_sums(int rows, int cols, int matrix[rows][cols], int sums[rows]) {
    for (int i = 0; i < rows; i++) {
        sums[i] = 0;
        for (int j = 0; j < cols; j++) {
            if (matrix[i][j] > 0) {
                sums[i] += matrix[i][j];
            }
        }
    }
}

// Функція для виведення матриці (для наглядності)
void print_matrix(int rows, int cols, int matrix[rows][cols]) {
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            printf("%4d", matrix[i][j]);
        }
        printf("\n");
    }
}

// Функція для виведення сум рядків
void print_sums(int rows, int sums[rows]) {
    for (int i = 0; i < rows; i++) {
        printf("Рядок %2d: сума додатніх = %d\n", i+1, sums[i]);
    }
}

int main() {
     system("chcp 65001");
    // Ініціалізація генератора випадкових чисел
    srand(time(0));
    
    // Матриця a(10, 12)
    int a[10][12];
    int a_sums[10];
    
    // Матриця b(15, 10)
    int b[15][10];
    int b_sums[15];
    
    // Заповнення матриць випадковими числами (від -50 до 50)
    for (int i = 0; i < 10; i++) {
        for (int j = 0; j < 12; j++) {
            a[i][j] = rand() % 101 - 50;
        }
    }
    
    for (int i = 0; i < 15; i++) {
        for (int j = 0; j < 10; j++) {
            b[i][j] = rand() % 101 - 50;
        }
    }
    
    // Обчислення сум для матриці a
    calculate_row_sums(10, 12, a, a_sums);
    
    // Обчислення сум для матриці b
    calculate_row_sums(15, 10, b, b_sums);
    
    // Виведення результатів
    printf("Матриця a(10, 12):\n");
    print_matrix(10, 12, a);
    printf("\nСумми додатніх елементів рядків матриці a:\n");
    print_sums(10, a_sums);
    
    printf("\n----------------------------------------\n");
    
    printf("\nМатриця b(15, 10):\n");
    print_matrix(15, 10, b);
    printf("\nСумми додатніх елементів рядків матриці b:\n");
    print_sums(15, b_sums);
    
    return 0;
}