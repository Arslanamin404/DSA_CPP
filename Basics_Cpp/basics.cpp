#include <iostream>
#include <string>

using namespace std;

struct Book
{
private:
    int bookID;
    string title;
    float price;

public:
    void setBookID(int id);
    void setBookTitle(string title);
    void setBookPrice(float price);
    int getBookID();
    string getBookTitle();
    float getBookPrice();
    void inputBook(int bookID, string title, float price);
    void displayBook();
};

int main()
{
    // int end;
    // cout << "Enter end range (2^n): ";
    // cin >> end;
    // for (int i = 0; i <= end; i++)
    //     // cout << "2^" << i << " = " << pow(2, i) << endl;
    //     cout << pow(2, i) << ",";

    Book b1, b2, b3;

    b1.inputBook(121, "Let Us C", 400.75);
    b2.inputBook(122, "Let Us C++", 480.25);
    b3.inputBook(123, "Data Structures and Algorithms", 521.12);

    b1.displayBook();
    b2.displayBook();
    b3.displayBook();

    return 0;
}

void Book::setBookID(int id)
{
    this->bookID = id;
}

void Book::setBookTitle(string title)
{
    this->title = title;
}

void Book::setBookPrice(float price)
{
    this->price = price;
}

int Book::getBookID()
{
    return this->bookID;
}

string Book::getBookTitle()
{
    return this->title;
}

float Book::getBookPrice()
{
    return this->price;
}

void Book::inputBook(int bookID, string title, float price)
{
    this->bookID = bookID;
    this->title = title;
    this->price = price;
}

void Book::displayBook()
{
    cout << "ID: " << this->bookID << "\nTITLE: " << this->title << "\nPRICE: " << this->price << endl;
    cout << "==========================================" << endl;
}
