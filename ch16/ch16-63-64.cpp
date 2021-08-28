#include <bits/stdc++.h>

using namespace std;

/*
 *
 *  Exercise 16.63: Define a function template to count the number of
 *  occurrences of a given value in a vector. Test your program by passing it a
 *  vector of doubles, a vector of ints, and a vector of strings.
 * 
 */

template <typename T>
auto count_occurrence(const vector<T>& vec, const T &obj) -> decltype(auto)
{
    return count(vec.begin(), vec.end(), obj);;
}

template <>
auto count_occurrence(const vector<const char *>& vec, const char* const& obj) -> decltype(auto)  // Specialization func template T = (const char *)                                                       
{
    return count_if(vec.begin(), vec.end(), [&obj](const char *_elem){
        return strcmp(_elem, obj) == 0;
    });
}

int main(int argc, char **argv)
{
    vector<long> ivec{1, 2, 4, 2, 4, 9, 8, 12, 9};
    vector<double> dvec{1.2, 2.2, 4.2, 2.2, 4.2, 9.2, 8.2, 12.2, 9.2};

    vector<const char *> c_cvec{"Luyi", "Messi", "Ronado", "Mppabe", "Messi"};

    if (argc != 2)
    {
        cout << argv[0] << " <double | long> " << endl;
        return 0;
    }

    auto v1 = strtol(argv[1], NULL, 10);
    auto v2 = strtod(argv[1], NULL);

    cout << "number of occurrence(" << v1 << ") " << count_occurrence(ivec, v1) << endl;
    cout << "number of occurrence(" << v2 << ") " << count_occurrence(dvec, v2) << endl;
    
    // cout << "number of occurrence(Messi) " << count_occurrence(c_cvec, "Messi") << endl;
    //                                                                     ^^^^^^   It would be failed because specialization template are not 
    //                                                                              overload function. Hence there is not maching function.
    cout << "number of occurrence(Messi) " << count_occurrence(c_cvec, (const char *) "Messi") << endl;
    return 0;
}