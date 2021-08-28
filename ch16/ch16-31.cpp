#include <bits/stdc++.h>

using namespace std;

/*
 *
 *  Exercise 16.31 Explain how the compiler might inline the call to the deleter if we used DebugDelete with unique_ptr.
 *      The compiler will set the default deleter type as DebugDelete, which will be executed is known at compile time.
 * 
 */


int main(int argc, char **argv)
{
    cout << "Hello chapter " << endl;
    
    return 0;
}