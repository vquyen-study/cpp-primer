#include <bits/stdc++.h>

using namespace std;

/*
 *
 *  Exercise 16.27: For each labeled statement explain what, if any,
 *   instantiations happen. If a template is instantiated, explain why; if not,
 *   explain why not.
 * 
 */

template <typename T> 
class Stack 
{

};

void f1(Stack<char>);                       // (a)
class Exercise {            
    Stack<double> &rsd;                     // (b)
    Stack<int> si;                          // (c)
};

void f1(Stack<char>)
{
    
}


int example_function() 
{
    Stack<char> *sc;                        // (d)
    f1(*sc);                                // (e)
    int iObj = sizeof(Stack< string >);     // (f)

    return 0;
}

/**
 * 
 *   (a) It should be instantiated here, and a class of Stack <char> type is defined
 *
 *   (b) It should be instantiated here, a Stack <double> class is defined, but the program does not use this class
 *
 *   (c) It should be instantiated here, a class of type Stack <int> is defined, but the program does not use this class
 *
 *   (d) There should be no more here, because the type has been defined before.
 *
 *   (e) This should also be absent. At the time of declaration, the relevant types have been defined. This is not a template function and should not be instantiated.
 *
 *   (f) Define a class of type Stack <string>
 * 
 * 
*/

int main(int argc, char **argv)
{
    cout << "Hello chapter " << endl;
    
    return 0;
}