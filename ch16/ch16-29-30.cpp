#include <bits/stdc++.h>

using namespace std;

/*
 *
 *  Exercise 16.29: Revise your Blob class to use your version of
*     shared_ptr rather than the library version.
 * 
 */

/**
 * 
 * std::shared_ptr is a smart pointer that retains shared ownership of an object through a pointer. 
 * Several shared_ptr objects may own the same object. The object is destroyed and its memory deallocated 
 * when either of the following happens:
 *   - the last remaining shared_ptr owning the object is destroyed;
 *   - the last remaining shared_ptr owning the object is assigned another pointer via operator= or reset(). 
 * 
*/

class ClassDeleter
{
private:
    /* data */
public:
    ClassDeleter() {}
    ~ClassDeleter() {}

    template <typename T>
    void operator() (T* t)
    {
        cout << "[ClassDeleter] calling delete object" << endl;
        delete t;
    }
};

// template <typename T, typename DeleterFunc>
template <typename T>
class SharedPtr
{
    const string TAG = "[SharedPtr] ";
public:
    SharedPtr() : count{nullptr}
                , obj{nullptr}
                , del{} 
    {
        cout << TAG + "default-ctor allocate empty object" << endl;
    }

    SharedPtr(T* _obj, function<void(T*)> _del = [](T* t){ delete t;})    
                    : count{new size_t{0}}
                    , obj{_obj}
                    , del{_del} 
    {
        *count = *count + 1;
        cout << TAG + "input pointer ctor allocate " << obj << endl;
        
    }

    SharedPtr(const SharedPtr& _obj)    
                    : count{_obj.count}
                    , obj{_obj.obj}
                    , del{_obj.del} 
    {
        *count = *count + 1;
        cout << TAG + "copy-ctor allocate " << obj << endl;
    }

    SharedPtr(SharedPtr&& rhs)
    {
        count = std::move(rhs.count);
        obj = std::move(rhs.obj);
        del = std::move(rhs.del);
        cout << TAG + "move-ctor allocate " << obj  << endl;
    }

    SharedPtr& operator=(SharedPtr rhs)
    {
        destroy();

        count = std::move(rhs.count);
        obj = std::move(rhs.obj);
        del = std::move(rhs.del);

        *count = *count + 1;
        
        rhs.count = nullptr;
        rhs.obj = nullptr;

        cout << TAG + "operator= allocate " << obj  << endl;
        return *this;
    }

    T* operator->()
    {
        if (obj == nullptr)
            throw std::runtime_error(TAG + "Warning!!! your code is going to access nullptr");
        return &(this->operator*());
    }

    T& operator*()
    {
        if (obj == nullptr)
            throw std::runtime_error(TAG + "Access nullptr");
        return *obj;
    }

    void reset(T* ptr)
    {
        destroy();
        
        this->obj = ptr;
        this->count = new size_t{1};
    }

    T* get() const noexcept
    {
        return obj;
    }

    void destroy()
    {
        if(count != nullptr)
        {
            *count = *count - 1;
            if (*count == 0)
            {
                if (obj)
                    del(obj);
                delete count;

                cout << TAG << obj << " has been deleted" << endl;
                obj = nullptr;
                count = nullptr;
            }
        }
    }
    ~SharedPtr()
    {
        destroy();
    }
private:
    size_t *count;
    
    T* obj;
    function<void(T*)> del;
};

template <typename T>
class UniquePtr
{
    const string TAG = "[UniquePtr] ";
public:
    UniquePtr() : obj{new T()}, destroy_func{[](T* _t) { delete _t; }} 
    {

    }

    UniquePtr(T* _t, function<void(T*)> _destroy) : obj{_t}, destroy_func{_destroy} 
    {

    }

    UniquePtr(UniquePtr&& _o) 
    {
        obj = std::move(_o.obj);
        destroy_func = std::move(_o.destroy_func);

        _o.obj = nullptr;
        _o.destroy_func = function<void(T*)>();
    }

    UniquePtr& operator=(UniquePtr&& _o) 
    {
        obj = std::move(_o.obj);
        destroy_func = std::move(_o.destroy_func);

        _o.obj = nullptr;
        _o.destroy_func = function<void(T*)>();
    }

    T& operator*()
    {
        if (obj == nullptr)
            throw std::runtime_error(TAG + "Access to null pointer");
            
        return *obj;
    }

    ~UniquePtr() 
    {
        if (obj && destroy_func)
        {
            destroy_func(obj);
            cout << TAG + "has been deleted " << obj << endl;
        }
            
    }
private:
    UniquePtr(const UniquePtr& _o) = delete;
    UniquePtr& operator=(const UniquePtr& _o) = delete;
    
    T* obj;
    function<void(T*)> destroy_func;
    
};


template <typename T>
class BlobPtr;

template <typename T>
class Blob
{
    template <typename K>
    friend class BlobPtr;
public:
    typedef typename vector<T>::size_type size_type;
    Blob() : vec{} {}
    
    Blob(initializer_list<T> itor) : vec{new vector<int>{itor}} 
    {

    }

    template<typename Itor>
    Blob(Itor first, Itor end) : vec{new vector<int>{first, end}}
    {
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
    SharedPtr<vector<T>> vec; 
    void check(size_type i, const string& msg)
    {
        if (i > vec->size())
            throw std::out_of_range(msg);
    }
};

struct TestClass
{
    int x;
    int y;
};

template <typename T, typename ...Args>
T* sharedptr_factory(Args ...args)
{
    return new T{forward<Args>(args)...};
}

int main(int argc, char **argv)
{
    cout << "Hello, ch16-24" << endl;
    Blob<int> bi = {1, 2, 3, 5, 8};
    Blob<int> bi2{bi.begin(), bi.end()};

    for (auto itor = bi2.begin(); itor != bi2.end(); ++itor)
        cout << *itor << ", ";
    cout << endl;

    SharedPtr<vector<int>> s_valv{new vector<int>{1, 2, 3}};
    SharedPtr<vector<int>> s_test = sharedptr_factory<vector<int>>(1, 2, 3, 4, 8, 9);

    for (auto itor = s_test->begin(); itor != s_test->end(); ++itor)
        cout << *itor << ", ";
    cout << endl;
    return 0;
}