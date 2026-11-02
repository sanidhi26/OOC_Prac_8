
#include <iostream>
using namespace std;

class Distance
{
private:
    int feet, inch;

public:
    // Constructor
    Distance(int f = 0, int i = 0)
    {
        feet = f;
        inch = i;
    }

    // Unary operator overloading
    void operator-()
    {
        feet--;
        inch--;

        cout << "After decrement: "
             << feet << "'" << inch << endl;
    }

    // Binary operator overloading
    Distance operator+(Distance d)
    {
        Distance temp;
        temp.feet = feet + d.feet;
        temp.inch = inch + d.inch;
        return temp;
    }

    // Relational operator overloading
    bool operator==(Distance d)
    {
        return feet == d.feet && inch == d.inch;
    }

    bool operator!=(Distance d)
    {
        return !(*this == d);
    }

    bool operator<(Distance d)
    {
        return (feet * 12 + inch) <
               (d.feet * 12 + d.inch);
    }

    bool operator>(Distance d)
    {
        return d < *this;
    }

    bool operator<=(Distance d)
    {
        return !(*this > d);
    }

    bool operator>=(Distance d)
    {
        return !(*this < d);
    }

    // Insertion operator
    friend ostream& operator<<(ostream& out, Distance d)
    {
        out << d.feet << "'" << d.inch;
        return out;
    }

    // Extraction operator
    friend istream& operator>>(istream& in, Distance& d)
    {
        cout << "Enter feet and inches: ";
        in >> d.feet >> d.inch;
        return in;
    }
};

int main()
{
    Distance d1, d2, d3;

    cout << "Enter first distance:" << endl;
    cin >> d1;

    cout << "Enter second distance:" << endl;
    cin >> d2;

    // Unary operator
    -d1;

    // Binary operator
    d3 = d1 + d2;

    cout << "\nTotal Distance: " << d3 << endl;

    // Relational operators
    cout << "\nRelational Comparison:" << endl;

    cout << "d1 == d2: " << (d1 == d2) << endl;
    cout << "d1 != d2: " << (d1 != d2) << endl;
    cout << "d1 < d2: " << (d1 < d2) << endl;
    cout << "d1 > d2: " << (d1 > d2) << endl;
    cout << "d1 <= d2: " << (d1 <= d2) << endl;
    cout << "d1 >= d2: " << (d1 >= d2) << endl;

    return 0;
}
