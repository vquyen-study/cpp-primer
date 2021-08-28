#include <bits/stdc++.h>

using namespace std;

/*
 *
 *  Exercise 16.19: Write a function that takes a reference to a container and
 *    prints the elements in that container. Use the container’s size_type and
 *    size members to control the loop that prints the elements
 * 
 */

void print_vector(vector<int>& vec)
{
    typename vector<int>::const_iterator first_itor = vec.begin();
    typename vector<int>::const_iterator end_itor = vec.end();
//    ^^^^^^    we must specify typename to inform compiler that we are using the type of template.

    while (first_itor != end_itor)
        cout << *first_itor++ << ", ";

    cout << endl;
}
int main(int argc, char **argv)
{
    vector<int> v = {1, 2, 3, 4, 6, 8, 9};

    print_vector(v);

    return 0;
}