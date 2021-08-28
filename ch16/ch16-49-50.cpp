#include <bits/stdc++.h>

using namespace std;

/*
 *
 *  Exercise 16.49: Explain what happens in each of the following calls:
 * 
 */

template <typename T> void f(T)                    //1
{
    cout << "f(T t) \t\t (1)" << endl;
}

template <typename T> void f(const T*)             //2
{
    cout << "f(const T* t) \t (2)" << endl;
}

template <typename T> void g(T)                    //3
{
    cout << "g(T t) \t\t (3)" << endl;
}

template <typename T> void g(T*)                   //4
{
    cout << "g(T* t) \t (4)" << endl;
}

int main(int argc, char **argv)
{
    cout << "Hello chapter " << endl;
    
    int i = 42, *p = &i;
    const int ci = 0, *p2 = &ci;

    g(42);      // 3
    g(p);       // 4 (int) ==> 3 (int *)
    g(ci);      // 3 (const int)
    g(p2);      // 4 (const int) ==> 3 (const int *)
    
    f(42);      // 1 (int)
    f(p);       // 1 (int *) ==> 2 (int)
    f(ci);      // 1 (const int)
    f(p2);      // 2 (int) ==> 1 (const int *)

    return 0;
}