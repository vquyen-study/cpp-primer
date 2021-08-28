#include <bits/stdc++.h>

using namespace std;

/*
 *
 *  Exercise 16.7: Write a constexpr template that returns the size of a given array.
 * 
 */

template <typename T, unsigned size>
constexpr uint64_t myGetArraySize(const T (&arr)[size])
{
    return size;
}

int main(int argc, char **argv)
{
    cout << "hello word ch16-05 " << endl;
    const char str_c[] = {"12345"};
    string s[] = {"The first one", "The second one", "The third one"};
    
    cout << "size of  str_c " << myGetArraySize(str_c) << endl;
    cout << "size of  s     " << myGetArraySize(s) << endl;
    

    return 0;
}