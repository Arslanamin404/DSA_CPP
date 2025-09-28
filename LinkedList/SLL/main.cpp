#include <iostream>
#include "SLL.h"

using namespace std;

void menu()
{
    cout << "\n=======================================================" << endl;
    cout << "\t\tSINGLY LINKED LIST" << endl;
    cout << "=======================================================\n"
         << endl;
    cout << "[1] INSERT AT START" << endl;
    cout << "[2] INSERT AT END" << endl;
    cout << "[3] INSERT AFTER" << endl;
    cout << "[4] DELETE AT START" << endl;
    cout << "[5] DELETE AT END" << endl;
    cout << "[6] DELETE NODE" << endl;
    cout << "[7] DISPLAY LIST" << endl;
    cout << "[8] EXIT\n"
         << endl;
}
int main()
{
    SLL mySll = SLL();
    int choice;
    while (true)
    {
        system("clear");
        menu();
        cout << "PLEASE ENTER YOUR CHOICE: ";
        cin >> choice;
        switch (choice)
        {
        case 1:
        {
            cout << "\nYOU SELECTED INSERT_AT_START OPTION\n"
                 << endl;
            int value;
            cout << "ENTER VALUE TO INSERT: ";
            cin >> value;
            mySll.insert_at_start(value);
            cout << "\nINSERT_AT_START✅! Press any key to continue...";
            cin.ignore();
            cin.get();
            break;
        }
        case 2:
        {
            cout << "\nYOU SELECTED INSERT_AT_END OPTION\n"
                 << endl;
            int value;
            cout << "ENTER VALUE TO INSERT: ";
            cin >> value;
            mySll.insert_at_end(value);
            cout << "\nINSERT_AT_LAST✅! Press any key to continue...";
            cin.ignore();
            cin.get();
            break;
        }
        case 3:
        {
            cout << "\nYOU SELECTED INSERT_AFTER OPTION\n"
                 << endl;
            int source;
            int value;
            cout << "ENTER THE VALUE AFTER WHCIH YOU WANT TO INSERT: ";
            cin >> source;
            cout << "ENTER VALUE TO INSERT: ";
            cin >> value;
            mySll.insert_after(source, value);
            cout << "\nINSERT_AFTER✅! Press any key to continue...";
            cin.ignore();
            cin.get();
            break;
        }
        case 4:
        {
            cout << "\nYOU SELECTED DELETE_AT_START OPTION\n"
                 << endl;
            mySll.delete_at_start();
            cout << "\nDELETE_AT_START✅! Press any key to continue...";
            cin.ignore();
            cin.get();
            break;
        }
        case 5:
        {
            cout << "\nYOU SELECTED DELETE_AT_END OPTION\n"
                 << endl;
            mySll.delete_at_end();
            cout << "\nDELETE_AT_END✅! Press any key to continue...";
            cin.ignore();
            cin.get();
            break;
        }
        case 6:
        {
            cout << "\nYOU SELECTED DELETE_NODE OPTION\n"
                 << endl;
            int value;
            cout << "ENTER VALUE TO DELETE: ";
            cin >> value;
            mySll.delete_node(value);
            cout << "\nDELETE_NODE✅! Press any key to continue...";
            cin.ignore();
            cin.get();
            break;
        }
        case 7:
        {
            cout << "\nYOU SELECTED DISPLAY_LIST OPTION\n"
                 << endl;
            mySll.display();
            cout << "\nDISPLAY_LIST✅! Press any key to continue...";
            cin.ignore();
            cin.get();
            break;
        }
        case 8:
        {
            cout << "\nTHANK YOU FOR USING OUR LINKED LIST PROGRAM🎉\n"
                 << endl;
            return 0;
        }
        default:
        {
            cout << "INVALID CHOICE❌! PLEASE TRY AGAIN." << endl;
            cout << "\nPress any key to continue...";
            cin.ignore();
            cin.get();
        }
        }
    }

    // mySll.insert_at_start(10);
    // mySll.insert_at_start(20);
    // mySll.insert_at_start(30);
    // mySll.insert_at_end(40);
    // mySll.insert_at_end(50);
    // mySll.insert_at_end(60);
    // mySll.insert_after(10, 15);
    // mySll.insert_after(2, 12);

    // mySll.display();
    // cout << "\n===========================" << endl;
    // mySll.delete_at_start();
    // mySll.delete_at_end();
    // mySll.delete_node(40);
    // mySll.delete_node(100);
    // mySll.display();
    return 0;
}