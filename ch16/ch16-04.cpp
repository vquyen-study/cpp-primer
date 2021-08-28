#include <bits/stdc++.h>

using namespace std;

/**
 *
 *  Exercise 16.4: Write a template that acts like the library find algorithm.
 *  The function will need two template type parameters, one to represent the
 *  function’s iterator parameters and the other for the type of the value. Use
 *  your function to find a given value in a vector<int> and in a
 *  list<string>.
 *
 */

template <typename Itor, typename V>
Itor myFind(Itor first, Itor last, V value)
{
    for (auto it = first; it != last; it++)
        if (*it == value)
            return it;
    
    return last;
}

int main(int argc, char **argv)
{
    vector<int> ivec{1, 9, 8, 6, 10, 22};
    list<string> regions{"United State", "United Kingdom", "Korea", "Russia"};

    auto find_itor1 = myFind(ivec.begin(), ivec.end(), 9);
    auto find_itor2 = myFind(ivec.begin(), ivec.end(), 60);
    
    if (find_itor1 != ivec.end())
        cout << *find_itor1 << endl;
    
    if (find_itor2 != ivec.end())
        cout << *find_itor2 << endl;

    auto hanoi_3 = myFind(regions.begin(), regions.end(), "United Kingdom");
    auto hanoi_60 = myFind(regions.begin(), regions.end(), "Germany");
    
    if (hanoi_3 != regions.end())
        cout << *hanoi_3 << endl;
    
    if (hanoi_60 != regions.end())
        cout << *hanoi_60 << endl;
    return 0;
}