#include <bits/stdc++.h>

using namespace std;

/*
 *
 *  Exercise 16.58: Write the emplace_back function for your StrVec class
 *  and for the Vec class that you wrote for the exercises in § 16.1.2 (p. 668)
 * 
 */

/*
 *
 *  Exercise 16.59: Assuming s is a string, explain svec.emplace_back(s).
 * 
 *  Answer:
 *      The emplace_back will forward the variadic parameter to construct new new string element. 
 *      Forward will save cost to re-use during construct from rvalue object. From lvalue is copy-constructor will be called.
 * 
 */



class StrVec
{
public:
    StrVec() = default;
    ~StrVec() = default;

    //...
    template <class... Args>
    void StrVec::emplace_back(Args&&... args)
    {
        alloc.construct(free_element++, std::forward(args)...);
    }
    
    //...

private:
    std::allocator<string> alloc;

    string *free_element;
    string *first_element;
    string *capacity;

};



int main(int argc, char **argv)
{
    cout << "Hello chapter " << endl;
    
    return 0;
}