#include <bits/stdc++.h>

using namespace std;

/*
 *
 *  Exercise 16.47: Write your own version of the flip function and test it by calling functions that have lvalue and rvalue 
 *  reference parameters.
 * 
 */

struct DebugType {
    DebugType(int&& n) { std::cout << "rvalue overload, n=" << n << "\n"; }
    DebugType(int& n)  { std::cout << "lvalue overload, n=" << n << "\n"; }
};

template <typename F, typename T1, typename T2>
void flip(F f, T1&& t1, T2&& t2)
{
    cout << "flip..." << endl;
    f(std::forward<T2>(t2), std::forward<T1>(t1));
}

void f_f1(DebugType&& dt1, DebugType&& dt2)
{

}

template <typename T1, typename T2>
void f_f(T1&& dt1, T2&& dt2)
{

}

class ForwardTest {
public:
    template<class T1, class T2, class T3>
    ForwardTest(T1&& _t1, T2&& _t2, T3&& _t3) :
        a1{std::forward<T1>(_t1)},
        a2{std::forward<T2>(_t2)},
        a3{std::forward<T3>(_t3)}
    {
    }
 
private:
    DebugType a1, a2, a3;
};

template<class T, class U>
std::unique_ptr<T> make_unique1(U&& u)
{
    return std::unique_ptr<T>(new T(std::forward<U>(u)));
}
 
template<class T, class... U>
std::unique_ptr<T> make_unique2(U&&... u)
{
    return std::unique_ptr<T>(new T(std::forward<U>(u)...));
}
 
int main()
{   
    int i = 1;
    auto p1 = make_unique1<DebugType>(2); // rvalue
    auto p2 = make_unique1<DebugType>(i); // lvalue
    

    std::cout << endl << "ForwardTest...\n";
    auto t = make_unique2<ForwardTest>(2, i, 3);

    cout << endl;
    flip(f_f<DebugType, DebugType>, i, 10);
}