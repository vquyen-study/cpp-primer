#include <bits/stdc++.h>

using namespace std;

/*
 *
 *  Exercise 16.17: What, if any, are the differences between a type parameter
 *    that is declared as a typename and one that is declared as a class? When
 *    must typename be used?
 * 
 *   *) There no difference between typename and class in template parameter.
 *   *) We must use the "typename" keywork to inform compiler that we are specifying a type of template parameter.
 * 
 */

// Exercise 16.18:
// Explain each of the following function template declarations and identify
// whether any are illegal. Correct each error that you find.
//

template <typename T, typename U, typename V> void f1(T, U, V);
//                   ^^^^^^^^ added to fix the error

template <typename T> T f2(T&);
//                        ^^

template <typename T> inline T foo(T, unsigned int*);
//                   ^^^^^^ inline must be after template

template <typename T> T f4(T, T);
//                   ^ -- return type must be provided

typedef char Ctype;
//          ^^^^^
//the template declatation below hides this typedef
template <typename Ctype> Ctype f5(Ctype a);


int main(int argc, char **argv)
{
    cout << "hello word ch16-07 " << endl;


    return 0;
}