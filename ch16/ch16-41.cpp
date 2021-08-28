#include <bits/stdc++.h>

using namespace std;

/*
 *
 *  Exercise 16.41: Write a version of sum with a return type that is guaranteed to be large enough to hold the result of 
 *  the addition.
 * 
 */

template <typename T1, typename T2>
auto sum(T1 a, T2 b) -> decltype(a + b) {
    return a + b;
}


int main(int argc, char **argv)
{
    cout << "Hello chapter Exercise 16.41" << endl;
    auto s= sum(std::numeric_limits<long long unsigned>::max(), std::numeric_limits<long long unsigned>::max()) ;
    cout << to_string(s) << endl;
    return 0;
}