#include <bits/stdc++.h>

using namespace std;

/*
 *
 *  Exercise 16.42: Determine the type of T and of val in each of the following calls:
 * 
 *  template <typename T> void g(T&& val);
 *   int i = 0; const int ci = i;
 *   (a) g(i);
 *   (b) g(ci);
 *   (c) g(i * ci);
 * 
 *   (a) T: int& val: int& && -> int &
 *   (b) T: const int& val: const int& && -> const int &
 *   (c) T: int val: int &&
 * 
 *  When we pass an lvalue int to a function parameter that is an rvalue reference to a template type parameter T&&, the 
 *  compiler deduces the template type parameter as the argument’s lvalue reference type int &. 
 *     
 *  X& &, X& &&, and X&& & all collapse to type X&.
 */

/*
 *
 *  Exercise 16.43: Using the function defined in the previous exercise, what would the template parameter of g be if we 
 *  called g(i = ci)?
 * 
 *  The type is  int&
 */


/*
 *
 *  Exercise 16.44: Using the same three calls as in the first exercise, determine the types for T if g’s function parameter 
 *  is declared as T (not T&&). What if g’s function parameter is const T&?
 * 
 *  template <typename T> void g(T val);
 *   int i = 0; const int ci = i;
 * 
 *   (a) g(i);          // T is int, val is int.
 *   (b) g(ci);         // T is int, val is int. ===========>>>> this is special case when c++ drop cv-qualifier top-level.
 *   (c) g(i * ci);     // T is int, val is int.
 * 
 *  template <typename T> void g(const T& val);
 *   int i = 0; const int ci = i;
 * 
 *   (a) g(i);          // T is int, val is int.
 *   (b) g(ci);         // T is int, val is int.
 *   (c) g(i * ci);     // T is int, val is int.
 * 
 **/

/*
 *
 *  Exercise 16.45: Given the following template, explain what happens if we call g on a literal 
 *  value such as 42. What if we call g on a variable of type int? 
 * 
 *  template <typename T> void g(T&& val) { vector<T> v; }
 *  
 *  Answer:
 *  - If we call g on a literal value such as 42, T should be int, and we get a tempoary variable v, which type is vector<int>. 
 *  - If we call g on a variable of type int, then val should be a lvalue, T should be int&(because int& && ==> int&), then we 
 *  would declared a v as vector<int&>. But the component type of vector must be assignable, the references are not assignable, 
 *  thus, vector<int&> is not allowed, the compiler would complain about it.
 * 
 **/


int main(int argc, char **argv)
{
    cout << "Hello chapter Exercise 16.42 - 16.43" << endl;

    return 0;
}