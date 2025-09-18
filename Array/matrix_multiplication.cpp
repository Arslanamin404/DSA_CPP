#include <iostream>
#include <vector>

using namespace std;

void setMatrix(vector<vector<int>> &matrix, int rows, int cols)
{
    cout << "Enter " << rows * cols << " elements: " << endl;
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < cols; j++)
            cin >> matrix[i][j];
    }
}

void PrintMatrix(const vector<vector<int>> &matrix, int rows, int cols)
{
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < cols; j++)
            cout << matrix[i][j] << " ";
        cout << endl;
    }
}

void MatrixMultiplication(const vector<vector<int>> &matrix_A, const vector<vector<int>> &matrix_B, int m, int n, int p, int q)
{
    if (n != p)
    {
        cout << "ERROR: Matrix Multiplication not possible. Invalid Matrix Dimensions! " << endl;
        return;
    }

    vector<vector<int>> result(m, vector<int>(q));
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < q; j++)
        {
            int sum = 0;
            for (int k = 0; k < n; k++)
                sum += matrix_A[i][k] * matrix_B[k][j];
            result[i][j] = sum;
        }
    }
    cout << "Resultant Matrix:" << endl;
    cout << "------------------" << endl;
    PrintMatrix(result, m, q);
}

int main()
{
    int m, n, p, q;
    cout << "ENTER DIMENSIONS OF MATRIX 1 (m n): ";
    cin >> m >> n;
    cout << "ENTER DIMENSIONS OF MATRIX 2 (p q): ";
    cin >> p >> q;

    vector<vector<int>> matrix_A(m, vector<int>(n));
    vector<vector<int>> matrix_B(p, vector<int>(q));
    setMatrix(matrix_A, m, n);
    cout << "\n-------------------------------------------------------" << endl;
    setMatrix(matrix_B, m, n);
    cout << "\n-------------------------------------------------------" << endl;
    MatrixMultiplication(matrix_A, matrix_B, m, n, p, q);
    cout << "\n-------------------------------------------------------" << endl;

    return 0;
}
