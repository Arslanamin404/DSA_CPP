#include <iostream>
using namespace std;

class Problems
{
public:
    void set_array(int *arr, int size)
    {
        cout << "ENTER " << size << " ELEMENTS: ";
        for (int i = 0; i < size; i++)
            cin >> arr[i];
    }

    void get_array(int *arr, int size)
    {
        for (int i = 0; i < size; i++)
            cout << arr[i] << " ";
    }

    inline void print_line()
    {
        cout << "\n----------------------------------------------" << endl;
    }

    int get_largest(int *arr, int size)
    {
        int largest = arr[0];
        for (int i = 1; i < size; i++)
        {
            if (arr[i] > largest)
                largest = arr[i];
        }
        return largest;
    }

    int better_get_second_largest(int *arr, int size)
    {
        int largest = this->get_largest(arr, size);
        int second_largest = -1;
        for (int i = 1; i < size; i++)
        {
            if (arr[i] > second_largest && arr[i] != largest)
                second_largest = arr[i];
        }
        return second_largest;
    }

    int optimal_get_second_largest(int *arr, int size)
    {
        int largest = arr[0];
        int second_largest = INT_MIN;
        for (int i = 1; i < size; i++)
        {
            if (arr[i] > largest)
            {
                second_largest = largest;
                largest = arr[i];
            }
            else if (arr[i] < largest && arr[i] > second_largest)
                second_largest = arr[i];
        }
        return second_largest;
    }

    bool is_sorted(int *arr, int size)
    {
        int prev = 0, next = 1;
        for (int i = 0; i < size - 1; i++)
        {
            if (arr[prev] <= arr[next])
            {
                prev++;
                next++;
            }
            else
                return false;
        }
        return true;
    }

    int remove_dublicates_from_sorted(int *arr, int size)
    {
        int i = 0;
        for (int j = 1; j < size; j++)
        {
            if (arr[i] != arr[j])
            {
                i++;
                arr[i] = arr[j];
            }
        }
        return i + 1;
    }

    void left_rotate_by_one(int *arr, int size)
    {
        // [1,2,3,4,5]
        // [2,3,4,5,1]
        int start = arr[0];
        for (int i = 0; i < size - 1; i++)
            arr[i] = arr[i + 1];
        arr[size - 1] = start;
    }

    // sorting
    void selection_sort(int *arr, int size)
    {
        for (int i = 0; i < size - 1; i++)
        {
            for (int j = i + 1; j < size; j++)
            {
                if (arr[i] > arr[j])
                    swap(arr[i], arr[j]);
            }
        }
    }

    void bubble_sort(int *arr, int size)
    {
        for (int i = 0; i < size; i++)
        {
            for (int j = 0; j < size - i - 1; j++)
            {
                if (arr[j] > arr[j + 1])
                    swap(arr[j], arr[j + 1]);
            }
        }
    }

    void insertion_sort(int *arr, int size)
    {
        for (int i = 0; i < size; i++)
        {
            int j = i;
            while (j > 0 && arr[j - 1] > arr[j])
            {
                swap(arr[j - 1], arr[j]);
                j--;
            }
        }
    }

    void quick_sort(int *arr, int size) {}

    void merge_sort(int *arr, int size) {}
};

int main()
{
    Problems array_prblems;
    int size;
    cout << "Enter size of array: ";
    cin >> size;
    int arr[size];

    array_prblems.set_array(arr, size);
    array_prblems.print_line();
    array_prblems.get_array(arr, size);

    // array_prblems.print_line();

    // cout << "LARGEST ELEMENT: " << array_prblems.get_largest(arr, size) << endl;
    // cout << "SECOND ELEMENT (Better Approach): " << array_prblems.better_get_second_largest(arr, size) << endl;
    // cout << "SECOND ELEMENT (Optimal Approach): " << array_prblems.optimal_get_second_largest(arr, size) << endl;

    // array_prblems.print_line();
    // cout << "IS SORTED ARRAY: " << array_prblems.is_sorted(arr, size) << endl;

    // array_prblems.print_line();
    // int new_size = array_prblems.remove_dublicates_from_sorted(arr, size);
    // array_prblems.get_array(arr, new_size);

    // array_prblems.print_line();
    // array_prblems.left_rotate_by_one(arr, size);
    // array_prblems.get_array(arr, size);

    // array_prblems.print_line();
    // array_prblems.selection_sort(arr, size);
    // array_prblems.bubble_sort(arr, size);
    array_prblems.insertion_sort(arr, size);
    array_prblems.get_array(arr, size);
    return 0;
}