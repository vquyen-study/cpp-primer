#include <bits/stdc++.h>

using namespace std;

/*
 *
 *  Exercise 17.1: Define a tuple that holds three int values and initialize the
 *  members to 10, 20, and 30.
 * 
 * 
 *  Exercise 17.2: Define a tuple that holds a string, a vector<string>,
 *  and a pair<string, int>.
 * 
 * 
 *  Exercise 17.3: Rewrite the TextQuery programs from § 12.3 (p. 484) to
 *  use a tuple instead of the QueryResult class. Explain which design you
 * 
 */

int main(int argc, char **argv)
{
    ostringstream oss;
    cout << "Hello ex-ch17-0x" << endl;

    // Exercise 17.1: Define a tuple that holds three int values and initialize the members to 10, 20, and 30.
    tuple<int, int , int> tple{10, 20, 30};
    oss << "tuple value " << get<0>(tple) << ", " << get<1>(tple) << ", " << get<2>(tple) << endl;

    cout << oss.str();

    // Exercise 17.2: Define a tuple that holds a string, a vector<string>,
    // and a pair<string, int>.
    tuple<string, vector<string>, pair<string, int>> tpl2{"first string", {"vec string 1", "vec string 2"}, {"pair string", 10}};
    cout << get<0>(tpl2) << endl;
    cout << get<1>(tpl2)[0] << endl;
    cout << get<1>(tpl2)[1] << endl;
    cout << get<2>(tpl2).first << endl;
    cout << get<2>(tpl2).second << endl;
    return 0;
}