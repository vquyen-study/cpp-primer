#include <bits/stdc++.h>

using namespace std;

/*
 *
 *  Exercise 16.21: Write your own version of DebugDelete.
 * 
 */

class DeleterDebugger
{
private:
    ostream& os;
public:
    DeleterDebugger(ostream& _os = std::cerr) : os(_os) {}
    ~DeleterDebugger() {}

    template<typename T>
    void operator() (T* p)
    {
        os << "[DeleterDebugger] You are deleting the object " << reinterpret_cast<void *>(p) << endl;
        delete p;
        os << "[DeleterDebugger] The memory " << reinterpret_cast<void *>(p) << " has been deleted " << endl;
    }
};

int main(int argc, char **argv)
{
    cout << "Hello chapter " << endl;

    int *pi = new int;
    DeleterDebugger dobj;
    dobj(pi);
    
    return 0;
}