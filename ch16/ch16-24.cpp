#include <bits/stdc++.h>

using namespace std;

/*
 *
 *  Exercise 16.12: Write your own version of the Blob and BlobPtr templates. including the various
 *  const members that were not shown in the text.
 * 
 */

template <typename T>
class BlobPtr;

template <typename T>
class Blob
{
    template <typename K>
    friend class BlobPtr;
public:
    typedef typename vector<T>::size_type size_type;
    Blob() : vec{make_shared<T>()} {}
    Blob(initializer_list<T> itor) : vec{make_shared<vector<T>>(itor)} 
    {

    }

    template<typename Itor>
    Blob(Itor first, Itor end) : vec{make_shared<vector<T>>()}
    {
        vec->insert(vec->end(), first, end);
    }

    auto begin()
    {
        return vec->begin();
    }

    auto end()
    {
        return vec->end();
    }

    ~Blob() {}

    void push_back(T& v) 
    {
        vec->push_back(v);
    }

    void push_back(T&& v) 
    {
        vec->push_back(std::move(v));
    }
    void pop_back() 
    {
        check(0, "Pop back from empty Blob\n");
        vec->pop_back();
    }

    T& back() 
    { 
        check(0, "Get back() from empty Blob\n");
        return vec->back(); 
    }
    T& operator[] (size_type i)
    {
        check(0, "\"access out of range\" the i is greater than size of Blob\n");
        return (*vec)[i];
    }

    

    size_t size() const { return vec->size(); }
    bool empty() const { return vec->empty(); }

private:
    shared_ptr<vector<T>> vec; /* data */
    void check(size_type i, const string& msg)
    {
        if (i > vec->size())
            throw std::out_of_range(msg);
    }
};

int main(int argc, char **argv)
{
    cout << "Hello, ch16-24" << endl;
    Blob<int> bi = {1, 2, 3, 5, 8};
    Blob<int> bi2{bi.begin(), bi.end()};

    for (auto itor = bi2.begin(); itor != bi2.end(); ++itor)
        cout << *itor << ", ";
    cout << endl;

    return 0;
}