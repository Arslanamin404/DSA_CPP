#include <stdio.h>

void get_matrix(int rows, int cols, int arr[][cols]);
void set_matrix(int rows, int cols, int arr[][cols]);
void add();
void product();
void transpose();

int main()
{
    // add();
    // product();
    // transpose();
    return 0;
}

void set_matrix(int rows, int cols, int arr[][cols])
{
    printf("Enter %d elements in matrix: \n", rows * cols);
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < cols; j++)
            scanf("%d", &arr[i][j]);
    }
}

void get_matrix(int rows, int cols, int arr[][cols])
{
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < cols; j++)
        {
            printf("%2d ", arr[i][j]);
        }
        printf("\n");
    }
}

void add()
{
    int rows, cols;
    printf("Rows Cols: ");
    scanf("%d %d", &rows, &cols);

    int matrix1[rows][cols], matrix2[rows][cols], result[rows][cols];
    printf("\n===========================\n");
    set_matrix(rows, cols, matrix1);
    printf("\n===========================\n");
    set_matrix(rows, cols, matrix2);
    printf("\n===========================\n");

    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < cols; j++)
        {
            result[i][j] = matrix1[i][j] + matrix2[i][j];
        }
    }

    printf("\nMatrix addition: \n");
    get_matrix(rows, cols, result);
    printf("\n===========================\n");
}

void product()
{
    int m, n, p, q;
    printf("Rows Cols of Matrix 1: ");
    scanf("%d %d", &m, &n);

    printf("\nRows Cols of Matrix 2: ");
    scanf("%d %d", &p, &q);

    if (n != p)
    {
        printf("ERROR: Matrix multiplication not possible, number of columns of Matrix 1 must be euqal to the number of rows of Matrix 2 (p==q)\n");
        return;
    }

    int matrix1[m][n], matrix2[p][q], result[m][q];
    printf("\n===========================\n");
    set_matrix(m, n, matrix1);
    printf("\n===========================\n");
    set_matrix(p, q, matrix2);
    printf("\n===========================\n");

    for (int i = 0; i < m; i++)
    {
        int sum = 0;
        for (int j = 0; j < q; j++)
        {
            sum = 0;
            for (int k = 0; k < n; k++)
            {
                sum += (matrix1[i][k] * matrix2[k][j]);
            }
            result[i][j] = sum;
        }
    }

    get_matrix(m, q, result);
}

void transpose()
{
    int m, n;
    printf("Rows Cols of Matrix: ");
    scanf("%d %d", &m, &n);

    int matrix[m][n];
    set_matrix(m, n, matrix);

    printf("\nBefore Transpose: \n");
    get_matrix(m, n, matrix);
    printf("\n===============================\n");

    for (int i = 0; i < m; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
            if (i < j)
            {
                int temp = matrix[j][i];
                matrix[j][i] = matrix[i][j];
                matrix[i][j] = temp;
            }
        }
    }
    printf("\nAfter Transpose: \n");
    printf("===============================\n");
    get_matrix(m, n, matrix);
    printf("\n===============================\n");
}
