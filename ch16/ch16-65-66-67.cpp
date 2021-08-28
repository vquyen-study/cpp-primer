#include <bits/stdc++.h>

using namespace std;

//
// Exercise 16.65:
// In § 16.3 (p. 698) we defined overloaded two versions of debug_rep one
// had a const char* and the other a char* parameter. Rewrite these functions
// as specializations.
//
// Exercise 16.66:
// What are the advantages and disadvantages of overloading
// these debug_rep functions as compared to defining specializations?
//
//  Overloading changes the function match.
//
// Exercise 16.67:
// Would defining these specializations affect function matching for debug_rep?
// If so, how? If not, why not?
//
//  page 873 : When we define a function template specialization, we are essentially taking over the
//  job of the compiler. That is, we are supplying the definition to use for a specific
//  instantiation of the original template. It is important to realize that a specialization is
//  an instantiation; it is not an overloaded instance of the function name.
//                     ^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^ Specialization is not overload instance of the function name.
//  Won't change.
//  Specializations instantiate a template; they do not overload it. As a result,
//  specializations do not affect function matching.
//
// More detailed Ref : http://www.gotw.ca/publications/mill17.htm



int main(int argc, char **argv)
{
    cout << "Hello chapter " << endl;
    
    return 0;
}