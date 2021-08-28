#include <bits/stdc++.h>

using namespace std;

/*
 *
 *  Exercise 16.50: Determine what sizeof...(Args) and sizeof...(rest) return for each call to foo in this section.
 *  
 *  Answer: Like sizeof (§ 4.9, p. 156), sizeof... returns a constant expression (§ 2.4.4, p. 65) and does not evaluate 
 *  its argument
 * 
 */

template <typename T, typename ... Args>
void foo(const T & t, const Args & ... rest)
{
    cout << "Number of varidict template ... " << sizeof...(rest) << endl;
}



int main(int argc, char **argv)
{
    cout << "Hello chapter Exercise 16.50" << endl;
    int i = 0; double d = 3.14; string s = "how";

    foo(i, s, 42, d);  // input in Args: string, int(rvalue), double  sizeof...(Args): 3  sizeof...(rest): 3
    foo(s, 42, "hi");  // input in Args: int(rvalue), const char[3]   sizeof...(Args): 2  sizeof...(rest): 2
    foo(d, s);         // input in Args: string                       sizeof...(Args): 1  sizeof...(rest): 1
    foo("hi");         // input in Args: None                         sizeof...(Args): 0  sizeof...(rest): 0
    foo(i, s, s, d);   // input in Args: string, string, double       sizeof...(Args): 3  sizeof...(rest): 3

    return 0;
}