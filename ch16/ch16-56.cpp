#include <bits/stdc++.h>

using namespace std;

/*
 *
 *  Exercise 16.56: Exercise 16.56: Write and test a variadic version of errorMsg.
 * 
 */

// Exercise 16.57:
// Compare your variadic version of errorMsg to the error_msg function in
// § 6.2.6 (p. 220). What are the advantages and disadvantages of each
// approach?
//  The error_msg takes initializer_list as the argument. So only the elements
//  stored in it must be the same or at least convertible. In contrast, the variadic
//  version provides better flexibility.
//

template <typename T>
string debug(const T& t)
{
    ostringstream oss;
    oss << "dbg " << t;
    return oss.str();
}

/**
 * 
 * Pack Expansions(variadic) we need to define the end of two parameter.
 * 
 **/
template <typename T>
ostream& print(ostream& _os, const T& t)
{
    _os << "<" << t << ">";
    return _os;
}

template <typename T, typename... Args>
ostream& print(ostream& _os, const T& _t, const Args&... _args)
{
    print(_os, _t);
    print(_os, _args...);   
    return _os;
}

template <typename... Args>
ostream& err_msg(ostream& _os, const Args&... args)
{
    print(_os, args...);
    cout << endl;

    print(_os, debug(args)...);
    return _os;
}



int main(int argc, char **argv)
{
    cout << "Hello chapter " << endl;
    string s1("str1-hello-msg");
    int i = 10;

    err_msg(cout, 2889, s1, i, 1119);

    return 0;
}