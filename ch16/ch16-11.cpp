#include <bits/stdc++.h>

using namespace std;

/*
 *
 *  Exercise 16.11: The following definition of List is incorrect. How would
 *  you fix it?
 * 
 */

template <typename elemType> 
class ListItem;

template <typename elemType> 
class List 
{
public:
    List<elemType>();
    List<elemType>(const List<elemType> &);
    List<elemType>& operator=(const List<elemType> &);
    ~List();
    void insert(ListItem<elemType> *ptr, elemType value);
                //      ^^^^^^^^^^
                //          this position needs to specify class template type.
private:
    ListItem<elemType> *front, *end;
        //  ^^^^^^^^^^
        //      this position needs to specify class template type.
};  


int main(int argc, char **argv)
{
    cout << "hello word ch16-11 " << endl;

    return 0;
}