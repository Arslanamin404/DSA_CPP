#include <iostream>
#include "SLL.h"
using namespace std;

class Problems
{
public:
    /*
    ? Problem Statement: Add Two Numbers Represented by Linked Lists

    * Given two non-empty linked lists representing two non-negative integers,
    * where the digits are stored in reverse order, and each node contains a single digit.

    TODO: Add the two numbers and return the sum as a linked list (also in reverse order).

    ! Example:
    * Input:
    * List 1: 3 → 5        (represents 53)
    * List 2: 4 → 5 → 9 → 9 (represents 9954)

    ! Output:
    * Result List: 7 → 0 → 0 → 0 → 1   (represents 10007)
    */
    Node *add_two_numbers(Node *start_1, Node *start_2)
    {
        Node *temp_1 = start_1;
        Node *temp_2 = start_2;
        Node *dummy_node = new Node(0);
        Node *current = dummy_node;
        int carry = 0;

        while (temp_1 || temp_2 || carry)
        {
            int sum = carry;
            if (temp_1)
            {
                sum += temp_1->data;
                temp_1 = temp_1->next;
            }
            if (temp_2)
            {
                sum += temp_2->data;
                temp_2 = temp_2->next;
            }
            carry = sum / 10;
            current->next = new Node(sum % 10);
            current = current->next;
        }
        return dummy_node->next;
    }

    void display_list(Node *start)
    {
        while (start)
        {
            cout << start->data << " ";
            start = start->next;
        }
    }
};

int main()
{
    Problems p = Problems();
    int arr1[] = {3, 5};
    int arr2[] = {4, 5, 9, 9};

    SLL list_1 = SLL();
    SLL list_2 = SLL();

    list_1.array_to_list(arr1, (sizeof(arr1) / sizeof(int)));
    list_2.array_to_list(arr2, (sizeof(arr2) / sizeof(int)));

    Node *sum_list_start_node = p.add_two_numbers(list_1.start, list_2.start);
    p.display_list(sum_list_start_node);
    return 0;
}