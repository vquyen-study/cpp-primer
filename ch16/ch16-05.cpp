#include <bits/stdc++.h>

using namespace std;

/*
 *
 *  Exercise 16.5: Write a template version of the print function from § 6.2.4
 *  (p. 217) that takes a reference to an array and can handle arrays of any size
 *  and any element type.
 * 
 */

/**
 *  The key of input object is "Nontype Template Parameters" must be 
 *    When the template is instantiated, nontype parameters are replaced with a value
 *    supplied by the user or deduced by the compiler. These values must be constant
 *    expressions (§ 2.4.4, p. 65), which allows the compiler to instantiate the templates
 *    during compile time.
 */
template <typename T, unsigned size>
void myPrint(const T (&arr)[size])
{
    for (auto const& e : arr)
        cout << e << ", ";

    cout << endl;
}

int main(int argc, char **argv)
{
    cout << "hello word ch16-05 " << endl;
    string s[] = {"hello US", "Hello UK", "Hello Korea", "Hello Germany"};
    const char *arr[] = {"hello US", "Hello UK", "Hello Korea", "Hello Germany", "Hello Singapore"};

    myPrint(s);
    myPrint(arr);

    return 0;
}