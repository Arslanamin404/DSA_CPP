#include <iostream>
using namespace std;

class Complex
{
    int real, img;

public:
    Complex() : real(0), img(0) {}
    Complex(int real, int imaginary) : real(real), img(imaginary) {}

    // Copy constructor
    Complex(const Complex &obj) : real(obj.real), img(obj.img) {}

    friend istream &operator>>(istream &in, Complex &obj);
    // friend ostream &operator<<(istream &out, Complex &obj);

    void setData(int, int);
    void display();
    Complex operator+(const Complex &obj);
    Complex operator-(const Complex &obj);
    Complex operator-(); // unary - operator (-a)
    bool operator==(const Complex &obj);
};

class Time
{
    int hh, mm, ss;
    void normalize();

public:
    Time() {}
    Time(int hour, int min, int sec) : hh(hour), mm(min), ss(sec)
    {
        this->normalize();
    }

    bool operator>(const Time &obj);
    void set_time(int hour, int min, int sec);
    void display();

    // pre/post increament the Time by 1 sec;
    Time operator++(int); // post increment
    Time operator++();    // pre increment
};

class Fraction
{
    long numerator, denominator;

public:
    Fraction() {};
    Fraction(long numi, long denom) : numerator(numi), denominator(denom) {}
    Fraction operator+(const Fraction &obj);
};

int main()
{
    // Complex c1,
    //     c3, c4, c5;
    // c1.setData(2, 4);

    // Complex c2(5, 8);

    // c1.display();
    // c2.display();

    // c3 = c1 + c2;
    // c3.display();

    // c4 = c1 - c2;
    // c4.display();

    // c5 = c4;
    // c5.display();

    // Complex c6;
    // c6 = -c1;
    // c6.display();

    // (c1 == c2) ? cout << "EQUAL" : cout << "NOT EQUAL" << endl;

    // cout << "\n===============================" << endl;

    // Complex C[5];
    // C[0].setData(20, 30);
    // C[1].setData(22, 39);
    // C[2].setData(72, 91);
    // C[3].setData(43, 22);
    // C[4].setData(28, 37);

    // for (int i = 0; i < 5; i++)
    //     C[i].display();

    // cout << "===============================" << endl;

    // Time t1(7, 59, 59);
    // Time t2(12, 45, 9);
    // Time t3;

    // (t1 > t2) ? cout << "T1" : cout << "T2" << endl;

    // t1.display();
    // t2.display();

    // t3 = t1++;
    // t3.display();
    // t1.display();

    return 0;
}

void Complex::setData(int real, int imaginary)
{
    this->real = real;
    this->img = imaginary;
}

void Complex::display()
{
    cout << this->real << "+" << this->img << "i" << endl;
}

Complex Complex::operator+(const Complex &obj)
{
    Complex temp;
    temp.real = this->real + obj.real;
    temp.img = this->img + obj.img;
    return temp;
}

Complex Complex::operator-(const Complex &obj)
{
    Complex temp;
    temp.real = this->real - obj.real;
    temp.img = this->img - obj.img;
    return temp;
}

Complex Complex::operator-()
{
    Complex temp;
    temp.real = -real;
    temp.img = -img;
    return temp;
}

bool Complex::operator==(const Complex &obj)
{
    if (this->real == obj.real && this->img == obj.img)
        return true;
    else
        return false;
}

bool Time::operator>(const Time &obj)
{
    if (this->hh > obj.hh)
        return true;
    else if (this->hh < obj.hh)
        return false;
    else if (this->mm > obj.mm)
        return true;
    else if (this->mm < obj.mm)
        return false;
    else if (this->ss > obj.ss)
        return true;
    else
        return false;
}
void Time::set_time(int hour, int min, int sec)
{
    this->hh = hour;
    this->mm = min;
    this->ss = sec;
}
void Time::display()
{
    cout << this->hh << ":" << this->mm << ":" << this->ss << endl;
}

void Time::normalize()
{
    this->mm += this->ss / 60;
    this->ss %= 60;

    this->hh += this->mm / 60;
    this->mm %= 60;
}

Time Time::operator++(int)
{
    Time temp = *this;
    this->ss++;
    this->normalize();
    return temp;
}

Time Time::operator++()
{
    this->ss++;
    this->normalize();
    return *(this);
}

Fraction Fraction::operator+(const Fraction &obj)
{

    Fraction temp;
    // using cross multiplication method, this can be also solved using LCM method
    if (this->denominator == obj.denominator)
    {
        temp.numerator = this->numerator + obj.numerator;
        temp.denominator = this->denominator;
    }
    else
    {
        temp.numerator = (this->numerator * obj.denominator) + (this->denominator * obj.numerator);
        temp.denominator = this->denominator * obj.denominator;
    }
    return temp;
}

istream &operator>>(istream &in, Complex &obj)
{
    in >> obj.real >> obj.img;
    return in;
}