#include <bits/stdc++.h>

using namespace std;

/*
 *
 *  Exercise 16.6: How do you think the library begin and end functions that
 *  take an array argument work? Define your own versions of these functions.
 * 
 */

template <typename T, unsigned size>
const T* myBegin(const T (&arr)[size])
{
    return &arr[0];
}

template <typename T, unsigned size>
const T* myEnd(const T (&arr)[size])
{
    return  &arr[size];
}


int main(int argc, char **argv)
{
    cout << "hello word ch16-05 " << endl;
    
    string s[] = {"hello US"s, "Hello UK"s, "Hello Korea"s, "Hello Germany"s};
    
    for (auto it = myBegin(s); it != myEnd(s); it++)
        cout << *it << endl;

    return 0;
}