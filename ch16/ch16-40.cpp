#include <bits/stdc++.h>

using namespace std;

/*
 *
 *  Exercise 16.40: Is the following function legal? If not, why not? If it is legal, what, if any, are the restrictions on the 
 *  argument type(s) that can be passed, and what is the return type?
 * 
 * template <typename It>
 *   auto fcn3(It beg, It end) -> decltype(*beg + 0) {
 *       // process the range
 *       return *beg; // return a copy of an element from the range
 *   }
 * 
 * 
 *  Answer:
 *  legal. But only type that support this + 0 operation can be passed, and the return type depends on the what type the 
 *  operator + return.
 * 
 */


int main(int argc, char **argv)
{
    cout << "Hello chapter " << endl;
    
    return 0;
}