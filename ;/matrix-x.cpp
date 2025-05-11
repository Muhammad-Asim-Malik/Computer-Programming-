// Matrix Multiplication (3x3)

#include <iostream>
using namespace std;

// Function declarations
void inputMatrix(double matrix[3][3], const string& name);
void displayMatrix(double matrix[3][3], const string& name);
void multiplyMatrices(double A[3][3], double B[3][3], double C[3][3]);

// Block diagram:
// Inputs: 3x3 matrices A and B
// Outputs: 3x3 matrix C (result)
// Processing: Multiplies matrices A and B, stores result in C

int main() {
    double matrixA[3][3], matrixB[3][3], resultMatrix[3][3];
    
    // Input matrices
    inputMatrix(matrixA, "A");
    inputMatrix(matrixB, "B");
    
    // Multiply matrices
    multiplyMatrices(matrixA, matrixB, resultMatrix);
    
    // Display results
    displayMatrix(matrixA, "A");
    displayMatrix(matrixB, "B");
    displayMatrix(resultMatrix, "Result (A × B)");
    
    return 0;
}

// Function to input a matrix
void inputMatrix(double matrix[3][3], const string& name) {
    cout << "Enter values for matrix " << name << " (3x3):\n";
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            cout << "Enter value for position [" << i << "][" << j << "]: ";
            cin >> matrix[i][j];
        }
    }
}

// Function to display a matrix
void displayMatrix(double matrix[3][3], const string& name) {
    cout << "Matrix " << name << ":\n";
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            cout << matrix[i][j] << "\t";
        }
        cout << endl;
    }
    cout << endl;
}

// Function to multiply two matrices
void multiplyMatrices(double A[3][3], double B[3][3], double C[3][3]) {
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            C[i][j] = 0; // Initialize to zero
            
            // Calculate C[i][j] = sum of A[i][k] * B[k][j] for k from 0 to 2
            for (int k = 0; k < 3; k++) {
                C[i][j] += A[i][k] * B[k][j];
            }
        }
    }
}
