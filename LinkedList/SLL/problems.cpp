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

    /*
    ? Given a Linked List, modify the list such that:
    TODO: odd index nodes appear before the even index nodes in the modified list.
    * Dont use extra space.
    * |----------------------------------------------|
    * | INPUT: 1 -> 3 -> 4 -> 12 -> 10 -> 9 -> NULL  |
    * |----------------------------------------------|
    * | OUTPUT: 1 -> 4 -> 10 -> 3 -> 12 -> 9 -> NULL |
    * |----------------------------------------------|
    */
    Node *odd_and_even_list(Node *start)
    {
        if (start == nullptr || start->next == nullptr)
            return start;

        Node *odd_idx = start;
        Node *even_idx = start->next;
        Node *even_idx_head = start->next;

        while (even_idx && even_idx->next)
        {
            odd_idx->next = odd_idx->next->next;
            even_idx->next = even_idx->next->next;

            odd_idx = odd_idx->next;
            even_idx = even_idx->next;
        }

        odd_idx->next = even_idx_head;

        return start;
    }

    /*
    ? Given a Linked List containing only 0s, 1s, and 2s only,
    TODO: rearrange the nodes so that all 0s come first, followed by 1s, then 2s.
    * Do not use any extra space.
    * |-----------------------------------------------|
    * | INPUT:  2 -> 1 -> 0 -> 1 -> 2 -> 0 -> NULL    |
    * |-----------------------------------------------|
    * | OUTPUT: 0 -> 0 -> 1 -> 1 -> 2 -> 2 -> NULL    |
    * |-----------------------------------------------|
*/
    Node *sort(Node *start)
    {
        // dummy nodes
        Node *zero_head = new Node(-1);
        Node *one_head = new Node(-1);
        Node *two_head = new Node(-1);

        Node *zero = zero_head;
        Node *one = one_head;
        Node *two = two_head;

        if (start == nullptr || start->next == nullptr)
            return start;

        Node *temp = start;

        while (temp)
        {
            if (temp->data == 0)
            {
                zero->next = temp;
                zero = zero->next;
            }
            else if (temp->data == 1)
            {
                one->next = temp;
                one = one->next;
            }
            else
            {
                two->next = temp;
                two = two->next;
            }
            temp = temp->next;
        }
        zero->next = (one_head->next) ? one_head->next : two_head->next;
        one->next = two_head->next;
        two->next = nullptr;

        Node *new_start = zero_head->next;

        delete zero_head;
        delete one_head;
        delete two_head;

        return new_start;
    }

    Node *reverse(Node *start)
    {
        Node *prev = nullptr;
        Node *current = start;
        Node *next = nullptr;
        while (current)
        {
            next = current->next;
            current->next = prev;
            prev = current;
            current = next;
        }
        start = prev;
        return start;
    }
};

int main()
{
    Problems p;

    cout << "\n===== Add Two Numbers Represented by Linked Lists =====" << endl;
    int arr1[] = {3, 5};       // represents 53 (in reverse order: 5->3)
    int arr2[] = {4, 5, 9, 9}; // represents 9954 (in reverse order)

    SLL list1, list2;
    list1.array_to_list(arr1, sizeof(arr1) / sizeof(int));
    list2.array_to_list(arr2, sizeof(arr2) / sizeof(int));

    Node *sum_list = p.add_two_numbers(list1.start, list2.start);
    cout << "Sum List: ";
    p.display_list(sum_list);

    cout << "\n\n===== Rearrange Odd and Even Index Nodes =====" << endl;
    int arr3[] = {1, 3, 4, 12, 10, 9};
    SLL list3;
    list3.array_to_list(arr3, sizeof(arr3) / sizeof(int));

    cout << "Original List: ";
    p.display_list(list3.start);

    Node *odd_even_head = p.odd_and_even_list(list3.start);
    cout << "\nModified List: ";
    p.display_list(odd_even_head);

    cout << "\n\n===== Sort 0s, 1s, and 2s in Linked List =====" << endl;
    int arr4[] = {2, 1, 0, 1, 2, 0};
    SLL list4;
    list4.array_to_list(arr4, sizeof(arr4) / sizeof(int));

    cout << "Original List: ";
    p.display_list(list4.start);

    Node *sorted_head = p.sort(list4.start);
    cout << "\nSorted List:   ";
    p.display_list(sorted_head);

    cout << "\n\n===== Reverse Linked List =====" << endl;
    int arr5[] = {1, 2, 3, 4, 5, 6, 7, 8, 9};
    SLL list5;
    list5.array_to_list(arr5, sizeof(arr5) / sizeof(int));

    cout << "Original List: ";
    p.display_list(list5.start);

    Node *reverse_list_head = p.reverse(list5.start);
    cout << "\nReversed List: ";
    p.display_list(reverse_list_head);

    return 0;
}