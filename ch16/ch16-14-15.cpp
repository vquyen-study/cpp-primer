#include <bits/stdc++.h>

using namespace std;

/*
 *
 *  Exercise 16.14: Write a Screen class template that uses nontype parameters to define the height and width of the Screen.
 *   
 */

/***
 *  Exercise 16.15: Implement input and output operators for your Screen
 *      template. Which, if any, friends are necessary in class Screen to make the
 *      input and output operators work? Explain why each friend declaration, if any,
 *      was needed.
 */

template <size_t _height, size_t _width>
class Screen;

template <size_t _height, size_t _width>
ostream& operator<<(ostream& out, const Screen<_height, _width>& scr);

template <size_t _height, size_t _width>
istream& operator>>(istream& in, Screen<_height, _width>& scr);

template <size_t _height, size_t _width>
class Screen
{
    friend ostream& operator<< <_height, _width>(ostream& out, const Screen<_height, _width>& scr);
    friend istream& operator>> <_height, _width>(istream& in, Screen<_height, _width>& scr);
private:
    double x, y;
    
    size_t height = _height;
    size_t width = _width;
public:
    Screen() : x{0} , y{0} {}
};

template <size_t _height, size_t _width>
ostream& operator<<(ostream& out, const Screen<_height, _width>& scr)
{
    out << "rectangle screen windows " << endl
        << "A(" << scr.x << ", " << scr.y << "), "
        << "B(" << scr.x << ", " << scr.y + scr.height << "), "
        << "C(" << scr.x + scr.width<< ", " << scr.y + scr.height << "), "
        << "D(" << scr.x + scr.width<< ", " << scr.y << ")" << endl;
    
    return out;
}

template <size_t _height, size_t _width>
istream& operator>>(istream& in, Screen<_height, _width>& scr)
{
    in >> scr.x >> scr.y;
    return in;
}

int main(int argc, char **argv)
{
    cout << "Hello ch16-15" << endl;
    Screen<5, 9> scr;
    cin >> scr;

    cout << scr << endl;
    return 0;
}