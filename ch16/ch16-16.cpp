#include <bits/stdc++.h>

using namespace std;

/*
 *
 *  Exercise 16.16: Rewrite the StrVec class (§ 13.5, p. 526) as a template named MyVector.
 *   
 */
template<typename T>
class MyVector
{
public:
    MyVector():element(nullptr), first_free(nullptr), cap(nullptr)
    {

    }

    MyVector(std::initializer_list<T> l)
    {
        T* data = alloc.allocate(l.size());

        T* p = data;
        for (auto& el : l)
            alloc.construct(p++, std::move(el));
        
        element = data;
        first_free = p;
        cap = first_free;

    }

    // copy-constructor.
    MyVector(const MyVector& v)
    {
        std::pair<T*, T*> pair = alloc_n_copy(v.begin(), v.end());
       
        element = pair.first;
        first_free = pair.second;
        cap = first_free;
    }

    // assignment-constructor.
    MyVector& operator =(const MyVector& rhs)
    {
        std::pair<T*, T*> pair = alloc_n_copy(rhs.begin(), rhs.end());
        
        // we need to remove old data.
        free();

        element = pair.first;
        first_free = pair.second;
        cap = first_free;
    }

    ~MyVector()
    {
        if (element)
        {
            for (T* p = element; p != first_free; p++)
                alloc.destroy(p);
            
            alloc.deallocate(element, capacity());
        }
    }

    // memmbers
    void push_back(const T& t)
    {
        chk_n_alloc();
        alloc.construct(first_free++, t);
    }

    std::size_t size() const    { return first_free - element; }
    std::size_t capacity()const { return cap - element; }

    T* begin() const { return element;      }
    T* end()   const { return first_free;   }

    void reserve(std::size_t n)
    {
        // There is enough capacity as requirment.
        if (capacity() > n) return;

        // IF NOT, do alloc new space and move old data to new one.
        wy_alloc_n_move(n);
    }

    void resize(std::size_t n)
    {
        resize(n, T());
    }

    // resize to size of vector to specific size. vector is truncated when vector size is greater than n, otherwise vector will be add T().
    void resize(std::size_t n, const T& t)
    {
        if (n < size())
        {
            for (T* p = element + n; p != first_free; p++)
                alloc.destroy(p);
            
            first_free = element + n;
        }
        else if (n > size())
        {
            while (size() != n)
                push_back(t);
        }
    }

private:
    // data members
    T* element;
    T* first_free;
    T* cap;

    std::allocator<T> alloc;

    // utillities
    void reallocate()
    {
        auto size_cap = size() ? (2 * size()) : 1;

        wy_alloc_n_move(size_cap);
    }

    void chk_n_alloc()  
    { 
        if (size() == capacity()) 
            reallocate();
    }
    
    void free()
    {
        if (element)
        {
            for (auto p = first_free; first_free != element;)
                alloc.destroy(--p);

            alloc.deallocate(element, capacity());
        }
    }

    void wy_alloc_n_move(std::size_t n)
    {
        // T* data = alloc(n);
        T* data = alloc.allocate(n);
        T* new_first_free = data;
        T* old_data = element;
        
        while (old_data != first_free)
            alloc.construct(new_first_free++, std::move(*old_data++));
        
        free();
        element = data;
        first_free = new_first_free;
        cap = element + n;
    }

    std::pair<T*, T*> alloc_n_copy(T* b, T* e)
    {
        T* data = alloc.allocate(e-b);
        return {data, std::uninitialized_copy(b, e, data)};
    }
};



int main(int argc, char **argv)
{
    cout << "Hello ch16-16" << endl;

    MyVector<int> iv = {1, 2, 3, 4};
    MyVector<string> svec = {"hanoi", "Frankust", "HCM"};

    for (auto& i : iv)
        cout << i << ", ";
    
    cout << endl;

    for (auto& i : svec)
        cout << i << ", ";
    
    cout << endl;
    
    return 0;
}