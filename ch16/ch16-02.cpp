#include <bits/stdc++.h>

using namespace std;

/*
 *
 *  Exercise 16.2: Write and test your own versions of the compare functions
 *
 */

template <typename T>
int myCompare(const T& lhs, const T& rhs)
{
    if (lhs == rhs) return 0;

    return lhs < rhs ? -1 : 1;
}

int main(int argc, char **argv)
{

    cout << "expectation  0 : " << myCompare(1, 1) << endl;
    cout << "expectation -1 : " << myCompare(1, 2) << endl;
    cout << "expectation  1 : " << myCompare(2, 1) << endl;
    return 0;
}