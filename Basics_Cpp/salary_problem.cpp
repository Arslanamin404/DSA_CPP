/*
? A company pays salaries using only certain denominations of noyes like (1000,500,200,100,50,20,10,2,1).
* Given an employee's salary.
todo: Find the minimum number of notes needed to pay the exact salary.
*/

#include <iostream>
#include <vector>
#include <map>

using namespace std;

map<int, int> calculate_denominations(int salary)
{
    vector<int> denominations = {1000, 500, 100, 50, 20, 10, 2, 1};
    map<int, int> note_count;
    for (int denom : denominations)
    {
        if (salary >= denom)
        {
            int count = salary / denom;
            salary -= count * denom;
            note_count[denom] = count;
        }
    }
    return note_count;
}

int main()
{
    int salary;
    cout << "Enter the salary amount: ";
    cin >> salary;

    map<int, int> notes = calculate_denominations(salary);
    int total_notes = 0;

    cout << "\n=================================" << endl;
    cout << "SALAY DENOMINATION BREAKDOWN" << endl;
    cout << "=================================" << endl;

    for (auto it = notes.rbegin(); it != notes.rend(); ++it)
    {
        cout << "₹" << it->first << " x " << it->second << " = ₹" << (it->first * it->second) << endl;
        total_notes += it->second;
    }

    cout << "\n=======================" << endl;
    cout << "TOTAL NOTES PAID: " << total_notes << endl;
    cout << "=======================\n"
         << endl;
    return 0;
}