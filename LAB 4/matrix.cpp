#include <iostream>
#include <vector>

using namespace std;

// Function to create a matrix initialized with zeros
vector<vector<int>> createMatrix(int size) {
    return vector<vector<int>>(size, vector<int>(size, 0));
}

// Function to print a matrix
void printMatrix(const vector<vector<int>>& matrix) {
    for (const auto& row : matrix) {
        for (int val : row) {
            cout << val << " ";
        }
        cout << endl;
    }
    cout << endl;
}

// Recursive function to multiply matrices and accumulate result in C
void multiply(const vector<vector<int>>& A, const vector<vector<int>>& B, vector<vector<int>>& C,
              int rowA, int colA, int rowB, int colB, int rowC, int colC, int size) {
    if (size == 1) {
        C[rowC][colC] += A[rowA][colA] * B[rowB][colB];
        return;
    }

    int half = size / 2;

    // Multiply and add into the four quadrants of C
    // Top-left quadrant (C11) contributions
    multiply(A, B, C, rowA, colA, rowB, colB, rowC, colC, half); // A11*B11
    multiply(A, B, C, rowA, colA + half, rowB + half, colB, rowC, colC, half); // A12*B21

    // Top-right quadrant (C12) contributions
    multiply(A, B, C, rowA, colA, rowB, colB + half, rowC, colC + half, half); // A11*B12
    multiply(A, B, C, rowA, colA + half, rowB + half, colB + half, rowC, colC + half, half); // A12*B22

    // Bottom-left quadrant (C21) contributions
    multiply(A, B, C, rowA + half, colA, rowB, colB, rowC + half, colC, half); // A21*B11
    multiply(A, B, C, rowA + half, colA + half, rowB + half, colB, rowC + half, colC, half); // A22*B21

    // Bottom-right quadrant (C22) contributions
    multiply(A, B, C, rowA + half, colA, rowB, colB + half, rowC + half, colC + half, half); // A21*B12
    multiply(A, B, C, rowA + half, colA + half, rowB + half, colB + half, rowC + half, colC + half, half); // A22*B22
}

int main() {
    int N = 8; // Matrix size (must be a power of 2)

    vector<vector<int>> A = {
        {1, 2, 3, 4, 5, 6, 7, 8},
        {2, 3, 4, 5, 6, 7, 8, 1},
        {3, 4, 5, 6, 7, 8, 1, 2},
        {4, 5, 6, 7, 8, 1, 2, 3},
        {5, 6, 7, 8, 1, 2, 3, 4},
        {6, 7, 8, 1, 2, 3, 4, 5},
        {7, 8, 1, 2, 3, 4, 5, 6},
        {8, 1, 2, 3, 4, 5, 6, 7}
    };

    vector<vector<int>> B = {
        {8, 7, 6, 5, 4, 3, 2, 1},
        {7, 6, 5, 4, 3, 2, 1, 8},
        {6, 5, 4, 3, 2, 1, 8, 7},
        {5, 4, 3, 2, 1, 8, 7, 6},
        {4, 3, 2, 1, 8, 7, 6, 5},
        {3, 2, 1, 8, 7, 6, 5, 4},
        {2, 1, 8, 7, 6, 5, 4, 3},
        {1, 8, 7, 6, 5, 4, 3, 2}
    };

    vector<vector<int>> C = createMatrix(N);

    cout << "Matrix A:\n";
    printMatrix(A);

    cout << "Matrix B:\n";
    printMatrix(B);

    // Perform recursive multiplication
    multiply(A, B, C, 0, 0, 0, 0, 0, 0, N);

    cout << "Resultant Matrix C (A x B):\n";
    printMatrix(C);

    return 0;
}