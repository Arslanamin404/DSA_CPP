#include <stdio.h>

void swap(int *a, int *b);
void set_array(int *arr, int size);
void get_array(int *arr, int size);
void subString(char *str, int start_index, int end_index, char *result);

int main()
{
    int a, b;
    printf("Enter 2 numbers: ");
    scanf("%d %d", &a, &b);

    printf("a:%d b:%d\n", a, b);
    swap(&a, &b);
    printf("a:%d b:%d\n", a, b);

    // int arr[5];
    // set_array(arr, 5);
    // get_array(arr, 5);

    return 0;
}

void swap(int *a, int *b)
{
    *a = *a + *b;
    *b = *a - *b;
    *a = *a - *b;
}

void set_array(int *arr, int size)
{
    for (int i = 0; i < size; i++)
        scanf("%d", arr + i);
}

void get_array(int *arr, int size)
{
    for (int i = 0; i < size; i++)
        printf("%d ", *(arr + i));
}

void subString(char *str, int start_index, int end_index, char *result)
{
    for (int i = start_index; i < end_index; i++)
        result[i - start_index] = str[i];

    result[end_index - start_index] = '\0';
}
