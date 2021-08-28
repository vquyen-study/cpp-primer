#include <bits/stdc++.h>

using namespace std;

/*
 *
 *  Exercise 16.53: Write your own version of the print functions and test
 *  them by printing one, two, and five arguments, each of which should have
 *  different types.
 * 
 */

/*
 *
 *  Exercise 16.54: What happens if we call print on a type that doesn’t have
 *  an << operator?
 * 
 *  Answer: below error will be occured if Employee does not define operator<<.
 *      error: no match for ‘operator<<’ (operand types are ‘std::ostream’ {aka ‘std::basic_ostream<char>’} and ‘const Employee’)
 * 
 */

/*
 *
 *  Exercise 16.55: Explain how the variadic version of debug would execute if
 *  we declared the nonvariadic version of debug after the definition of the
 *  variadic version.
 * 
 *  Answer: 
 *      The first two calls can match only the variadic version of debug because the
 *      nonvariadic version isn’t viable. These calls pass four and three arguments,
 *      respectively, and the nonvariadic debug takes only two arguments.
 * 
 *      For the last call in the recursion, print(cout, 42), both versions of print are
 *      viable. This call passes exactly two arguments, and the type of the first argument is
 *      ostream&. Thus, the nonvariadic version of print is viable.
 * 
 */

struct Student
{
    string name;
    int id;

    friend ostream& operator<<(ostream& os, const Student& obj)
    {
        os << "[Student] name " << obj.name << " ID " << obj.id;
        return os;
    }
};

struct Employee
{
    string name;
    int id;

    // It need to be defined to use debug function. otherwise will promt below error.
    // error: no match for ‘operator<<’ (operand types are ‘std::ostream’ {aka ‘std::basic_ostream<char>’} and ‘const Employee’)
    friend ostream& operator<<(ostream& os, const Employee& obj)
    {
        os << "[Employee] name " << obj.name << " ID " << obj.id;
        return os;
    }
};

template <typename T>
ostream& debug(ostream& os,const T& t)
{
    os << t << ", ";
    return os;
}

template <typename T, typename ... Args>
ostream& debug(ostream& os, const T& t, const Args& ...args)
{
    debug(os, t);
    debug(os, args...);
    return os;
}



int main(int argc, char **argv)
{
    cout << "Hello chapter Exercise 16.50" << endl;
    int i = 0; double d = 3.14; string s = "how";
    Student s1 {"Mpabe", 12349};
    Employee e1 {"Messi", 12349};

    debug(cout, s, 42, d, s1);              
    cout << endl;

    debug(cout, s, 42, d, e1);              

    return 0;
}