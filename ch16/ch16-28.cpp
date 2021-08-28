#include <bits/stdc++.h>

using namespace std;

/*
 *
 *  Exercise 16.28: Write your own versions of shared_ptr and unique_ptr.
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
    SharedPtr() : count{new size_t{0}}
                , obj{new T()}
                , del{[](T* t) { delete t;}} 
    {
        cout << TAG + "default-ctor allocate " << obj << endl;
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

    UniquePtr(const UniquePtr& _o) = delete;
    UniquePtr& operator=(const UniquePtr& _o) = delete;

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
    T* obj;
    function<void(T*)> destroy_func;
    
};


int main(int argc, char **argv)
{
    cout << "Hello chapter " << endl;

    SharedPtr<int> a(new int);
    SharedPtr<int> m(new int, ClassDeleter());
    {
        SharedPtr<int> b(new int);
        SharedPtr<int> m1(new int, ClassDeleter());
        a = b;
        m1 = m;
    }
    auto c(a);
    a.reset(new int);

    UniquePtr<int> u_ptr;
    UniquePtr<int> u_ptr1(std::move(u_ptr));
    UniquePtr<int> u_ptr2 = std::move(u_ptr1);
    {
        *u_ptr2 = 10;
        cout << "[main] value " << *u_ptr2 << endl;
    }

    *u_ptr = 100;
    
    cout << "[main] End program" << endl;
    
    return 0;
}