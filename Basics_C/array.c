#include <stdio.h>
#include <limits.h>

void set_array(int arr[], int size);
void get_array(int arr[], int size);
int sum(int arr[], int size);
float avg(int arr[], int size);
void odd_even_sum(int arr[], int size);
int greatest(int arr[], int size);
int smallest(int arr[], int size);
void sort_array(int arr[], int size, int order);
int second_greatest(int arr[], int size);
int get_dublicates_count(int arr[], int size);
void get_unique_elements(int arr[], int size);
void merge_array(int arr[], int size);

int main()
{
    int size;
    printf("Enter size of array: ");
    scanf("%d", &size);

    int arr[size];
    set_array(arr, size);
    // printf("%d\n", sum(arr, size));
    // printf("%.2f\n", avg(arr, size));
    // odd_even_sum(arr, size);
    // printf("\n%d\n", greatest(arr, size));
    // printf("%d\n", smallest(arr, size));
    // printf("%d\n", second_greatest(arr, size));
    // printf("There are %d dublicates in array\n", get_dublicates_count(arr, size));
    // get_unique_elements(arr, size);
    // merge_array(arr, size);

    return 0;
}

void set_array(int arr[], int size)
{
    for (int i = 0; i < size; i++)
        scanf("%d", &arr[i]);
}

void get_array(int arr[], int size)
{
    for (int i = 0; i < size; i++)
        printf("%d ", arr[i]);
}

int sum(int arr[], int size)
{
    int sum = 0;
    for (int i = 0; i < size; i++)
        sum += arr[i];

    return sum;
}

float avg(int arr[], int size)
{
    int array_sum = sum(arr, size);
    return array_sum / (float)size;
}

void odd_even_sum(int arr[], int size)
{
    int odd_sum = 0, even_sum = 0;
    for (int i = 0; i < size; i++)
    {
        if (arr[i] % 2 == 0)
            even_sum += arr[i];
        else
            odd_sum += arr[i];
    }
    printf("SUM OF ODDNUMBERS = %d\nSUM OF EVENNUMERS = %d", odd_sum, even_sum);
}

int greatest(int arr[], int size)
{
    int MAX_VALUE = INT_MIN;
    for (int i = 0; i < size; i++)
    {
        if (arr[i] > MAX_VALUE)
            MAX_VALUE = arr[i];
    }

    return MAX_VALUE;
}

int smallest(int arr[], int size)
{
    int MIN_VALUE = INT_MAX;
    for (int i = 0; i < size; i++)
    {
        if (arr[i] < MIN_VALUE)
            MIN_VALUE = arr[i];
    }

    return MIN_VALUE;
}

void sort_array(int arr[], int size, int order)
{
    if (order == -1)
    {
        // descending order
        for (int i = 0; i < size; i++)
        {
            for (int j = i + 1; j < size; j++)
            {
                if (arr[i] < arr[j])
                {
                    int temp = arr[j];
                    arr[j] = arr[i];
                    arr[i] = temp;
                }
            }
        }
    }
    else
    {
        for (int i = 0; i < size; i++)
        {
            for (int j = i + 1; j < size; j++)
            {
                if (arr[i] > arr[j])
                {
                    int temp = arr[j];
                    arr[j] = arr[i];
                    arr[i] = temp;
                }
            }
        }
    }
}

int second_greatest(int arr[], int size)
{
    int MAX_VALUE = INT_MIN;
    for (int i = 0; i < size; i++)
    {
        if (arr[i] > MAX_VALUE)
            MAX_VALUE = arr[i];
    }
    int SECOND_MAX_VALUE = INT_MIN;
    for (int i = 0; i < size; i++)
    {
        if ((arr[i] > SECOND_MAX_VALUE) && (arr[i] != MAX_VALUE))
            SECOND_MAX_VALUE = arr[i];
    }

    return SECOND_MAX_VALUE;
}

int get_dublicates_count(int arr[], int size)
{
    sort_array(arr, size, 1);
    int count = 0, i = 0, j = 1;
    while (i < size - 2) // size-2 is 2nd last element of array
    {
        if (arr[i] == arr[j])
            count++;

        while (arr[i] == arr[j])
        {
            j++;
        }
        i = j;
        j = j + 1;
    }
    return count;
}

void get_unique_elements(int arr[], int size)
{
    sort_array(arr, size, 1);
    int i = 0, j = 1;
    while (i < size)
    {
        printf("%d ", arr[i]);

        while (arr[i] == arr[j])
        {
            j++;
        }
        i = j;
        j = j + 1;
    }
}

void merge_array(int arr[], int size)
{
    int arr2[size];
    printf("\nEnter array 2 elements: \n");
    set_array(arr2, size);

    int arr3[2 * size];

    for (int i = 0; i < size; i++)
        arr3[i] = arr[i];

    for (int j = 0; j < size; j++)
        arr3[j + size] = arr2[j];

    sort_array(arr3, 2 * size, -1);

    get_array(arr3, 2 * size);
}
