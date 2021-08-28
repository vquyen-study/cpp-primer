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

template <typename T>
class BlobPtr;

template <typename T>
bool operator==(const BlobPtr<T>& lhs, const BlobPtr<T>& rhs);

template <typename T>
bool operator<(const BlobPtr<T>& lhs, const BlobPtr<T>& rhs);

template <typename T>
class BlobPtr
{
    friend bool operator== <T>(const BlobPtr<T>& lhs, const BlobPtr<T>& rhs);
    friend bool operator< <T>(const BlobPtr<T>& lhs, const BlobPtr<T>& rhs);
public:
    // prefix
    BlobPtr& operator++()
    {
        check(curr, "post increasement operator out of range.\n");
        curr++;        
        return *this;
    }

    BlobPtr& operator--()
    {
        check(curr, "post increasement operator out of range.\n");
        curr--;
        return *this;
    }

    // deference operator
    T& operator*() const
    {
        check(curr, "deference operator out of range\n");

        auto sptr = wptr.lock();
        if (sptr && !sptr->empty())
            return (*sptr)[curr];
        else 
            throw std::runtime_error("deference operator empty pointer\n");
    }

    // postfix
    BlobPtr& operator++(int)
    {
        check(curr, "post increasement operator out of range.\n");
        BlobPtr& ret = *this;
        curr++;      
        return ret;
    }

    BlobPtr& operator--(int)
    {
        check(curr, "post decreasement operator out of range.\n");
        BlobPtr& ret = *this;
        curr--;
        return ret;
    }

    BlobPtr(Blob<T>& data, size_t size = 0) : wptr{data.vec}, curr{size}
    {
        cout << "ctor curr " << curr << endl;
    }

private:
    void check(size_t i,const string& s) const
    {
        auto sptr = wptr.lock();
        
        if (i > sptr->size())
            throw std::out_of_range(s);
    }
    
    weak_ptr<vector<T>> wptr;
    size_t curr;
};

template <typename T>
bool operator==(const BlobPtr<T>& lhs, const BlobPtr<T>& rhs)
{
    if (lhs.wptr.lock() != rhs.wptr.lock())
        std::runtime_error("Point to difference Blob\n");

    return lhs.curr == rhs.curr;
}

template <typename T>
bool operator!=(const BlobPtr<T>& lhs, const BlobPtr<T>& rhs)
{
    return !(lhs == rhs);
}

template <typename T>
bool operator<(const BlobPtr<T>& lhs, const BlobPtr<T>& rhs)
{
    if (lhs.wptr.lock() != rhs.wptr.lock())
        std::runtime_error("Point to difference Blob\n");
    return *lhs < *rhs;
}

int main(int argc, char **argv)
{
   Blob<int> bi = {1, 2, 3, 5, 8};
   BlobPtr<int> bptr_start{bi, 0}, bptr_end{bi, bi.size()};
    
    while (bptr_start != bptr_end)
    {
        cout << *bptr_start << ", ";
        bptr_start++;
    }

    return 0;
}