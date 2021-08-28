#include <bits/stdc++.h>

using namespace std;

/*
 *  Exercise 16.32: What happens during template argument deduction?
 *    During template argument deduction, the compiler uses types of the arguments in the call to find the template 
 *    arguments that generate a version of the function that best matches the given call.
 * 
 */

/*
 *  Exercise 16.33: Name two type conversions allowed on function arguments involved in template argument deduction.
 *   const conversions
 *   Array- or function-to-pointer conversions
 */

/**
 *  Exercise 16.34: Given only the following code, explain whether each of these calls is legal. If so, what is 
 *   the type of T? If not, why not?
 * 
 *      template <class T> int compare(const T&, const T&);
 *       (a) compare("hi", "world");
 *       (b) compare("bye", "dad");
 * 
 * 
 *   (a): illegal, as two types are different, the first type being const char[3] ,second const char[6]
 *   (b): legal, the type is const char(&)[4].
 **/

/**
 *  Exercise 16.35: Which, if any, of the following calls are errors? If the call is legal, what is the type 
 *   of T? If the call is not legal, what is the problem?
 *  
 *       template <typename T> T calc(T, int);
 *       template <typename T> T fcn(T, T);
 *       double d; float f; char c;
 *       (a) calc(c, 'c');
 *       (b) calc(d, f);
 *       (c) fcn(c, 'c');
 *       (d) fcn(d, f);
 * 
 * 
 *   (a) legal, type is char.
 *   (b) legal, type is double.
 *   (c) legal, type is char.
 *   (d) illegal, d is double, but f is float, they are totally different type.
 **/

/**
 *  Exercise 16.36: What happens in the following calls:
 *   of T? If the call is not legal, what is the problem?
 *  
 *       template <typename T> f1(T, T);
 *       template <typename T1, typename T2) f2(T1, T2);
 *       int i = 0, j = 42, *p1 = &i, *p2 = &j;
 *       const int *cp1 = &i, *cp2 = &j;
 *       (a) f1(p1, p2);
 *       (b) f2(p1, p2);
 *       (c) f1(cp1, cp2);
 *       (d) f2(cp1, cp2);
 *       (e) f1(p1, cp1);
 *       (f) f2(p1, cp1);
 * 
 *  At first, there are some error in function declarations.
 *
 *   f1, f2 should have return type, maybe void?
 *   In f2, typename T2) should be typename T2>.
 * 
 *   (a) T is int*
 *   (b) T1 and T2 are both int*
 *   (c) T is const int*
 *   (d) T1 and T2 are both const int*
 *   (e) error, p1 is int*, cp1 is const int*, they are different type
 *   (f) T1 is int*, T2 is const int*
 **/

/**
 *  Exercise 16.37: The library max function has two function parameters and returns the larger of its arguments. This function 
 *   has one template type parameter. Could you call max passing it an int and a double? If so, how? If not, why not?
 *  
 *      Yes. Specify the parameter explicitly:
 * 
 *      int a = 6; double b = 6.1231;
 *      std::cout << std::max<long double>(a, b) << std::endl;
 * 
 *      Then : Normal conversions also apply for arguments whose template type parameter is explicitly specified.
 **/

/**
 *  Exercise 16.38: When we call make_shared (12.1.1, p. 451), we have to provide an explicit template argument. Explain 
 *  why that argument is needed and how it is used.
 *  
 *  Answer: Because when we call make_shared, it is allowed for no argument. Then, we have nothing to deduce the type of 
 *  the return type.
 * 
 **/

/**
 *  Exercise 16.39: Use an explicit template argument to make it sensible to pass two string literals to the original 
 *  version of compare from 16.1.1 (p.652).
 *  
 *  Answer: 
 *          std::cout << compare<std::string>("czwp", "czyz") << std::endl;
 *                               ^^^^^^^^^^^
 * 
 **/


template <typename T>
bool compare(const T& a, const T& b)
{
    return a == b;
}

int main(int argc, char **argv)
{
    cout << "Hello chapter 16.30 " << endl;
    int i = 10, k = 20;
    long j = 12;

    // cout << std::boolalpha << compare(i, j) << endl;     /* Error : Because deducted type is different. */
    cout << std::boolalpha << compare(i, k) << endl;
    return 0;
}