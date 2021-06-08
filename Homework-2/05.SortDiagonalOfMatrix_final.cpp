#include <iostream>

using namespace std;

const int N = 6;

void SortingDiagonalOfMatrix(int matrix[N][N], int n)
{
    int temp;
    int offsetRow = 0;

    // Sorting the elements from columns
    for (int columnIndex = 0; columnIndex < n; columnIndex++) {
        for (int rowIndex = offsetRow; rowIndex < n; rowIndex++) {
            for (int nextRowIndex = (rowIndex + 1); nextRowIndex < n; nextRowIndex++) {
                if (matrix[rowIndex][columnIndex] >= matrix[nextRowIndex][columnIndex]) {
                    for (int index = 0; index < n; index++) {
                        temp = matrix[rowIndex][index];
                        matrix[rowIndex][index] = matrix[nextRowIndex][index];
                        matrix[nextRowIndex][index] = temp;
                    }
                }
            }
        }
        offsetRow++;
    }

    // Sorting to elements from the diagonal
    offsetRow = 1;
    for (int columnIndex = 1; columnIndex < n - 1; columnIndex++) {
        for (int rowIndex = offsetRow; rowIndex < n; rowIndex++) {
            for (int nextRowIndex = (rowIndex + 1); nextRowIndex < n; nextRowIndex++) {
                if (matrix[rowIndex-1][columnIndex-1] <= matrix[rowIndex][columnIndex]) {
                    continue;
                } else if (matrix[rowIndex-1][columnIndex-1] <= matrix[nextRowIndex][columnIndex]) {
                    for (int index = 0; index < n; index++) {
                        temp = matrix[rowIndex][index];
                        matrix[rowIndex][index] = matrix[nextRowIndex][index];
                        matrix[nextRowIndex][index] = temp;
                    }
                }
            }
        }
        offsetRow++;
    }
}

int main()
{
    int matrix[N][N] = {
        {5, 4, 3, 8, 0, 6},
        {9, 2, 5, 1, 0, 8},
        {8, 5, 8, 0, 6, 1},
        {0, 9, 6, 8, 4, 2},
        {6, 1, 0, 2, 6, 1},
        {2, 1, 8, 4, 2, 6}
    };

    bool verificateResult = true;

    // Print the matrix
    cout << "The source matrix is: " << endl;
    for (int rowIndex = 0; rowIndex < N; rowIndex++) {
        for (int columnIndex = 0; columnIndex < N; columnIndex++) {
            cout << matrix[rowIndex][columnIndex] << " ";
        }
        cout << "\n";
    }
    cout << "\n";

    SortingDiagonalOfMatrix(matrix, N);

    // check result
    for (int rowIndex = 1; rowIndex < N; rowIndex++) {
        int columnIndex = rowIndex;
        if (matrix[rowIndex-1][columnIndex-1] > matrix[rowIndex][columnIndex]) {
            verificateResult = false;
        }
    }

    // Printing the result
    if (verificateResult) {
        cout << "Sorted diagonal in ascending order: " << endl;
        for (int rowIndex = 0; rowIndex < N; rowIndex++) {
            for (int columnIndex = 0; columnIndex < N; columnIndex++) {
                cout << matrix[rowIndex][columnIndex] << " ";
            }
            cout << "\n";
        }
    } else {
        cout << "Sorting of the elements from the diagonal is not possible!" << endl;
    }

    return 0;
}
