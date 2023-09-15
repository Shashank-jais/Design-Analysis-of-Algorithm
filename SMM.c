#include <stdio.h>

void printMatrix(int n, int matrix[][n]) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            printf("%d\t", matrix[i][j]);
        }
        printf("\n");
    }
}

void matrixAdd(int n, int a[][n], int b[][n], int result[][n]) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            result[i][j] = a[i][j] + b[i][j];
        }
    }
}

void matrixSub(int n, int a[][n], int b[][n], int result[][n]) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            result[i][j] = a[i][j] - b[i][j];
        }
    }
}

void matrixMultiply(int n, int a[][n], int b[][n], int result[][n]) {
    if (n == 1) {
        result[0][0] = a[0][0] * b[0][0];
        return;
    }

    int newSize = n / 2;
    int A11[newSize][newSize], A12[newSize][newSize], A21[newSize][newSize], A22[newSize][newSize];
    int B11[newSize][newSize], B12[newSize][newSize], B21[newSize][newSize], B22[newSize][newSize];
    int C11[newSize][newSize], C12[newSize][newSize], C21[newSize][newSize], C22[newSize][newSize];
    int P1[newSize][newSize], P2[newSize][newSize], P3[newSize][newSize], P4[newSize][newSize], P5[newSize][newSize], P6[newSize][newSize], P7[newSize][newSize];

    // Divide A and B into 4 sub-matrices each
    for (int i = 0; i < newSize; i++) {
        for (int j = 0; j < newSize; j++) {
            A11[i][j] = a[i][j];
            A12[i][j] = a[i][j + newSize];
            A21[i][j] = a[i + newSize][j];
            A22[i][j] = a[i + newSize][j + newSize];

            B11[i][j] = b[i][j];
            B12[i][j] = b[i][j + newSize];
            B21[i][j] = b[i + newSize][j];
            B22[i][j] = b[i + newSize][j + newSize];
        }
    }

    int temp1[newSize][newSize];
    int temp2[newSize][newSize];

    // Calculate intermediate products
    matrixAdd(newSize, A11, A22, temp1);
    matrixAdd(newSize, B11, B22, temp2);
    matrixMultiply(newSize, temp1, temp2, P1);

    matrixAdd(newSize, A21, A22, temp1);
    matrixMultiply(newSize, temp1, B11, P2);

    matrixSub(newSize, B12, B22, temp1);
    matrixMultiply(newSize, A11, temp1, P3);

    matrixSub(newSize, B21, B11, temp1);
    matrixMultiply(newSize, A22, temp1, P4);

    matrixAdd(newSize, A11, A12, temp1);
    matrixMultiply(newSize, temp1, B22, P5);

    matrixSub(newSize, A21, A11, temp1);
    matrixAdd(newSize, B11, B12, temp2);
    matrixMultiply(newSize, temp1, temp2, P6);

    matrixSub(newSize, A12, A22, temp1);
    matrixAdd(newSize, B21, B22, temp2);
    matrixMultiply(newSize, temp1, temp2, P7);

    // Calculate C submatrices
    matrixAdd(newSize, P1, P4, temp1);
    matrixSub(newSize, temp1, P5, temp2);
    matrixAdd(newSize, temp2, P7, C11);

    matrixAdd(newSize, P3, P5, C12);

    matrixAdd(newSize, P2, P4, C21);

    matrixSub(newSize, P1, P2, temp1);
    matrixAdd(newSize, temp1, P3, temp2);
    matrixAdd(newSize, temp2, P6, C22);

    // Combine C submatrices to get the result
    for (int i = 0; i < newSize; i++) {
        for (int j = 0; j < newSize; j++) {
            result[i][j] = C11[i][j];
            result[i][j + newSize] = C12[i][j];
            result[i + newSize][j] = C21[i][j];
            result[i + newSize][j + newSize] = C22[i][j];
        }
    }
}

int main() {
    int n = 4;

    int a[4][4] = {{1, 2, 3, 4},
                  {5, 6, 7, 8},
                  {9, 10, 11, 12},
                  {13, 14, 15, 16}};

    int b[4][4] = {{17, 18, 19, 20},
                  {21, 22, 23, 24},
                  {25, 26, 27, 28},
                  {29, 30, 31, 32}};

    int c[4][4];

    matrixMultiply(n, a, b, c);

    printf("Resultant matrix:\n");
    printMatrix(n, c);

    return 0;
}


//okk