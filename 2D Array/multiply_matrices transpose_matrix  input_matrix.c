#include <stdio.h>

void input_matrix(int rows, int cols, int matrix[rows][cols]);
void print_matrix(int rows, int cols, int matrix[rows][cols]);
void multiply_matrices(int r1, int c1, int matrix1[r1][c1], int r2, int c2, int matrix2[r2][c2], int result[r1][c2]);
void transpose_matrix(int rows, int cols, int matrix[rows][cols], int transpose[cols][rows]);

int main() {
    int rows1, cols1, rows2, cols2;

    // Input size of first matrix
    printf("Enter rows and columns for Matrix 1: ");
    scanf("%d %d", &rows1, &cols1);
    int matrix1[rows1][cols1];

    // Input size of second matrix
    printf("Enter rows and columns for Matrix 2: ");
    scanf("%d %d", &rows2, &cols2);
    int matrix2[rows2][cols2];

    // Ensure matrices can be multiplied
    if (cols1 != rows2) {
        printf("Matrix multiplication not possible. Columns of Matrix 1 must match rows of Matrix 2.\n");
        return 0;
    }

    int result[rows1][cols2]; // Resultant matrix for multiplication
    int transpose[cols1][rows1]; // Transpose of Matrix 1

    // Input matrices
    printf("Enter elements of Matrix 1:\n");
    input_matrix(rows1, cols1, matrix1);

    printf("Enter elements of Matrix 2:\n");
    input_matrix(rows2, cols2, matrix2);

    // Traversing (Print matrices)
    printf("\nMatrix 1:\n");
    print_matrix(rows1, cols1, matrix1);

    printf("\nMatrix 2:\n");
    print_matrix(rows2, cols2, matrix2);

    // Multiplication of matrices
    multiply_matrices(rows1, cols1, matrix1, rows2, cols2, matrix2, result);
    printf("\nResult of Matrix Multiplication:\n");
    print_matrix(rows1, cols2, result);

    // Transpose of the first matrix
    transpose_matrix(rows1, cols1, matrix1, transpose);
    printf("\nTranspose of Matrix 1:\n");
    print_matrix(cols1, rows1, transpose);

    return 0;
}

// Function to input a matrix
void input_matrix(int rows, int cols, int matrix[rows][cols]) {
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            printf("Enter element [%d][%d]: ", i + 1, j + 1);
            scanf("%d", &matrix[i][j]);
        }
    }
}

// Function to print a matrix
void print_matrix(int rows, int cols, int matrix[rows][cols]) {
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            printf("%4d", matrix[i][j]);
        }
        printf("\n");
    }
}

// Function to multiply two matrices
void multiply_matrices(int r1, int c1, int matrix1[r1][c1], int r2, int c2, int matrix2[r2][c2], int result[r1][c2]) {
    // Initialize the result matrix to zero
    for (int i = 0; i < r1; i++) {
        for (int j = 0; j < c2; j++) {
            result[i][j] = 0;
        }
    }

    // Matrix multiplication logic
    for (int i = 0; i < r1; i++) {
        for (int j = 0; j < c2; j++) {
            for (int k = 0; k < c1; k++) {
                result[i][j] += matrix1[i][k] * matrix2[k][j];
            }
        }
    }
}

// Function to find the transpose of a matrix
void transpose_matrix(int rows, int cols, int matrix[rows][cols], int transpose[cols][rows]) {
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            transpose[j][i] = matrix[i][j];
        }
    }
}
