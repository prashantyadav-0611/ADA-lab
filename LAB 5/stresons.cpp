#include <iostream>
#include <vector>

using namespace std;

vector<vector<int>> createMatrix(int size) {
    return vector<vector<int>>(size, vector<int>(size, 0));
}

void printMatrix(const vector<vector<int>>& matrix) {
    for (const auto& row : matrix) {
        for (int val : row) {
            cout << val << " ";
        }
        cout << endl;
    }
    cout << endl;
}

vector<vector<int>> addMatrix(const vector<vector<int>>& A, const vector<vector<int>>& B) {
    int size = A.size();
    vector<vector<int>> C(size, vector<int>(size, 0));
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            C[i][j] = A[i][j] + B[i][j];
        }
    }
    return C;
}

vector<vector<int>> subtractMatrix(const vector<vector<int>>& A, const vector<vector<int>>& B) {
    int size = A.size();
    vector<vector<int>> C(size, vector<int>(size, 0));
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            C[i][j] = A[i][j] - B[i][j];
        }
    }
    return C;
}

vector<vector<int>> strassenMultiply(const vector<vector<int>>& A, const vector<vector<int>>& B) {
    int size = A.size();
    if (size == 1) {
        return {{A[0][0] * B[0][0]}};
    }
    int newSize = size / 2;
    
    vector<vector<int>> A11(newSize, vector<int>(newSize));
    vector<vector<int>> A12(newSize, vector<int>(newSize));
    vector<vector<int>> A21(newSize, vector<int>(newSize));
    vector<vector<int>> A22(newSize, vector<int>(newSize));
    vector<vector<int>> B11(newSize, vector<int>(newSize));
    vector<vector<int>> B12(newSize, vector<int>(newSize));
    vector<vector<int>> B21(newSize, vector<int>(newSize));
    vector<vector<int>> B22(newSize, vector<int>(newSize));
    
    for (int i = 0; i < newSize; i++) {
        for (int j = 0; j < newSize; j++) {
            A11[i][j] = A[i][j];
            A12[i][j] = A[i][j + newSize];
            A21[i][j] = A[i + newSize][j];
            A22[i][j] = A[i + newSize][j + newSize];
            B11[i][j] = B[i][j];
            B12[i][j] = B[i][j + newSize];
            B21[i][j] = B[i + newSize][j];
            B22[i][j] = B[i + newSize][j + newSize];
        }
    }
    
    vector<vector<int>> M1 = strassenMultiply(addMatrix(A11, A22), addMatrix(B11, B22));
    vector<vector<int>> M2 = strassenMultiply(addMatrix(A21, A22), B11);
    vector<vector<int>> M3 = strassenMultiply(A11, subtractMatrix(B12, B22));
    vector<vector<int>> M4 = strassenMultiply(A22, subtractMatrix(B21, B11));
    vector<vector<int>> M5 = strassenMultiply(addMatrix(A11, A12), B22);
    vector<vector<int>> M6 = strassenMultiply(subtractMatrix(A21, A11), addMatrix(B11, B12));
    vector<vector<int>> M7 = strassenMultiply(subtractMatrix(A12, A22), addMatrix(B21, B22));
    
    vector<vector<int>> C11 = addMatrix(subtractMatrix(addMatrix(M1, M4), M5), M7);
    vector<vector<int>> C12 = addMatrix(M3, M5);
    vector<vector<int>> C21 = addMatrix(M2, M4);
    vector<vector<int>> C22 = addMatrix(subtractMatrix(addMatrix(M1, M3), M2), M6);
    
    vector<vector<int>> C(size, vector<int>(size));
    for (int i = 0; i < newSize; i++) {
        for (int j = 0; j < newSize; j++) {
            C[i][j] = C11[i][j];
            C[i][j + newSize] = C12[i][j];
            C[i + newSize][j] = C21[i][j];
            C[i + newSize][j + newSize] = C22[i][j];
        }
    }
    
    return C;
}

int main() {
    int N = 8; 

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

    vector<vector<int>> B = A; 
    vector<vector<int>> C = strassenMultiply(A, B);

    cout << "Resultant Matrix C (A x B):\n";
    printMatrix(C);

    return 0;
}
