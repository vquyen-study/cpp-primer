#include <bits/stdc++.h>

using namespace std;

/*
 *
 *  Exercise 16.46: Explain this loop from StrVec::reallocate in 13.5 (p.530):
 * 
 * 
 *      for (size_t i = 0; i != size(); ++i)
 *           alloc.construct(dest++, std::move(*elem++));
 * 
 * Since C++11, std::allocator::construct's second parameter is Args&&... args. *elem++ is a certain lvalue, and 
 * would be casted to a rvalue reference by std::move, then the construct would call the move constructor of std::string 
 * rather than copy constructor.
 * 
 */


int main(int argc, char **argv)
{
    cout << "Hello chapter " << endl;
    
    return 0;
}