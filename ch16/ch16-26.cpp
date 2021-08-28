#include <bits/stdc++.h>

using namespace std;

/*
 *
 *  Exercise 16.26: Assuming NoDefault is a class that does not have a
 *   default constructor, can we explicitly instantiate vector<NoDefault>? If
 *   not, why not?
 *      ==> Not 
 *      ==> refer : http://stackoverflow.com/questions/21525169/while-explicitly-instantiating-vectorsometype-what-is-the-sometype-default-co
 * 
 */

class NoDefault
{
private:
    /* data */
public:
    NoDefault() = default;
    ~NoDefault() {}
};


template class vector<NoDefault>;

int main(int argc, char **argv)
{
    cout << "Hello chapter " << endl;
    
    return 0;
}