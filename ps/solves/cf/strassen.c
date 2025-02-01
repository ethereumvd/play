#include <stdio.h>
#include <stdlib.h>

int** allocate_matrix(int n) {
    int **matrix = malloc(sizeof(int)*n);
    for (int i = 0; i < n; i++) {
        matrix[i] = malloc(sizeof(int)*n);
    }
    return matrix;
}

void add(int **A, int **B, int **C, int n) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            C[i][j] = A[i][j] + B[i][j];
        }
    }
}

void multiply(int **A, int **B, int **C, int n) {
    if (n == 1) {
        C[0][0] = A[0][0] * B[0][0];
        return;
    }

    int new_n = n / 2;
    int **A11 = allocate_matrix(new_n);
    int **A12 = allocate_matrix(new_n);
    int **A21 = allocate_matrix(new_n);
    int **A22 = allocate_matrix(new_n);
    int **B11 = allocate_matrix(new_n);
    int **B12 = allocate_matrix(new_n);
    int **B21 = allocate_matrix(new_n);
    int **B22 = allocate_matrix(new_n);
    int **C11 = allocate_matrix(new_n);
    int **C12 = allocate_matrix(new_n);
    int **C21 = allocate_matrix(new_n);
    int **C22 = allocate_matrix(new_n);

    for (int i = 0; i < new_n; i++) {
        for (int j = 0; j < new_n; j++) {
            A11[i][j] = A[i][j];
            B11[i][j] = B[i][j];
            A12[i][j] = A[i][j + new_n];
            B12[i][j] = B[i][j + new_n];
            A21[i][j] = A[i + new_n][j];
            B21[i][j] = B[i + new_n][j];
            A22[i][j] = A[i + new_n][j + new_n];
            B22[i][j] = B[i + new_n][j + new_n];
        }
    }

    int **temp1 = allocate_matrix(new_n);
    int **temp2 = allocate_matrix(new_n);

    multiply(A11, B11, temp1, new_n);
    multiply(A12, B21, temp2, new_n);
    add(temp1, temp2, C11, new_n);
    
    multiply(A11, B12, temp1, new_n);
    multiply(A12, B22, temp2, new_n);
    add(temp1, temp2, C12, new_n);

    multiply(A21, B11, temp1, new_n);
    multiply(A22, B21, temp2, new_n);
    add(temp1, temp2, C21, new_n);

    multiply(A21, B12, temp1, new_n);
    multiply(A22, B22, temp2, new_n);
    add(temp1, temp2, C22, new_n);

    for (int i = 0; i < new_n; i++) {
        for (int j = 0; j < new_n; j++) {
            C[i][j] = C11[i][j];
            C[i][j + new_n] = C12[i][j];
            C[i + new_n][j] = C21[i][j];
            C[i + new_n][j + new_n] = C22[i][j];
        }
    }

    free(A11);
    free(A12);
    free(A21);
    free(A22);
    free(B11);
    free(B12);
    free(B21);
    free(B22);
    free(temp1);
    free(temp2);
    free(C11);
    free(C12);
    free(C21);
    free(C22);
}

int main() {
    int n = 2;
    int **A = allocate_matrix(n);
    int **B = allocate_matrix(n);
    puts("Matrix A:");
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            scanf("%d", &A[i][j]);
        }
    }
    puts("Matrix B:");
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            scanf("%d", &B[i][j]);
        }
    }

    int **C = allocate_matrix(n);
    multiply(A, B, C, n);

    puts("Matrix C: A*B");
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            printf("%d ", C[i][j]);
        }
        printf("\n");
    }
    free(A);
    free(B);
    free(C);
}
