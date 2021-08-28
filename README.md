## 1. Build on windows.
* By default the cmake generate nmake... It is neccessary to reconfig to makefile for cygwin as bellow.

```shell
cmake -S . -B build -G "Unix Makefiles"
```

Notes:
### 1. Declaring a Function That Returns a Pointer to an Array
> 
> **Solution 1:**
>> - int arr[10]; // arr is an array of ten ints
>> - int *p1[10]; // p1 is an array of ten pointers
>> - int (*p2)[10] = &arr; // p2 points to an array of
> ```
>   Type (*function(parameter_list))[dimension] 
> ```
> ``` 
>   example : int (*func(int i))[10];
> ```
> - *func(int)* says that we can call func with an int argument.
> - *(*func(int))* says we can dereference the result of that call.
> - *(*func(int))[10]* says that dereferencing the result of a call to func yields an array of size ten.
> - *int (*func(int))[10]* says the element type in that array is int.

> 
> **Solution 2:**
> - Using a Trailing Return Type.
> ```
> *auto func(int i) -> int(*)[10];*
> ```

### 1. Different between bool compare(const T& a, const T& b) and bool compare(T& a, T& b)
> The different betwen above template function a, b are able to have temporary object, rvalue... while c,d only allow lvalue. 
> ```
> #include <iostream>
> #include <string>
> 
> using namespace std;
> 
> struct MyClass
> {
>   MyClass(const char *s) { cout << " ctor const char * - " << string(s) << endl;}  
>   MyClass(const MyClass&) { cout << " copy-ctor" << endl;}  
> };
> 
> template <typename T>
> bool compare(const T& a, const T& b)
> {
>     return true;
> }
> 
> int main()
> {
>     compare<MyClass>("abc", "slklks");
>     return 0;
> }
> ```

> Define following function
> ```C++
> template <typename T> string debug_rep(const T &t) 
> {
>   //....
> }
> 
> template <typename T> string debug_rep(T *p) 
> {
>   //....
> }
> ```
> which function will be called with below flow.
> ```C++
> const string *sp = &s;
> cout << debug_rep(sp) << endl;
> ```
> Here both templates are viable and both provide an exact match:
> - **debug_rep(const string* &)**, the instantiation of the first version of the template with T bound to **const string***
> - **debug_rep(const string*)**, the instantiation of the second version of the template with T bound to **const string**
> - this call resolves to **debug_rep(T*)**, which is the more specialized template.
> - ==> The problem is that the template debug_rep(const T&) can be called on essentially any type